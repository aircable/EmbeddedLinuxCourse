Steps
1. Partition SD Card
2. Download Firmware and DTB 
3. Setup Toolchain on Host
4. Build Kernel
5. Copy Firmware, DTBs and Kernel to Boot Partition
6. Setup Config Files in /boot
7. Setup Root Filesystem 
8. Setup BusyBox 

###
##### --
###
1. PARTITION SD CARD

1a. Use a scratch SD CARD and 
    mount on Ubuntu host
    
1b. Use GPARTED tool
    see https://youtu.be/elG8-x_3mug (for steps) 

    Create 2 partitions on SD Card
    -  /boot partition: FAT32 partition of at least 64 MB
       it will contain firmware, device tree blobs, Linux kernel, 
       and configuration files: config.txt and cmdline.txt. 
    -  / root partition: EXT4 partition of at least 4 GB 
       it will contain kernel modules and busybox - for now.

###
##### --
###

2. DOWNLOAD FIRMWARE AND DTB 
   see github/raspberrypi/firmware: https://github.com/raspberrypi/firmware 


2a. bootcode.bin
    wget https://github.com/raspberrypi/firmware/blob/master/boot/bootcode.bin 

2b. fixup.dat
    wget https://github.com/raspberrypi/firmware/blob/master/boot/fixup.dat

2c. start.elf 
    wget https://github.com/raspberrypi/firmware/blob/master/boot/start.elf


##
## steps to help above.
# mount /dev/sdb1 /mnt/boot
# mount /dev/sdb2 /mnt/root
# tar czvf bootfiles.tar --exclude=/mnt/boot/"System Volume Information"* /mnt/boot/* 
##
# set -a
# TDIR=$(mktemp -u)
# cd $TDIR
# mkdir overlays
# wget https://github.com/raspberrypi/firmware/blob/master/boot/
# for f in $(grep title index.html | sed -e 's/<[^>]*>//g' -e 's/<a data-.*//' -e 's/kernel: Bump.*//'| egrep -v "^[  ]*$|See:|More|Update" | egrep "overlays|linux|broadcom|dtb|bootcode|fixu.*.dat|kern.*img|star.*elf")
  do
    wget -q https://github.com/raspberrypi/firmware/blob/master/boot/$f
  done
# cd overlays
# wget -q https://github.com/raspberrypi/firmware/blob/master/boot/overlays/
# for f in $(grep title index.html | sed -e 's/.* title="//' -e 's/" data-turbo.*//g' -e 's/<span .*//' -e 's/kernel:.*//' | egrep dtbo); do   wget https://github.com/raspberrypi/firmware/blob/master/boot/overlays/$f; done
###
##### --
###

3. CREATE TOOLCHAIN ON HOST

3a. Create your own.
    use crosstool-ng from previous chapter.

    export TGT=${1:-"rpi4"} 
    export PATH=$PATH:~/x-tools/aarch64-${TGT}-linux-gnu/bin
    aarch64-${TGT}-linux-gnu-gcc hello.c -o ${TGT}-helloc
    aarch64-${TGT}-linux-gnu-g++ hello.cpp -o ${TGT}-hellocpp
    file ${TGT}-helloc ${TGT}-hellocpp

3b. Alternatively, use a prebuilt toolchain for 
    `arm-linux-gnueabihf-*` compiler, linker etc.
    sudo apt -y install bc bison crossbuild-essential-armhf \
      flex git libc6-dev libncurses5-dev libssl-dev 

###
##### --
###

4. BUILD KERNEL

4a. Create base dirs

    mkdir -p ~/el/rpi/
    cd ~/el/rpi/

4b. use a prebuilt kernel from RPi foundation

    export ARCH=arm
    export CROSS_COMPILE=arm-linux-gnueabihf-

    git clone https://github.com/raspberrypi/linux --depth=1 
    cd linux 

4c. or, alternatively, get latest kernel, and
    use crosstool-ng steps in #1

    export ARCH=arm
    export TGT=${1:-"rpi4"} 
    export PATH=$PATH:~/x-tools/aarch64-${TGT}-linux-gnu/bin
    export CROSS_COMPILE=aarch64-${TGT}-linux-gnu- 

    git clone git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux-stable.git --depth=1
    cd linux-stable

    export KERNEL=kernel7   # 
    make ARCH=arm multi_v7_defconfig  # (for rpi4 or for rpi3b)

4d. create config file and compile kernel
    export KERNEL=kernel7   # (for rpi4)
    make bcm2711_defconfig  # (for rpi4)

    export KERNEL=kernel7   # (for rpi3b)
    make bcm2709_defconfig  # (for rpi3b)

    make -j4 zImage modules dtbs 

###
##### --
###

