// #define _GNU_SOURCE
#include <stdio.h>

#include <sys/types.h>
#include <unistd.h>

#include <sys/syscall.h>

int main(int argc, char *argv[])
{
	pid_t tid, pid;

	pid = getpid();
	tid = syscall(SYS_gettid);
	// tid = gettid();
	
  printf("Hello World .. PID=%d TID==%d\n", pid, tid);

}
