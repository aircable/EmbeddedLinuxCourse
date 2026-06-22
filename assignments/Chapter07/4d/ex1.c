#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

	int pid, n;
	int status;

	int i=0;

	char *newargv[16];
	char *newenvp[16];

	// call fork() here.
  // COW happens here.
	switch (pid=fork()) {

		// two processes .. both in logically separate address spaces,
		//                   but in physically same address space .. because of mapping.

		// case when -1 .. error .. typically happens when there are too many processes. runaway (??)
		case -1:
			fprintf(stderr,"fork() failed\n");
			break;
		
		// case when 0 .. success: .. in the context of the child.
		case 0:
			fprintf(stderr,"Hello World .. child curr PID(%d), PPID(%d)\n",getpid(),getppid());

			newenvp[0]=0;

			newargv[i++]="ps";  
			newargv[i++]="-f";
			newargv[i++]=0;

			// exec overlays child with the new binary/executable
			// the address space of the child is completely demolished, 
			//     and replaced with new binary address space req.
			execvp(newargv[0], newargv);  // is what the shell uses

			// code never reached!!
			printf("Hello World\n");

			break;

		// case when positive .. success: .. in the context of the parent.
		default:
			fprintf(stderr,"Hello World .. parent curr PID(%d), PPID(%d)\n",getpid(),getppid());
			sleep(5);
			// system("ps -f");
			break;
	}

	return 0;

}	
