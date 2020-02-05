from pyroute2 import IPRoute
import os

def test_bond():
    ipr = IPRoute()
    ethx_index = ipr.link_lookup(ifname = "ens38")
    print("ens38 index:%s" % ethx_index)
    ipr.link("", index = ethx_index, )

test_bond()
