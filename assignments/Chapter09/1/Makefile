all: run clean

run: ex1
	sudo cat /proc/sys/kernel/core_uses_pid
	sudo cat /proc/sys/kernel/core_pattern
	## sudo echo /corefiles/core.%e.%t > /proc/sys/kernel/core_pattern
	## sudo cat /proc/sys/kernel/core_pattern
	## sudo echo /corefiles/core.%p > /proc/sys/kernel/core_pattern
	## sudo cat /proc/sys/kernel/core_pattern
	## at this time the ulimit -c is 0
	(sleep 2;./ex1; ) &
	sleep 2;
	-pkill -11 ./ex1  ## no core file generated, since ulimit -c = 0
	sleep 1;
	-ls -l core.*
	@echo "no core file generated at this time .. since \"ulimit -c\" is set to `ulimit -c`"
	@sleep 2;
	## explicitly unset ulimit -c
	(ulimit -c unlimited; sleep 2;./ex1; ) &
	sleep 2;
	-pkill -11 ex1  ## pkill here
	sleep 1;
	-ls -l core.*
	@ulimit -c unlimited; echo "core file is generated at this time .. since \"ulimit -c\" is set to `ulimit -c`"
	@sleep 2;

clean:
	rm -f core.* ./ex?
