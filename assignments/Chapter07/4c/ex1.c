#include <stdio.h>
#include <unistd.h>

int main() {

	int i=0;

	char *newargv[16];
	char *newenvp[16];

	newenvp[0]=0;

	newargv[i++]="ps";  
	newargv[i++]="-f";
	newargv[i++]=0;

	// execvp(newargv[0], newargv);  // is what the shell uses
	execvp(newargv[0], newargv);  // is what the shell uses

	// code never reached!!
	printf("Hello World\n");

	return 0;
}
	
