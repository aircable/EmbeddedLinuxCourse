#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main() {
	
	printf("PID==%d\n",getpid());

	while (putchar(  getchar() ));

}
