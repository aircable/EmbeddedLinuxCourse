# set tabstop=2 number nohlsearch

CONFIG_MODULE_SIG=n

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

OBJ := main

obj-m := $(OBJ).o

all: load clean

run:  load unload

compile:
	@$(MAKE) -C $(KDIR) M=$(PWD) modules 

###  
###  Alternatively, you may want to use the early 2.6 syntax of
###  $(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules 
###  
###

load:	compile
	@echo "try \"tail -f /var/log/messages\" in another window(as root) ..";
	# su -c "insmod ./$(OBJ).ko howmany=4 whom=World"
	su -c "insmod ./$(OBJ).ko whom=Universe howmany=2"
	# su -c "insmod ./$(OBJ).ko whom=Globe"
	# su -c "insmod ./$(OBJ).ko"
	# su -c "insmod ./$(OBJ).ko who=Globe"
	# su -c "insmod ./$(OBJ).ko howmany=4 whom=Galaxy"
	@sync;sync;sleep 1;
	-cat /proc/kallsyms | grep '\[main\]' 
	@dmesg | tail -6

unload: 
	-su -c "rmmod $(OBJ)"

clean: unload
	-@rm -f *.o *.ko .tmp_versions* [mM]odule* *.mod *.ko.* .[mM]odule* .cache.mk *.cmd .*.cmd *.mod.c
	-@rm -fr .tmp_versions*
