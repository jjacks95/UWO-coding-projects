//
//
//  Created by Josh Jackson on 2015-11-05.
//
//
#include "../common/tcp_connect.h"
#include "../common/udp_connect.h"

static char msg[4096];

void listDir(char* path) {
    //initialize variables for function
    DIR* dir;
    struct dirent *ent;
    double value;
    char file_list[512];
    char ruby[1024];
    char tmp[1024];
    
    //opening directory path passed through function
	
    if ((dir = opendir(path)) != NULL)
    {
        //reading directory contents checking to see contents exist
        while ((ent = readdir(dir)) != NULL)
        {
            //bypassing directory ".."
            if (strcmp(ent->d_name, "..") !=0)
            {
                //and bypass directory "."
                if (ent->d_type == DT_DIR && strcmp(ent->d_name, ".") != 0)
                {
                    //formatting the path for printing
                    file_list[0]='\0';
                    strncat(file_list, path, sizeof(file_list)-1);
                    strncat(file_list, "/", sizeof(file_list)-1);
                    strncat(file_list, ent->d_name, sizeof(file_list)-1);
                    listDir(file_list);
                }
                
                if(ent->d_type != DT_DIR)
                {
                    //formatting the path for printing into file
                    file_list[0]='\0';
                    strncat(file_list, path, sizeof(file_list)-1);
                    strncat(file_list, "", sizeof(file_list)-1);
                    strncat(file_list, ent->d_name, sizeof(file_list)-1);
                    
                    //calling ruby file with system cmd
                    sprintf(ruby, "ruby ../common/crc32.rb %s", file_list);
                    
                    //open pipe to execute the ruby file
                    FILE *fp = popen(ruby, "r");
                    
                    fscanf(fp, "%lf", &value);
                    pclose(fp);
                    sprintf(tmp, "%s %.0f\n", file_list, value);
                    syslog(LOG_DEBUG, "* %s", tmp);
                    strcat(msg, tmp);
                   
                    
                }
            }
        }
        closedir(dir);
    }
}


