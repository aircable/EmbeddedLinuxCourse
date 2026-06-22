#include <stdio.h>
#include <sys/time.h>

/*
	
 man 7 vdso

 The  "vDSO"  (virtual dynamic shared object) is a small shared library 
 that the kernel automatically maps into the address space of all 
 user-space applications.  Applications usually  do  not  need  to
 concern  themselves  with  these details as the vDSO is most commonly 
 called by the C library.  This way you can code in the normal way 
 using standard functions and the C  library  will  take  care  of
 using any functionality that is available via the vDSO.

 Why  does  the  vDSO  exist at all?  There are some system calls the 
 kernel provides that user-space code ends up using frequently, to the 
 point that such calls can dominate overall performance.   This
 is  due  both  to the frequency of the call as well as the context-switch 
 overhead that results from exiting user space and entering the kernel.

 One frequently used system call is gettimeofday(2).  This system call 
 is  called  both  directly  by user-space applications as well as 
 indirectly by the C library.  Think timestamps or timing loops or
 polling—all of these frequently need to know what time it is right now.
 This  information  is  also not  secret—any  application in any 
 privilege mode (root or any unprivileged user) will get the same
 answer.  Thus the kernel arranges for the information required to 
 answer this question to be  placed in  memory  the  process  can access.  

 Now a call to gettimeofday(2) changes from a system call to a
 normal function call and a few memory accesses.

*/


int main() {
	
	int i=0;
  struct timeval tv[1];  

	while (i++<100000000)
   	gettimeofday(tv, NULL);  

}
