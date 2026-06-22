all: install run

install:
	# https://www.osadl.org/Realtime-test-utilities-cyclictest-and-s.rt-test-cyclictest-signaltest.0.html
	./install_cyclictest.sh

run:
	(cd ~/rt/rt-tests; \
	echo "running one thread alone"; \
	sudo ./cyclictest -l 10000 -m -n -p 99)
	(cd ~/rt/rt-tests; \
	echo "running one thread per core";\
	sudo ./cyclictest -l 10000 -a -t -n -p99)

clean:
	-cd ~/rt; sudo rm -rf rt-tests