void client(int argc, char** argv)
{
    /* Initializing Variables */
    char auth[1024];
    char buffer[4096];
    char buffer1[4096];
    char buffer2[4096];
    char tmpmsg[4096];
    //char tempmsg[4096];
    const char* server = "localhost";
    char* port = "9000";
    char* dir = "/vagrant/test/";   //"~/hooli";
    char* fserver = "localhost";
    char* fport = "10000";
    const char* username = argv[argc - 2];
    const char* password = argv[argc - 1];
    static int verbose_flag = 0;
    int count = 0;
    int c;
    int i;
    int retval;
    char** tokens2;
    //char** tokens3;
    //const char* checksum;
    //const char* filename;
    
	
    //while loop to read through all command line arguments using getopt long
    //setting the different options if used by client
    while ((argc-2) != 0)
    {
        count++;
        static struct option long_options[] =
        {
            {"verbose", no_argument, &verbose_flag, 1  },
            {"server", 	required_argument, 0, 		's'},
            {"port", 	required_argument, 0, 		'p'},
            {"dir", 	required_argument, 0, 		'd'},
            {"fserver", required_argument, 0,       'f'},
            {"fport",   required_argument, 0,       'o'},
            {0,0,0,0}
		};
        int option_index = 0;
        c = getopt_long(argc, argv, "vs:p:d:f:o:", long_options, &option_index);
        
        if (c == -1)
            break;
        
         //switch case to sort through arguments and set each one to the operation that follows
        switch(c) {
            case 'v':
                verbose_flag = 1;
                break;
                
            case 's':
                server = optarg;
                count++;
                break;
                
            case 'p':
                port = optarg;
                count++;
                break;
                
            case 'd':
                dir = optarg;
                count++;
                break;
            
            case 'f':
                fserver = optarg;
                count++;
                break;
            
            case 'o':
                fport = optarg;
                count++;
                break;
                
            case '?':
                // Error message already printed by getopt -- we'll just exit
                syslog(LOG_ERR, "EXIT FAILURE");
                exit(EXIT_FAILURE);
                break;
        }
    }
    
    //check if username and password were included
    if(argc - count != 2){
		syslog(LOG_WARNING, "Error! *Must include Username and Password at end of arg*");
        exit(EXIT_FAILURE);
    }
    
	syslog(LOG_INFO, "Scanning Directory : %s\n", dir);
    //call list dir function
    listDir(dir);

    // Buffer to store received message, leaving
    strcat(auth, msg);
    
	// space for the NULL terminator
    // Connect to the server
	syslog(LOG_INFO, "Connecting to Server: %s",server);
    struct addrinfo* results = get_sockaddr(server, port);
    
    //open connection
    int sockfd = open_connection(results);
    
    //put username and pasword into auth array
	sprintf(auth,"%s,%s",username, password);

    //send auth to server to be authenticated
	syslog(LOG_DEBUG,"Sending credentials");
    
    if (send(sockfd, auth, strlen(auth), 0) == -1){
        err(EXIT_FAILURE, "%s", "Unable to send AUTH");
    }else
        send(sockfd, auth, strlen(auth), 0);
    
    int bytes_read = recv(sockfd, buffer, sizeof(buffer)-1, 0);
    if (bytes_read == -1){
        err(EXIT_FAILURE, "%s", "Unable to read");
    }else
        syslog(LOG_INFO,"%s", buffer);
    
    if (strcmp(buffer, "401 Unauthorized\n") == 0) {
        //exit(EXIT_FAILURE);
    }
    
    //send file list to server to be compared to hooli db
	//Sending the file list contained in msg
    syslog(LOG_INFO, "Uploading file list");
    
    syslog(LOG_INFO, "%s", buffer1);
    
    if (send(sockfd, buffer1, strlen(buffer1), 0) == -1){
        err(EXIT_FAILURE, "%s", "Unable to send");
    }
    
    //receiving files that need to be updated or added to hdb
    syslog(LOG_INFO, "Files Requested by Server:");
    recv(sockfd, buffer2, sizeof(buffer2)-1, 0);
    
    bytes_read = recv(sockfd, buffer2, sizeof(buffer2)-1, 0);
    if (bytes_read == -1)
        err(EXIT_FAILURE, "%s", "Unable to read");
    

    // Add the terminating NULL character to the end and print it
    syslog(LOG_INFO, "%s", buffer2);
    strcat(tmpmsg, buffer2);
    buffer2[bytes_read] = '\0';


	// Close the connection
    syslog(LOG_INFO, "Connection Terminated with Hooli Metadata Server");
    close(sockfd);
    
    // Connect to the Hoolie File Server
    
    host server1;   // Server address
    message* msg;  // Message to send/receive
    
    // Create a socket for communication with the server
    sockfd = create_client_socket(fserver, fport, &server1);
    
    // Create a message, and initialize its contents
    msg = create_message();
    printf("Buffer 2: %s\n\n\n\n\n", tmpmsg);
    //setting tokens2 to every line sent from client
    tokens2 = str_split(buffer2, '\n');
    printf("Token 0: %s\n", tokens2[0]);
    printf("Token 1: %s\n", tokens2[1]);
    printf("Token 2: %s\n", tokens2[2]);


    //Prepare a clean message
    strcpy(buffer2, "");
    
    printf("HELLO3\n");
    
    i = 0;
    
    while (*(tokens2 + i) != NULL) {
        //Tokenize the line to get filename and checksum separated by a space
        //tokens3 = str_split(*(tokens2 + i), ' ');
        i++;
        
        //set filename and checksum
        //filename = *(tokens3 + 0);
        //checksum = *(tokens3 + 1);
        
        //Send file to Hoolie File Server????
        msg->length = strlen("0");
        memcpy(msg->buffer, "0", msg->length);
        retval = send_message(sockfd, msg, &server1);
        free(msg);
        if (retval == -1)
        {
            close(sockfd);
            perror("Unable to send to socket");
            exit(EXIT_FAILURE);
        }
        // Read the server's reply
        msg = receive_message(sockfd, &server1);
        
        if (msg != NULL)
        {
            // Add NULL terminator and print reply
            msg->buffer[msg->length] = '\0';
            printf("Reply from server %s: %s\n", server1.friendly_ip, msg->buffer);
            // Free the memory allocated to the message
            free(msg);
        }
        //this is where we will send file
        
    }
    
    
    
    msg->length = strlen("1");
    memcpy(msg->buffer, "1", msg->length);
    
    // Send the message to the server, and free its memory
    retval = send_message(sockfd, msg, &server1);
    free(msg);
    // If we couldn't send the message, exit the program
   
    if (retval == -1)
    {
        close(sockfd);
        perror("Unable to send to socket");
        exit(EXIT_FAILURE);
    }
    // Read the server's reply
    msg = receive_message(sockfd, &server1);
    
    if (msg != NULL)
    {
        // Add NULL terminator and print reply
        msg->buffer[msg->length] = '\0';
        printf("Reply from server %s: %s\n", server1.friendly_ip, msg->buffer);
        // Free the memory allocated to the message
        free(msg); }
    
    
    // Close the socket
    syslog(LOG_INFO, "Connection Terminated with Hooli File Server");
    close(sockfd);
    exit(EXIT_SUCCESS);
    
    
 //Close connection to Hoolie File Server

}

int main(int argc, char** argv){

    //opening log file calling function and closing log file in main method
    openlog("client", LOG_PERROR | LOG_PID | LOG_NDELAY, LOG_USER);
    client(argc, argv);
    closelog();

}