5. COPY FIRMWARE, DTBs and KERNEL TO BOOT PARTITION .. on SD card.

   we have
   ** zImage     - compressed Linux kernel.
   ** DTBs       - physical/device 
   ** DTOverlays - overlays on core DTBs
 
   so, on Ubuntu Host

   mkdir -p ~/el/rpi/rpi_boot ~/el/rpi/rpi_boot/overlays

   cd ~/el/rpi/linux
   cp arch/arm/boot/zImage ~/el/rpi/rpi_boot
   cp arch/arm/boot/dts/bcm2710-rpi-3-b.dtb ~/el/rpi/rpi_boot
   cp arch/arm/boot/dts/bcm2711-rpi-4-b.dtb ~/el/rpi/rpi_boot
   cp arch/arm/boot/dts/overlays/disable-bt.dtbo* ~/el/rpi/rpi_boot/overlays 

   ** plug in SDCARD into Ubuntu host .. 
   ** locate boot partition of SDCARD in #1 (above)  .. 
   ** - modify /mnt/boot below as appropriate for you
   **   since we are using /mnt/boot - as placeholder for SDCARD location
   sudo cp -r ~/el/rpi/rpi_boot/* /mnt/boot

###
##### --
###

6. SETUP CONFIG FILES IN /boot

Summary
6a. Create config.txt file
6b. Create cmdline.txt file

Details
6a. Create config.txt file

  cd /mnt/boot
   
  cat >config.txt <<-EOF
	# Use Linux Kernel Image from earlier.
	kernel=zImage

	# Enable UART in order to use TTL cable. 
	enable_uart=1

	# Use appropriate DTB device.
	device_tree=bcm2711-rpi-4-b.dtb 
	# device_tree=bcm2710-rpi-3-b.dtb
	# device_tree=bcm2710-rpi-3-b-plus.dtb

	## - Additionally on RPi3b - Disable Bluetooth 
	## - - see https://youtu.be/68jbiuf27AY?t=431
	## - -     also https://github.com/raspberrypi/firmware/issues/553#issuecomment-199486644 
	## - - Do NOT skip this step, since UART/TTL connection will not work correctly.
	# dtoverlay=disable-bt 
	
	## - for RPi 4B, all you need is enable_uart=1
	## - - see https://forums.raspberrypi.com/viewtopic.php?t=309763 
	## - - see https://forums.raspberrypi.com/viewtopic.php?t=261753 (a better detail writeup).
EOF

6b. Create cmdline.txt file

  cd /mnt/boot
   
  cat >cmdline.txt <<-EOF
	console=tty1 console=serial0,115200 root=/dev/mmcblk0p2 rootfstype=ext4 rootwait
EOF

7. Setup Root Filesystem copy .. locally on host
	 root filesystem is where executables, kernel modules, system files etc reside.
   see Linux Filesystem Hierarchy Standard 
   - https://en.wikipedia.org/wiki/Filesystem_Hierarchy_Standard
 

7a. Install Kernel Modules
  
   export INSTALL_MOD_PATH=~/el/rpi/rpi_root
   mkdir -p $INSTALL_MOD_PATH
   cd ~/el/rpi/linux
   sudo su -c "make modules_install"
   
7b. Create system directories
   mkdir -p ~/el/rpi/rpi_root
   cd ~/el/rpi/rpi_root
	 mkdir proc sys dev etc usr
   mkdir -p etc/init.d

   cat >etc/init.d/rcS <<-EOF
		#!/bin/sh
		mount -t proc none /proc
		mount -t sysfs none /sys
		
		echo /sbin/mdev > proc/sys/kernel/hotplug
		mdev -s  
EOF
	 chmod +x etc/init.d/rcS 

8. Setup BusyBox
   statically cross-compile BusyBox - “Swiss Army Knife of Embedded Linux”. 
   a single executable that provides multiple functions .. 
   - depending on command that is run.

8a. Download BusyBox
   cd ~/el/rpi/
   git clone git://busybox.net/busybox.git --branch=1_33_0 --depth=1
   cd BusyBox

8b. Configure BusyBox
   make menuconfig
   
   use 
   - Settings -> Build static binary (no shared libraries)    .. Enable
   - Settings -> Cross compiler prefix   .. arm-Linux-gnueabihf- 
   - Settings -> Destination path for ‘make install’ .. same as INSTALL_MOD_PATH above

8c. Build BusyBox

   make -j4
   make install 

   BusyBox is now installed in ../root_fs. 
   many symbolic links are now created within bin/, sbin/, and usr/ directory 
   of your root filesystem directory ($INSTALL_MOD_PATH). 

 
9. Insert SDCARD into RPi and boot.

   Use TTL cable
   - will not work with HDMI monitor.

SUBMIT
------
output of 'uname -a' 
