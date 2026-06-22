#include <stdio.h>
#include <unistd.h>

int main() {

	int i=0;

	char *newargv[16];
	char *newenvp[16];

	newenvp[0]=0;

	// newargv[i++]="myps";        // just the name of the process .. can be anything.
	newargv[i++]="funny thing";    // just the name of the process .. can be anything.
	newargv[i++]="-f";
	newargv[i++]=0;

	execvp("/usr/bin/ps", newargv);  // is what the shell uses

	// code never reached!!
	printf("Hello World\n");

	return 0;
}
	
