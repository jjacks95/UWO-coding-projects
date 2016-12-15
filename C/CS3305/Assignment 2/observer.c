#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*	Program executes command line argument and measures
	time spent in user mode as well as kernel mode		*/								


//signal catching function
void signal_handler(int signal){

	if(signal == SIGINT){
		printf("\nSignal Interrupt\n");
		exit(0);
	}
}

//time executable is in user mode 
//time executable is in kernel mode
void UserKernelMode(char *execute){
	FILE *fp;
	pid_t pid;
	
	int i;
	int id;
	
	char filename[10];
	char dir[] = "proc";
	char folder[] = "stat";
	char buffer[4096];

	pid = fork();
	
	if(pid < 0){			
		//fork failed
		printf("Forking Failed\n");

	}
	if(pid > 0){
		//child-parent process			
		execlp(execute,execute, NULL);
		wait(0);
		
	}else{
		sleep(1);
		//child-child process	
		while(1){
		
			id = getppid();
		
			sprintf(filename,"/%s/%d/%s",dir,id,folder);
			printf("Filename: %s\n", filename);
		
			fp = fopen(filename, "r");
			i=0;
			
			//fscanf everything in the file
			while(fscanf(fp,"%s", buffer) != EOF){
				i++;
				
				//User Mode and Kernel Mode formatting
				//and displaying
				if(i == 14){
					float user_mode = atof(buffer)/100;
					printf("User Mode: %lf seconds\n", user_mode);
				}
				
				else if(i == 15){
					float kernel_mode = atof(buffer)/100;
					printf("Kernel Mode: %lf seconds\n", kernel_mode);
				}
			}
		//signal catching
		if(signal(SIGINT, signal_handler) == SIG_ERR){
			printf("Error: Can't Catch Signal\n");
			exit(1);
		}
	
		sleep(1);
		}
	}
}

int main(int argc, char *argv[]){
	
	UserKernelMode(argv[1]);
}
