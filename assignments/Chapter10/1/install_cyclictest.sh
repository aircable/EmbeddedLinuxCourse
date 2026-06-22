# https://www.osadl.org/Realtime-test-utilities-cyclictest-and-s.rt-test-cyclictest-signaltest.0.html
KERNELGIT=git://git.kernel.org/pub/scm/linux/kernel/git
mkdir -p ~/rt
cd ~/rt
[ ! -d rt-tests ] && { sudo git clone $KERNELGIT/clrkwllms/rt-tests.git; }
cd rt-tests
cat <<EOF
	on Fedora 
		sudo dnf -y install make automake gcc gcc-c++ kernel-devel libnuma-devel numactl-devel
	on Ubuntu
		sudo aptget -y install build-essential libnuma-dev

EOF
echo "Press Enter (if above packages exist) or ^C .."
sleep 2
read x
export PYTHONWARNINGS="ignore"
sudo make 2>/dev/null
# sudo ./cyclictest -l 100000 -a -t -n -p99
# sudo ./cyclictest -l 100000 -m -n -p 99
# echo "running one thread alone"
# sudo ./cyclictest -l 10000 -m -n -p 99
# echo "running one thread per core"
# sudo ./cyclictest -l 10000 -a -t -n -p99
