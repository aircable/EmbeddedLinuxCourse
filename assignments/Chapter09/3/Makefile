all: run clean

clean:
	rm -f ex?

run: ex1 ex2
	./ex1 & 
	./ex1 & 
	./ex1 & 
	./ex1 & 
	sleep 2
	./ex2 &
	sleep 15
	-pkill -9 ex1
	-pkill -9 ex2
