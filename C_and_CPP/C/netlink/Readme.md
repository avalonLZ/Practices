Makefile中的“KERNELDIR ?= /usr/lib/modules/3.10.0/build“这句在不同机器上需要进行修改，认准find / -name `uname -r`，得出的路径中的build文件夹或链接即可
