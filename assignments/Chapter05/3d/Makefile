KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

OBJ := main

obj-m := $(OBJ).o

all: clean load 
	@make -s clean

run:  load unload

compile:
	#rm -f ./main.c
	@$(MAKE) -C $(KDIR) M=$(PWD) modules 

###  
###  Alternatively, you may want to use the early 2.6 syntax of
###  $(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules 
###  
###

load:	compile
	@echo "try \"tail -f /var/log/messages\" in another window(as root) ..";
	su -c "insmod ./$(OBJ).ko";
	ls -l /sys/kernel/kobject_example
	sleep 1
	cat /sys/kernel/kobject_example/foo
	@echo "ls /sys/module/<module-name>/"
	ls /sys/module/main/*
	cat /sys/module/main/taint

unload: 
	-su -c "rmmod $(OBJ)"

clean: unload
	-@rm -fr $(OBJ).o $(OBJ).ko $(OBJ).*.* .$(OBJ).* .tmp_versions* [mM]odule* procApp *.mod .[mM]*.cmd
