/* see man 2 _syscall */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <linux/unistd.h>       /* for _syscallX macros/related stuff */
#include <linux/kernel.h>       /* for struct sysinfo */
#include <sys/sysinfo.h>

// _syscall1(int, sysinfo, struct sysinfo *, info);

int main(void)
{
	struct sysinfo s_info;
  int error;
	int i=0;

	while (i++<10000000)	  // BOGUS.  just to show high %sys
  	error = sysinfo(&s_info);


  printf("\n\ncode error = %d\n", error);
  printf("Uptime = %lds\nLoad (\?\?): 1 min %lu / 5 min %lu / 15 min %lu\n"
          "RAM: total %lu / free %lu / shared %lu\n"
          "Memory in buffers = %lu\nSwap: total %lu / free %lu\n"
          "Number of processes = %d\n",
          s_info.uptime, s_info.loads[0],
          s_info.loads[1], s_info.loads[2],
          s_info.totalram, s_info.freeram,
          s_info.sharedram, s_info.bufferram,
          s_info.totalswap, s_info.freeswap,
          s_info.procs);

	//memset(&s_info, 0, sizeof s_info);
	// if (!sysinfo(&s_info)) 
  {
    float f_load = 1.f / (1 << SI_LOAD_SHIFT); 
			// .f denotes that the floating-point number is single-precision
			// https://en.wikipedia.org/wiki/Single-precision_floating-point_format


    printf("load average (1 min): %.2f (%.0f%% CPU)\n",
			s_info.loads[0] * f_load,
     	s_info.loads[0] * f_load * 100/get_nprocs());
    // process other loads as well of you need
	}
  exit(EXIT_SUCCESS);
}
