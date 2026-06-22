EX1:=ex3
EX1:=ex1
EX1:=ex1a
EX1:=ex2

all: run clean

CFLAGS="-pthread"

run: $(EX1)
	## Watch here ex1 is an orphan, because the subshell has exited. 
	cat NOTE_on_pthreads.txt
	sleep 2
	./$(EX1) &  
	ps -f
	ps -mL
	ps -C $(EX1) -L -o pid,tid,class,rtprio,ni,pri,psr,pcpu,stat,wchan:25,comm

$(EX1): $(EX1).c

clean:
	rm -f ex? ex1?
