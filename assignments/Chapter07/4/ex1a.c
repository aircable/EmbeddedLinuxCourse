// example of a process.
#include <stdio.h>
#include <unistd.h>

int main()
{
	fprintf(stderr,"My PID==%u\n",getpid());
	while(1);
}
