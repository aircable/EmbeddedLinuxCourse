PARM1 = "Makefile"

all: run 

run: ex1
	@echo "now running ex1"

ex1: ex1.c ex1.h
	tree
	read x
	@make -C a 
	@make -C b  

clean:
	rm -f ex1 core.* */core.* */*/core.*

