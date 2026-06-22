#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

void *myfn( void *fnptr );

int main()
{
     pthread_t t[4];
     char *s1 = "Thread 1";
     char *s2 = "Thread 2";
     char *s3 = "Thread 3";
     char *s4 = "Thread 4";
     long  r[4];
		 int i=0;

		 printf(" main() resides at %#0x, while myfn() resides at %#0x\n", main, myfn); 

     r[i] = pthread_create( &t[i], NULL, myfn, (void*)1);
     i++; r[i] = pthread_create( &t[i], NULL, myfn, (void*)2);
     i++; r[i] = pthread_create( &t[i], NULL, myfn, (void*)3);
     i++; r[i] = pthread_create( &t[i], NULL, myfn, (void*)4);

		 i=0;
     pthread_join( t[i], (void **)r[i]);
     i++; pthread_join( t[i], (void **)r[i]);
     i++; pthread_join( t[i], (void **)r[i]);
     i++; pthread_join( t[i], (void **)r[i]);

		 i=0;
     printf("In Main:Thread %d returns: %d\n",i,r[i]);
     i++; printf("In Main:Thread %d returns: %d\n",i,r[i]);
     i++; printf("In Main:Thread %d returns: %d\n",i,r[i]);
     i++; printf("In Main:Thread %d returns: %d\n",i,r[i]);
     exit(0);

}

void *myfn( void *fnarg )
{
	 long i=0;

   while(i++<10000000);

   return fnarg;
}
