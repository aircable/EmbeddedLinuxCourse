EX1:=ex1

all: run clean

CFLAGS="-pthread"

run: $(EX1)
	## Watch here ex1 is an orphan, because the subshell has exited. 
	./$(EX1) &  
	ps -f
	ps -mL
	cat /proc/sys/kernel/threads-max

$(EX1): $(EX1).c

clean:
	rm -f ex? ex1?
