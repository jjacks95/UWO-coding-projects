#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/wait.h>
#include <math.h>

#define BILLION  1000000000L

#define CLOCK_ID CLOCK_PROCESS_CPUTIME_ID

/* This Program makes a minmal function call and a system call
	measuring the time it takes to complete each call			*/

//function from measureExample.c
uint64_t diff(struct timespec start, struct timespec end)
{
  uint64_t diff;

  diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;

  return diff;
}

//minimal function
void minFunc(){
}

int main(int argc, char *argv[]){
	

	struct timespec startFunc, endFunc, startSys, endSys;
	uint64_t FuncElapsedTime, SysElapsedTime;
		
	//minimal function call
	clock_gettime(CLOCK_ID, &startFunc);
		minFunc();
	clock_gettime(CLOCK_ID, &endFunc);
	FuncElapsedTime = diff(startFunc,endFunc);
	
	//minimal system call
	clock_gettime(CLOCK_ID, &startSys);
		getpid();
	clock_gettime(CLOCK_ID, &endSys);
	SysElapsedTime = diff(startSys,endSys);
	
	printf("Minimal Function Call: elapsed process CPU time is %llu\n", (long long unsigned int) FuncElapsedTime);
	printf("System Call: elapsed process CPU time is %llu\n", (long long unsigned int) SysElapsedTime);
	
}
