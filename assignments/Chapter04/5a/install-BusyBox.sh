#!/bin/bash -a
D="`pwd`"
mkdir -p ~/el ~/src ~/el/busybox
cd ~/el
mkdir -p log 
rm -f log/*.log log/*html*

echo "run make in $D to install from there" > log/README.txt

DIST="`cat /proc/version | sed -e 's/.*Ubuntu.*/Ubuntu/g' -e 's/.*Red *Hat.*/RedHat/g'`"
echo $DIST

##
##  Step #1. figure out LatestRelease & LatestRelDT
##  
cd log
wget -q https://busybox.net
LatestRelease=$(grep BusyBox index.html | grep stable | grep -v unstable | head -1 | awk '{print $(NF-1)}')
LatestRelDT=$(grep BusyBox index.html | grep stable | grep -v unstable | head -1 | awk '{print $1, $2, $3}' | sed 's/.*>//g')
echo "using ${bold}BusyBox${normal} $LatestRelease released $LatestRelDT"

##
##  Step #2. git - clone and checkout
##  
cd ~/el
[ \( -d busybox \) -a \( -d busybox/.git \) ] && \
  { echo "removing existing busybox and reinstalling"; rm -rf busybox; }
echo "git clone git://busybox.net/busybox.git"
git clone git://busybox.net/busybox.git 2>&1 | tee log/git_clone_busybox.log >/dev/null
cd busybox
echo "git checkout ${LatestRelease}"
git checkout ${LatestRelease} 2>&1 | tee  ../log/git_checkout_busybox-${LatestRelease}.log >/dev/null



