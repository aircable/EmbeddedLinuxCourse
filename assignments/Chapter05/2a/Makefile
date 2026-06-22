# set tabstop=2 number nohlsearch

CONFIG_MODULE_SIG=n

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

OBJ := hello

obj-m := $(OBJ).o

all: prep load clean
	#@make -s clean
	rm -f nm*

prep:
	## @echo "see line #42 in /etc/rsyslog.conf"
	## sleep 10
	## vim +42 /etc/rsyslog.conf
	cat use_dmesg_or_varlogmessages_or_varlogkern.log_or_journalctl.txt | more

run:  load 

compile:
	@$(MAKE) -C $(KDIR) M=$(PWD) modules 

###  Alternative antiquated syntax
###  $(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules 

load:	compile
	@echo "\"tail -f /var/log/messages\" in another window(as root) ..";
	@echo " or run"
	@echo "watch -d -n 2 \"dmesg | tail -12\""
	su -c "insmod ./$(OBJ).ko"
	-@echo "see +175 /usr/src/linux/include/linux/module.h ... GPL and variants"
	-@echo "see +8 /usr/src/linux/include/linux/kern_levels.h ... Msg Priority Levels"

checks: load
	-lsmod | head
	-cat /proc/kallsyms | grep hello
	-nm hello.o
	-nm hello.ko

unload: 
	-su -c "rmmod $(OBJ)"

clean: unload
	-@rm -f *.o *.ko .tmp_versions* [mM]odule* *.mod *.ko.* .[mM]odule* .cache.mk *.cmd .*.cmd *.mod.c
	-@rm -fr .tmp_versions*
