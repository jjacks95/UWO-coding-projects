//
//  hftpd.c
//  
//
//  Created by Josh Jackson on 2015-11-25.
//
//
//#include "../common/tcp_connect.h"
#include "../common/udp_connect.h"

void file_server(int argc, char** argv){
    
    /*Initializing Variables*/
    int c;
    //const char* dir = "/tmp/hftpd";
    char* port = "10000";
    //const char* timewait = "10";
    static int verbose_flag = 0;
    char buffer[4096];
    
    //while loop to read through all command line arguments using getopt long
    //setting the different options used by server
    while (argc > 0)
    {
        static struct option long_options[] =
        {
            {"verbose",     no_argument, &verbose_flag, 1  },
           // {"dir",        required_argument, 0, 		'd'},
            {"port",        required_argument, 0, 		'p'},
           // {"timewait",    required_argument, 0,       't'},
            {0,0,0,0}
            
        };
        int option_index = 0;
        c = getopt_long(argc, argv, "vs:p:d:t:", long_options, &option_index);
        
        if (c == -1)
            break;
        //switch case to sort through arguments and set each one to the operation that follows
        switch(c) {
            case 'v':
                verbose_flag = 1;
                break;
            
            case 'p':
                port = optarg;
                break;
            /**
            case 'r':
                root = optarg;
                break;
            
            case 't':
                timewait = optarg;
                break;
            */
                
            case '?':
                // Error message already printed by getopt -- we'll just exit
                syslog(LOG_ERR, "EXIT FAILURE");
                exit(EXIT_FAILURE);
                break;
        }
    }
    
    
    
    //UDP communication
    
    //int bytes_read;                                 // Number of Bytes Read
   // char buffer[65535];                             // Buffer to store incoming message
    char ip_address[INET_ADDRSTRLEN];               // Buffer to store human-readable source IP address
    struct sockaddr_in addr;                        // Source address and port
    //socklen_t addr_len = sizeof(struct sockaddr_in);// Length of the addr structure
    host source;                                    // Server address
    message* msg;                                   // Message to send/receive
    

    // Create a socket to listen on port
    int sockfd = create_server_socket(port);
    syslog(LOG_INFO, "Listening on Port: %s", port);
    
    // Read the next message into buffer, storing the source address in addr
    //bytes_read = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr, &addr_len);
    
    msg = create_message();
    
    // Convert the source address to a human-readable IP address
    //inet_ntop(addr.sin_family, &addr.sin_addr, ip_address, sizeof(ip_address));
    //syslog(LOG_INFO, "Connected to: %s", ip_address);
    
    int flag = 0;
    
    while(flag == 0){
    msg = receive_message(sockfd, &source);
        
        // Convert the source address to a human-readable IP address
        inet_ntop(addr.sin_family, &addr.sin_addr, ip_address, sizeof(ip_address));
        syslog(LOG_INFO, "Connected to: %s", ip_address);
        
    sprintf(buffer, "%s", msg->buffer);
    
    if (strcmp(buffer, "1") == 0) {
        flag = 1;
        break;
    }
        
    if (msg != NULL)
    {
        // Add NULL terminator and print reply
        msg->buffer[msg->length] = '\0';
        printf("Reply from server %s: %s\n", source.friendly_ip, msg->buffer);
        
        // Free the memory allocated to the message
        free(msg);
    }
    
    // Read the next message
    // Echo the message back to the client
    if(send_message(sockfd, msg, &source) == -1)
        {
        free(msg);
        perror("Unable to send to socket");
        exit(EXIT_FAILURE);
        }
    }//end of while loop
    
   
    if(send_message(sockfd, msg, &source) == -1)
    {
        free(msg);
        perror("Unable to send to socket");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close(sockfd);
    exit(EXIT_SUCCESS);
    
}

int main(int argc, char** argv){
    //opening log file calling function and closing log file in main method
    openlog("hftpd",LOG_PERROR | LOG_PID | LOG_NDELAY, LOG_USER);
    file_server(argc, argv);
    closelog();
}