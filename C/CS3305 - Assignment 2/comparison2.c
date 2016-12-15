#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <sched.h>


void signal_handler(int signal){

	if(signal == SIGINT){
		printf("Signal Interrupt\n");
		exit(0);
	}
}


int main(int argc, char *argv[]){
	
	int id, policy;
	char buffer[4096];
	struct sched_param param;
	pid_t pid;
	
	if(argc != 2){
		printf("Must include schedule policy, e.g. ./comparison2 SCHED_FIFO\n");
		exit(1);
	}
	policy = argv[1];
	
	//setting schedule policy
	param.sched_priority = sched_get_priority_max(policy);
		
	if(sched_setscheduler(0,policy,&param)){
		printf("Scheduling Failed\n");
		exit(1);
	}

	while(1){
		sleep(1);
		pid = fork();
		
		if(pid < 0){
			printf("Fork Failed\n");
			exit(1);
		}
		if(pid > 0){
			//parent process
		
		}else{
			//child process
			pid_t pid2 = getpid();

			//check for signal
			if(signal(SIGINT, signal_handler) == SIG_ERR){
				printf("Error: Can't Catch Signal\n");
				exit(1);
			}
		
			//child process executes I/O intensive function
			if(system("./IOBound") == -1){
				printf("system failed\n");
				exit(1);
			}
		}		
	}	
}
