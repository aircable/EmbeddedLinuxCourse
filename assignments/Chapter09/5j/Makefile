PARM1 = "Universe"

all: run clean

run: ex1
	export PARM1="WORLD"; ./ex1; 
	./ex1
	export PARM1="GALAXY"; ./ex1;
	PARM1="world" ./ex1; 
	./ex1

ex1: ex1.c ex1.h
	(gcc -o ex1 ex1.c; )

clean:
	rm -f ex1 core.*
