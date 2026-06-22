all: kernel

run:
	less /proc/meminfo

kernel:
	# figure out memory used by kernel.
	sudo more /proc/slabinfo | head
	sudo more /proc/vmallocinfo | head
	egrep "Slab|KernelStack|PageTables|VmallocUsed" /proc/meminfo | \
		awk '{sum+=$$2;} END {print "kernel memory usage=" sum/1024 " kb";}'
	lsmod | awk '{sum+=$$2;} END {print "module memory usage=" sum/1024 " kb";}'
