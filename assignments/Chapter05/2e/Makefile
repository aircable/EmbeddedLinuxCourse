# set tabstop=2 number nohlsearch

CONFIG_MODULE_SIG=n

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

OBJ := hello

obj-m := $(OBJ).o

all: load clean

run:  load
	lsmod | head
	cat /proc/kallsyms | grep hello

compile:
	@$(MAKE) -C $(KDIR) M=$(PWD) modules 

###  Alternative, antiquated syntax
###  $(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules 

load:	compile
	@echo "try \"tail -f /var/log/messages\" in another window(as root) ..";
	su -c "insmod ./$(OBJ).ko"
	nm ./$(OBJ).ko
	lsmod | head
	cat /proc/kallsyms | grep hello
	@dmesg | tail -1

unload: 
	-su -c "rmmod $(OBJ)"
	@dmesg | tail -1

clean: unload
	-@rm -f *.o *.ko .tmp_versions* [mM]odule* *.mod *.ko.* .[mM]odule* .cache.mk *.cmd .*.cmd *.mod.c
	-@rm -fr .tmp_versions*
