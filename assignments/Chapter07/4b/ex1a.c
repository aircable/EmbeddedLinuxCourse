#include <stdio.h>

void printmsg(void);

int main() {

	int pid, n;
	int status;

	switch (pid=fork()) {

		// case when -1 .. error .. typically happens when there are too many processes. runaway (??)
		case -1:
			fprintf(stderr,"fork() failed\n");
			break;
		// case when 0 .. success: .. in the context of the child.
		case 0:
			fprintf(stderr,"Hello World .. child curr PID(%d), PPID(%d)\n",getpid(),getppid());
			sleep(5);
			printmsg();
			break;
		// case when positive .. success: .. in the context of the parent.
		default:
			sleep(2);
			fprintf(stderr,"Hello World .. parent curr PID(%d), PPID(%d)\n",getpid(),getppid());
			break;
	}

	return 0;

}	

void printmsg() {

		int i=0;

		while (i++<5) {
			fprintf(stderr,"Hello World .. child curr PID(%d), PPID(%d)\n",getpid(),getppid());
			system("ps -f");
			sleep(2);
		}
}

