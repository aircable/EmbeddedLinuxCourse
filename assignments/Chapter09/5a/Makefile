#
# A Makefile is a file containing rules.
#
#
# TARGET:	<list of dependencies>
# <tab>	Action/Rule Lines
# <tab>	Action/Rule Lines
# <tab>	Action/Rule Lines
# <tab>	Action/Rule Lines
#

dbg: ex1 clean
	@echo bb

ex1: ex1.c ex1a.c ex1.h
	gcc -o ex1 ex1.c ex1a.c

clean: 
	rm -f ex1 ex1.o ex1a.o

example: bogus
	echo aa

bogus: 
	-@gcc -c aa.c

distclean: 
	@make -s clean 
	
# @make clean 1>/dev/null 2>&1
