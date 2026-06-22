#!/bin/bash -ax

# Step #1: Identify Latest Version.
mkdir -p ~/el/busybox/log
cd ~/el/busybox/log
#sudo rm downloads
rm -f index*
wget -q https://busybox.net/downloads/ 
# LatestRel=$(grep bz2 downloads|egrep -v -e "\.\."|sed -e 's/.*busybox-/busybox-/g' -e 's/\.bz2.*/\.bz2/' | tail -1)
LatestRel=$(grep bz2 index.html | sed -e 's/.*busybox[_-]/busybox-/g' -e 's/\.bz2.*/\.bz2/' | grep -v -E -e "\.\." | grep busybox | tail -1 | sed 's/\.tar\.bz2//')

# Step #2: Get the Latest Version.
mkdir -p ~/el/busybox
cd ~/el/busybox
wget -q https://busybox.net/downloads/${LatestRel}.tar.bz2
tar xf ${LatestRel}.tar.bz2
cd ${LatestRel}
