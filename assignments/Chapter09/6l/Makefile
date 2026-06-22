all: run

run:
	ps -Aly | head
	ps -eo pid,tid,class,rtprio,stat,vsz,rss,comm | head
	top -b -n 1 | head
