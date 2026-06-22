EX := ex1
all: run clean

LDFLAGS="-pthread"

run: ${EX}
	time ./${EX} &
	-(sleep 3; ps -C ${EX} -L -o pid,tid,class,rtprio,ni,pri,psr,pcpu,stat,wchan:25,comm)
	-(sleep 3; ps -C ${EX} -L -o pid,tid,class,rtprio,ni,pri,psr,pcpu,stat,wchan:25,comm)
	-(sleep 8; ps -C ${EX} -L -o pid,tid,class,rtprio,ni,pri,psr,pcpu,stat,wchan:25,comm)

${EX}: ${EX}.c

clean:
	rm -f ex?
