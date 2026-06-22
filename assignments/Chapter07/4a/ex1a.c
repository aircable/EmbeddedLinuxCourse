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
     pthread_t t1,t2,t3,t4;
     char *s1 = "Thread 1";
     char *s2 = "Thread 2";
     char *s3 = "Thread 3";
     char *s4 = "Thread 4";
		 int c;
     int  r1, r2, r3, r4;

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
     r2 = pthread_create( &t2, NULL, myfn, (void*)s2);
     r3 = pthread_create( &t3, NULL, myfn, (void*)s3);
     r4 = pthread_create( &t4, NULL, myfn, (void*)s4);

		 // do fun stuff here in main()
		 fprintf(stderr,"Enter a char: ");
		 c=getchar();

		 // ready for the rejoin of the thread
     pthread_join( t1, NULL);
     pthread_join( t2, NULL);
     pthread_join( t3, NULL);
     pthread_join( t4, NULL);

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

	for (i=0; i++<300;) {
	 	// gettid was not directly supported in glibc till about 2.30 .. about 2019. see 'man gettid'
	 	printf("%d. In %s: My PID=%u, My TID=%u\n",i,msg,getpid(),gettid());
    // while(1);
		sleep(1);
	}

	// fprintf(stderr,"Waiting for a char (in thread 1) ... ");
	// c=getchar();
	
	return 0;
}
