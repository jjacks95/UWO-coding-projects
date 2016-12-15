//
//  tcp_connect.c
//
//
//  Created by Josh Jackson on 2015-11-05.
//
//
#include "../common/tcp_connects.h"



void server(int argc, char** argv)
{
    /*Initializing Variables*/
    int c;
    const char* hostname = "localhost";
    char* port = "9000";
    static int verbose_flag = 0;
    int count = 0;
    
    //while loop to read through all command line arguments using getopt long
    //setting the different options used by server
    while (argc > 0)
    {
        count++;
        static struct option long_options[] =
        {
            {"verbose", no_argument, &verbose_flag, 1  },
            {"server", 	required_argument, 0, 		's'},
            {"port", 	required_argument, 0, 		'p'},
            {0,0,0,0}
            
        };
        int option_index = 0;
        c = getopt_long(argc, argv, "vs:p:", long_options, &option_index);
        
        if (c == -1)
            break;
        //switch case to sort through arguments and set each one to the operation that follows
        switch(c) {
            case 'v':
                verbose_flag = 1;
                break;
        
            case 's':
                hostname = optarg;
                count++;
                break;
                
            case 'p':
                port = optarg;
                count++;
                break;
                
                
            case '?':
                // Error message already printed by getopt -- we'll just exit
                syslog(LOG_ERR, "EXIT FAILURE");
                exit(EXIT_FAILURE);
                break;
        }
    }
    // We want to listen on the port specified on the command line
    struct addrinfo* results = get_server_sockaddr(port);
    
    // Create a listening socket
    int sockfd = bind_socket(results);
    
    // Start listening on the socket
    if (listen(sockfd, BACKLOG) == -1)
        err(EXIT_FAILURE, "%s", "Unable to listen on socket");
    
    // Wait for a connection and handle it
	syslog(LOG_INFO, "Server listening on port %s\n",port);
    int connectionfd = wait_for_connection(sockfd);
	handle_connection(connectionfd, hostname);
    

    // Close the socket and exit
	syslog(LOG_INFO, "Connection Terminated\n");
    
    close(sockfd);
    exit(EXIT_SUCCESS);
    
}
int main(int argc, char** argv){
    
    //opening log file calling function and closing log file in main method
    openlog("hmds",LOG_PERROR | LOG_PID | LOG_NDELAY, LOG_USER);
    server(argc, argv);
    closelog();
}
