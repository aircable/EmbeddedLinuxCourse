#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *myfn( void *fnptr );

// #define gettid() syscall(SYS_gettid,NULL,NULL,NULL)

int main()
{
     pthread_t t1;
     char *s1 = "Thread 1";
		 int c;
     int  r1;

	// int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
	//                           void *(*start_routine) (void *), void *arg);
		 //
		 // BEWARE: thread id in 't1' can get reused.
		 // 
		 // r1==0 (on success) or ERRNO (on failure)
		 //
	 	 printf("%d. In %s: My PID=%u MyTID=%u MypThId=%#0x\n",0, "main",
			getpid(),gettid(),pthread_self());

     r1 = pthread_create( &t1, NULL, myfn, (void*)s1);

		 // do fun stuff here in main()
		 fprintf(stderr,"Enter a char: ");
		 c=getchar();

		 // ready for the rejoin of the thread
     pthread_join( t1, NULL);

     printf("In Main:Thread 1 returns: %d\n",r1);


		 fprintf(stderr,"Waiting for a char ... ");
		 c=getchar();
     exit(0);
}

void *myfn( void *fnptr )
{
	char *msg = (char *) fnptr;
	int i=0;
	int c=0;

	for (i=0; i++<180;) {
	 	// gettid was not directly supported in glibc till about 2.30 .. about 2019. see 'man gettid'
	 	// printf("%d. In %s: My PID=%u, My TID=%u\n",i,msg,getpid(),gettid());
    // while(1);
		sleep(1);
	}

	// fprintf(stderr,"Waiting for a char (in thread 1) ... ");
	// c=getchar();
	
	return 0;
}
