#include <mcheck.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int j;
	void *d;
	mtrace();
	for (j = 0; j < 2; j++)
		d=malloc(100); /* Never freed:a memory leak */
	d=calloc(16, 16); /* Never freed:a memory leak */
	exit(EXIT_SUCCESS);
}
