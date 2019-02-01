#
##Desgin of Netlink
#
#
MODULE_NAME :=netlink_server
obj-m :=$(MODULE_NAME).o

KERNELDIR ?= /usr/lib/modules/3.10.0/build
PWD := $(shell pwd)

all:
	    $(MAKE) -C $(KERNELDIR) M=$(PWD)

clean:
	    $(MAKE) -C $(KERNELDIR) M=$(PWD) clean
