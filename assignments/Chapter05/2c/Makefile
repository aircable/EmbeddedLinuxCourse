# set tabstop=2 number nohlsearch

CONFIG_MODULE_SIG=n

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

OBJ := hello

obj-m := $(OBJ).o

all: load clean
	-rm -f nm.*

run:  load 
	-lsmod | head
	-cat /proc/kallsyms | grep hello

compile:
	@$(MAKE) -C $(KDIR) M=$(PWD) modules 

###  Alternative antiquated syntax
###  $(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules 

load:	compile
	@echo "try \"tail -f /var/log/messages\" in another window(as root) ..";
	su -c "insmod ./$(OBJ).ko"
	-lsmod | head
	@cd ../1/; make -s compile; cd -;nm ../1/hello.ko | awk '{printf("%-35s\n", $$0);}' > nm.hello.ko.EX1
	-nm hello.ko > nm.hello.ko.EX1c
	paste nm.hello.ko.EX1 nm.hello.ko.EX1c
	grep hello /proc/kallsyms

unload: 
	-su -c "rmmod $(OBJ)"

clean: unload
	-@rm -f *.o *.ko .tmp_versions* [mM]odule* *.mod *.ko.* .[mM]odule* .cache.mk *.cmd .*.cmd *.mod.c
	-@rm -fr .tmp_versions*
