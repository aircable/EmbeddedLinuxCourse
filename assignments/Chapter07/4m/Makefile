EX := ex1
all: run clean

LDFLAGS="-pthread"

run: ${EX}
	time ./${EX}  &
	-(sleep 3; ps -C ${EX} -L -o pid,tid,class,rtprio,ni,pri,psr,pcpu,stat,wchan:25,comm)
	-(sleep 5; ps -C ${EX} -L -o pid,tid,class,rtprio,ni,pri,psr,pcpu,stat,wchan:25,comm)
	-(sleep 5; ps -C ${EX} -L -o pid,tid,class,rtprio,ni,pri,psr,pcpu,stat,wchan:25,comm)
	-@echo "see man 2 sched_setscheduler"
	-@echo "see man 7 sched"

ex1: ex1.c

clean:
	rm -f ex?
