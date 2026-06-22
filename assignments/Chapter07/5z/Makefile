EX1:=ex1

all: run clean

run: $(EX1) exec_target
	@echo "benchmark for fork(), vfork(), exec()"
	-./ex1 -h
	./ex1 --fork 0 --timeout=10
	./ex1 --fork 0 --exec --timeout=10

exec_target:
	CFLAGS += -static -nostartfiles


clean:
	rm -f ex? ex1? exec_target
