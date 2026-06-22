#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

	int pid, n;
	int status;

	// call fork() here.
	switch (pid=fork()) {

		// case when -1 .. error .. typically happens when there are too many processes. runaway (??)
		case -1:
			fprintf(stderr,"fork() failed\n");
			break;
		
		// case when 0 .. success: .. in the context of the child.
		case 0:
			fprintf(stderr,"Hello World .. child curr PID(%d), PPID(%d)\n",getpid(),getppid());
			sleep(5);
			break;

		// case when positive .. success: .. in the context of the parent.
		default:
			fprintf(stderr,"Hello World .. parent curr PID(%d), PPID(%d)\n",getpid(),getppid());
			sleep(2);
			system("ps -f");
			break;
	}

	return 0;

}	
