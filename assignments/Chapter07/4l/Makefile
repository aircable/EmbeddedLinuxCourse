all: run clean

LDFLAGS="-pthread"

run: ex1 ex2
	time -p ./ex1
	# time -p ./ex2
	# -diff ex1.c ex2.c

ex1: ex1.c

ex2: ex2.c

clean:
	rm -f ex?
