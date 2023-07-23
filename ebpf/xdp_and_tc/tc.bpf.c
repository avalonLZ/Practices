// SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause)
/* Copyright (c) 2022 Hengqi Chen */
#include <vmlinux.h>
#include <bpf/bpf_endian.h>
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>

#define TC_ACT_OK 0
#define TC_ACT_SHOT 2
#define ETH_P_IP  0x0800 /* Internet Protocol packet	*/
#define SRC_MAC_MAP_SIZE 1024//需要参考ovs fdb表最大同时可以放多少条

struct {
        __uint(type, BPF_MAP_TYPE_LRU_HASH);
        __uint(max_entries, SRC_MAC_MAP_SIZE);
        __type(key, __be64);
        __type(value, bool);
} src_mac_map SEC(".maps");

struct {
        __uint(type, BPF_MAP_TYPE_ARRAY);
        __uint(max_entries, 1);
        __type(key, __u32);
        __type(value, __u32);
} active_port SEC(".maps");

SEC("xdp")
int tc_ingress(struct xdp_md *ctx)
{
	void *data_end = (void *)(__u64)ctx->data_end;
	void *data = (void *)(__u64)ctx->data;
	struct ethhdr *l2;
	__be64 src_mac;
	bool *value;
	int err;
	__u32 ifindex = ctx->ingress_ifindex;
	__u32 *ac_port;
	__u32 key = 0;

	l2 = data;
	if ((void *)(l2 + 1) > data_end)
		return XDP_PASS;

	//活动网口
	ac_port = bpf_map_lookup_elem(&active_port, &key);
	if (ac_port && *ac_port == ifindex) {
		//活动成员网口丢弃从其他成员口发出的报文
		src_mac = *((__be64 *)l2->h_source);
		value = bpf_map_lookup_elem(&src_mac_map, &src_mac);
		if (value) {
			bpf_printk("++++++ifindex:%u+++++++", ifindex);
			bpf_printk("src mac:%02x:%02x", l2->h_source[0], l2->h_source[1]);
			bpf_printk("%02x:%02x", l2->h_source[2], l2->h_source[3]);
			bpf_printk("%02x:%02x drop", l2->h_source[4], l2->h_source[5]);
			return XDP_DROP;
		}
	} else {
		//非活动成员网口丢弃所有组播、广播报文
		if (l2->h_dest[0] & 1) {
			bpf_printk("******ifindex:%u********", ifindex);
			bpf_printk("src mac:%02x:%02x", l2->h_source[0], l2->h_source[1]);
			bpf_printk("%02x:%02x", l2->h_source[2], l2->h_source[3]);
			bpf_printk("%02x:%02x", l2->h_source[4], l2->h_source[5]);
			bpf_printk("dst mac:%02x:%02x", l2->h_dest[0], l2->h_dest[1]);
			bpf_printk("%02x:%02x", l2->h_dest[2], l2->h_dest[3]);
			bpf_printk("%02x:%02x drop", l2->h_dest[4], l2->h_dest[5]);
			return XDP_DROP;
		}
	}

	return XDP_PASS;
}

SEC("tc")
int tc_egress(struct __sk_buff *ctx)
{
	int err;
	__be64 src_mac;
	struct ethhdr *l2;
	bool value = true;
	void *data = (void *)(__u64)ctx->data;
	void *data_end = (void *)(__u64)ctx->data_end;
	
	l2 = data;
	if ((void *)(l2 + 1) > data_end)
		return TC_ACT_OK;

	src_mac = *((__be64 *)l2->h_source);

	err = bpf_map_update_elem(&src_mac_map, &src_mac, &value, BPF_NOEXIST);
	if (!err) {
		bpf_printk("**src mac:%02x:%02x", l2->h_source[0], l2->h_source[1]);
		bpf_printk("%02x:%02x", l2->h_source[2], l2->h_source[3]);
		bpf_printk("%02x:%02x add", l2->h_source[4], l2->h_source[5]);
	}

	return TC_ACT_OK;
}

char __license[] SEC("license") = "GPL";
