#include <sys/types.h>
#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>
#include "ex1.h"

void myprintf(char *arg) {
	system ("ps -f");
}

int main() {
	
	char *str;

	str=(char *)getenv("PARM1");
	printf("Hello %s .. Testing %d from PID=%d PPID=%d\n", str, TESTNUM, getpid(),getppid());
	printf("Hello .. Got PARM1=%s\n", str);

	if (str)
		myprintf(str);

	return 0;
}
