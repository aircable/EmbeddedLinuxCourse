// from the text book
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#define BUFFER_SIZE (1024 * 1024)

static int c=0;
static int majfault[4];	
static int minfault[4];	

void print_pgfaults(void)
{
	int ret;
	struct rusage usage;

	ret = getrusage(RUSAGE_SELF, &usage);
	if (ret == -1) {
		perror("getrusage");
	} else {
		majfault[c++]=usage.ru_majflt;
		printf("Major page faults %ld\n", usage.ru_majflt);
		minfault[c]=usage.ru_minflt;
		printf("Minor page faults %ld\n", usage.ru_minflt);
	}
}

int main(int argc, char *argv[])
{
	unsigned char *p;
	printf("Initial state\n");
	print_pgfaults();
	p = malloc(BUFFER_SIZE);
	printf("After malloc\n");
	print_pgfaults();
	memset(p, 0x42, BUFFER_SIZE);
	printf("After memset\n");
	print_pgfaults();
	memset(p, 0x42, BUFFER_SIZE);
	printf("After 2nd memset\n");
	print_pgfaults();

/*
	There were 172 minor page faults encountered after initializing the program’s environment and a further 14
when calling getrusage(2) (these numbers will vary depending on the architecture and the version of the C
library being used).

	The important part is the increase when filling the memory with data: 442 - 186 = 256. The buffer is 1 MiB,
which is 256 pages.
*/
	return 0;
}
