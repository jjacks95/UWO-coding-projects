#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>
#include <syslog.h>

#define LOG_EMERG   0 /* system is unusable */ 
#define LOG_ALERT   1 /* action must be taken immediately */ 
#define LOG_CRIT    2 /* critical conditions */ 
#define LOG_ERR     3 /* error conditions */ 
#define LOG_WARNING 4 /* warning conditions */ 
#define LOG_NOTICE  5 /* normal but significant condition */ 
#define LOG_INFO    6 /* informational */ 
#define LOG_DEBUG   7 /* debug-level messages */

void client(int argc, char** argv)
{
    int c;
    
    char* log_filename = NULL;
	char* HOSTNAME = "localhost";
	char* PORT = "9000";
	char* DIR = "~/hooli";
	char* USERNAME = argv[argc - 2];
	char* PASSWORD = argv[argc -1];
	static int verbose_flag = 0;
	int count = 0;
	while (1)
	{    
		count++;
		static struct option long_options[] = 
		{
			{"verbose", no_argument, &verbose_flag, 1  },
			{"log", 	required_argument, 0, 		'l'},
			{"server", 	required_argument, 0, 		's'},
			{"port", 	required_argument, 0, 		'p'},
			{"dir", 	required_argument, 0, 		'd'},
			{0,0,0,0}
			
		};
	int option_index = 0;
    c = getopt_long(argc, argv, "vl:s:p:d:", long_options, &option_index);
		
		if (c == -1)
			break;
		
        switch(c) {
            case 'v':
                verbose_flag = 1;  
				syslog(LOG_INFO, "Verbose is active");
                break;
				
            case 'l':
                log_filename = optarg;
				syslog(LOG_INFO, "Log: %s", log_filename);
				count++;
                break;
				
			case 's':
				HOSTNAME = optarg;
				syslog(LOG_INFO, "Server: %s", HOSTNAME);
				count++;
				break;
			
			case 'p':
				PORT = optarg;
				syslog(LOG_INFO, "Port: %s", PORT);
				count++;
				break;
				
			case 'd':
				DIR = optarg;
				syslog(LOG_INFO, "Directory: %s", DIR);
				count++;
				break;
				
				
            case '?':
                // Error message already printed by getopt -- we'll just exit
				syslog(LOG_ERR, "EXIT FAILURE");
                exit(EXIT_FAILURE);
                break;
			} 
		}
		
    syslog(LOG_INFO, "Verbose 	: %s\n", verbose_flag ? "true" : "false");
    syslog(LOG_INFO, "Log     	: %s\n", log_filename);
	syslog(LOG_INFO, "Port		: %s\n", PORT);
	syslog(LOG_INFO, "Server	: %s\n", HOSTNAME);
	syslog(LOG_INFO, "Directory	: %s\n", DIR);
	//printf("Count		: %d\n", count);
	//printf("Arg		: %d\n", argc);

	if(argc - count == 2){
		syslog(LOG_INFO, "Username: %s and Password: %s", USERNAME, PASSWORD);
		
	
	}else
	{
		syslog(LOG_WARNING, "Error! *Must include Username and Password at end of arg*");
	}
}
int main(int argc, char** argv){
	openlog("cs3357",LOG_PERROR | LOG_PID | LOG_NDELAY, LOG_USER);
	client(argc, argv);
	closelog();
}