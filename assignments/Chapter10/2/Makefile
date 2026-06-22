all: run

run:
	time -p  sudo ./run_ftrace.sh

clean:
	-sudo echo "nop" > /sys/kernel/debug/tracing/current_tracer
	-sudo rm -f *.out
