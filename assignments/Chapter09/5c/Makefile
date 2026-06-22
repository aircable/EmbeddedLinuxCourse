# all: run recompile clean
all: run clean

run: ex1
	./ex1
	#sleep 40; touch ./ex1.h
	ls -l ./ex1.? ./ex1
	#rm -f ex1

ex1: ex1.c ex1.h

recompile: ex1
	ls -l ./ex1.? ./ex1
	@make ex1
	ls -l ./ex1.? ./ex1

clean:
	rm -f ./ex1
