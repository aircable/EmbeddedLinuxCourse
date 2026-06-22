#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int i=1;

	while(i++<120) 
	{
		fprintf(stderr,"Hello World");
		sleep(1);
	}
}
