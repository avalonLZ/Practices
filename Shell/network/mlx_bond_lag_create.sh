#!/bin/bash
#本脚本用于mlx网卡在ovs-kernel场景下的聚合卸载
# PCI ROOT
PCI_ROOT="/sys/bus/pci/devices"
NET_ROOT="/sys/class/net"

# mlx5_core driver bind/unbind
MLX5_BIND="/sys/bus/pci/drivers/mlx5_core/bind"
MLX5_UNBIND="/sys/bus/pci/drivers/mlx5_core/unbind"

pf_name_list="ens5f0np0 ens5f1np1"
# Active-backup as default mode
# ab is 1，xor is 2，lacp is 4
bond_mode=1

[ -n "$2" ] && bond_mode=$2

#1. 开启sriov
if [ -n "$1" -a "$1" = "setup" ]; then
    for pf in $pf_name_list; do
        echo 4 > "$NET_ROOT/$pf/device/sriov_numvfs" 2>/dev/null;
        echo "setup sriov for PF iface:$pf"
    done
    # Wait for 2s interval before later VF-LAG setup.
    sleep 2
fi

# 获取vf列表
vf_list=$(ls -l $NET_ROOT/*/device/ | grep virtfn | awk '{print $NF}' | cut -d'/' -f2)
if [ ! -n "$vf_list" ]; then
    echo "VF setup failure for vDPA hw-offload"
    exit 0
fi

#2. 解绑vf驱动以及取消linux聚合
if [ -n "$1" -a "$1" = "clean" ]; then
    # 2.1 unbind driver for all VFs
    for vf in $vf_list; do
        [ -e "$PCI_ROOT/$vf/driver" ] || continue
        # unbind vf driver
        echo $vf > $MLX5_UNBIND 2>/dev/null
        echo "unbind driver for VF:$vf"
    done
    # 2.2 remove slaves from bond
    echo "remove slaves:$pf_name_list from bond"
    for pf in $pf_name_list; do
        echo -$pf > "$NET_ROOT/bond1/bonding/slaves" 2>/dev/null
        # 2.3 turn off sriov for PF
        echo 0 > "$NET_ROOT/$pf/device/sriov_numvfs" 2>/dev/null;
        echo "turn off sriov for slave:$pf"
    done
    teamd -t team0 -k
    exit 0
fi

#1.2 设置vf口mac地址
if [ -n "$1" -a "$1" = "setup" ]; then
    i=0
    for pf_name in $pf_name_list; do
        pf_vf_list=$(ls "$NET_ROOT/$pf_name/device/" | grep virtfn | egrep -o "[0-9]+")
        [ -n "$pf_vf_list" ] || continue
        echo "setting VFs' mac for PF iface:$pf_name"
        # set VFs' mac for PF
        for idx in $pf_vf_list; do
            mac_eb=$(printf "%02x" $idx)
           echo "set mac: e4:1d:2d:fd:8${i}:$mac_eb"
            ip link set $pf_name vf $idx mac "e4:1d:2d:fd:8${i}:$mac_eb"
        done
        i=$((i+1))
    done
fi

#1.3 解绑所有vf的mlx驱动
for vf in $vf_list; do
    # If driver unbinded, ignore and next
    [ -e "$PCI_ROOT/$vf/driver" ] || continue
    # unbind vf driver
    echo $vf > "$MLX5_UNBIND" 2>/dev/null
    echo "unbind driver for VF:$vf"
done

#3. 开启mlx网卡pf的eswitch模式
if [ -n "$1" -a "$1" = "setup" ]; then
    for pf in $pf_name_list; do
        mode=$(cat "$NET_ROOT/$pf/compat/devlink/mode" 2>/dev/null)
        [ -n "$mode" -a "$mode" = "switchdev" ] && continue
        # enable 'switchdev' mode for PF
        #echo switchdev > "$NET_ROOT/$pf/compat/devlink/mode" 2>/dev/null
        pf_pci=$(basename $(readlink /sys/class/net/$pf/device))
        devlink dev eswitch set pci/$pf_pci mode switchdev
        if [ $? -eq 0 ]; then
            echo "enable 'switchdev' mode for PF:$pf success"
        else
            echo "enable 'switchdev' mode for PF:$pf failure"
        fi
    done
fi
#3.2 wait for 3s interval before VF-LAG setup
sleep 3

:<<COMMENT
# 4.创建内核聚合口
lsmod | grep -q bonding 2>/dev/null
if [ $? -ne 0 ]; then
    modprobe bonding 2>/dev/null
fi
# 4.2 down pf_name_list slaves of bond
for pf in $pf_name_list; do
    ip link set dev $pf down 2>/dev/null
done
# 4.3 create bond iface with active-backup mode
ls -l $NET_ROOT | grep -q bond1
if [ $? -ne 0 ]; then
    ip link add name bond1 type bond 2>/dev/null
fi
# set bond mode for bond
echo "set bonding mode:$bond_mode for bond"
ip link set dev bond1 down
echo $bond_mode > "$NET_ROOT/bond1/bonding/mode" 2>/dev/null
# 任何模式都必须配此项，否则物理链路断开，bond的active口也不会改变
echo 100 > /sys/class/net/bond1/bonding/miimon
# xor和lacp模式下有效
echo 1 > "$NET_ROOT/bond1/bonding/xmit_hash_policy" 2>/dev/null
sleep 0.2
# 4.4 add pf_name_list as slaves of bond1
ip link set dev bond1 down
sleep 0.2
for pf in $pf_name_list; do
    ip link set dev $pf down
    #ip link set dev $pf master bond1
    sleep 0.2
    echo +$pf > "$NET_ROOT/bond1/bonding/slaves"
done
# 4.5 set link up for slaves and bond
for pf in $pf_name_list; do
    ip link set dev $pf up 2>/dev/null
done
ip link set dev bond1 up 2>/dev/null
COMMENT

# 配置team聚合
# team和上面的bond任意选一个实现系统层面的聚合
#teamd -d -o -g -c '{"device":"team0","runner":{"name":"activebackup"},"link_watch":{"name":"ethtool"},"ports":{"ens5f0np0":{"prio":0,"sticky":true},"ens5f1np1":{"prio":1,"sticky":true}}}'
teamd -d -o -g -c '{"device":"team0","runner":{"name":"loadbalance","tx_hash":["l4"]},"link_watch":{"name":"ethtool"},"ports":{"ens5f0np0":{},"ens5f1np1":{}}}'
#teamd -d -o -g -c '{"device":"team0","runner":{"name":"lacp","active":true,"fast_rate":false,"tx_hash":["l4"]},"link_watch":{"name":"ethtool"},"ports":{"ens5f0np0":{},"ens5f1np1":{}}}'
ip link set dev team0 up 2>/dev/null

# 这里等成员网口被添加到聚合口，并且up起来后，mlx卡上的lag会自动创建出来
sleep 2

# 5. 重新绑定vf上的mlx驱动
if [ -n "$1" -a "$1" = "setup" ]; then
    for vf in $vf_list; do
        # If driver binded, ignore and next
        [ -e "$PCI_ROOT/$vf/driver" ] && continue
        # bind driver for vf
        echo $vf > $MLX5_BIND 2>/dev/null
        echo "rebind driver for VF:$vf"
    done
fi
