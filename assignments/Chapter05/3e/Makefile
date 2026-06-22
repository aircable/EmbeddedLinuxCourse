KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

OBJ := main

obj-m := $(OBJ).o

all: clean load 
	@echo see http://lwn.net/Articles/51437/
	sleep 3
	@make -s clean

run:  load unload

compile:
	@$(MAKE) -C $(KDIR) M=$(PWD) modules 

###  
###  Alternatively, you may want to use the early 2.6 syntax of
###  $(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules 
###  
###

load:	compile
	-@cp /usr/src/linux/samples/kobject/kobject-example.c ./main.c
	@echo "try \"tail -f /var/log/messages\" in another window(as root) ..";
	su -c "insmod ./$(OBJ).ko";
	ls -ld /sys/kernel/kobject_example
	ls -l /sys/kernel/kobject_example
	cat /sys/kernel/kobject_example/foo
	sleep 1
	cat /sys/kernel/kobject_example/baz
	sleep 1
	cat /sys/kernel/kobject_example/bar

unload: 
	-su -c "rmmod $(OBJ)"
	-ls -d /sys/kernel/*

clean: unload
	-@rm -fr $(OBJ).o $(OBJ).ko $(OBJ).*.* .$(OBJ).* .tmp_versions* [mM]odule*
