

## it will look for the very first target & dependency line
# target: dependencies
all: run clean

run: ex1
	./ex1

ex1: ex1.c ex1.h
	cc -o ex1 ex1.c   ## <<<<<<<<<<< ACTION Line

ex1.h:

clean:
	rm -f ./ex1

### syntax
#<nospace>target: dependencies .. space delimited
#<tab>shell command .. FUNDAMENTAL RULE ... otherwise you get the missing separator error
