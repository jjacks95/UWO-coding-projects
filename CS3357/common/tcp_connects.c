//
//  tcp_connect.c
//
//
//  Created by Josh Jackson on 2015-11-05.
//
//
#include "tcp_connects.h"



struct addrinfo* get_sockaddr(const char* hostname, const char* port){
    
    struct addrinfo hints;
    struct addrinfo* results;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    // Return socket addresses for the server's IPv4 addresses
    hints.ai_socktype = SOCK_STREAM;
    // Return TCP socket addresses
    int retval = getaddrinfo(NULL, port, &hints, &results);
    if (retval)
        errx(EXIT_FAILURE, "%s", gai_strerror(retval));
    return results;
}

struct addrinfo* get_server_sockaddr(const char* port){
    
    struct addrinfo hints;
    struct addrinfo* results;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    // Return socket addresses for our local IPv4 addresses
    hints.ai_socktype = SOCK_STREAM;
    // Return TCP socket addresses
    hints.ai_flags = AI_PASSIVE;
    // Socket addresses should be for listening sockets
    int retval = getaddrinfo(NULL, port, &hints, &results);
    if (retval)
        errx(EXIT_FAILURE, "%s", gai_strerror(retval));
    return results;
}

int bind_socket(struct addrinfo* addr_list){
    
    struct addrinfo* addr;
    int sockfd;
    // Iterate over the addresses in the list;
    //stop when we successfully bind to one
    for (addr = addr_list; addr != NULL; addr = addr->ai_next)
    {
        // Open a socket
        sockfd = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
        // Move on to the next address if we couldn't open a socket
        if (sockfd == -1)
            continue;
        // Try to bind the socket to the address/port
        if (bind(sockfd, addr->ai_addr, addr->ai_addrlen) == -1)
        {
            // If binding fails, close the socket, and move on to the next address
            close(sockfd);
            continue;
        }
        else
        {
            // Otherwise, we've bound the address to the socket, so stop processing
            break;
        }
    }
    // Free the memory allocated to the address list
    freeaddrinfo(addr_list);
    // If addr is NULL, we tried every address and weren't able to bind to any
    if (addr == NULL)
    {
        err(EXIT_FAILURE, "%s", "Unable to bind");
    }
    else
    {
        // Otherwise, return the socket descriptor
        return sockfd;
    }
}

int wait_for_connection(int sockfd){
    
    struct sockaddr_in client_addr;
    // Remote IP that is connecting to us
    unsigned int addr_len = sizeof(struct sockaddr_in);
    // Length of the remote IP structure
    char ip_address[INET_ADDRSTRLEN];
    // Buffer to store human-friendly IP address
    int connectionfd;
    // Socket file descriptor for the new connection
    // Wait for a new connection
    connectionfd = accept(sockfd, (struct sockaddr*)&client_addr, &addr_len);
    // Make sure the connection was established successfully
    if (connectionfd == -1)
        err(EXIT_FAILURE, "%s", "Unable to accept connection");
    // Convert the connecting IP to a human-friendly form and print it
    inet_ntop(client_addr.sin_family, &client_addr.sin_addr, ip_address, sizeof(ip_address));
    
    
    syslog(LOG_INFO, "Incoming connection from %s\n", ip_address);
    
    return connectionfd;
    
}

void handle_connection(int connectionfd, const char* hostname){
    /*Initializing Variables*/
    char buffer1[4096];
    char buffer2[4096];
    char buffer3[4096];
    char tempmsg[4096];
    bool exists;
    int bytes_read;
    int i;
    char** tokens;
    char** tokens2;
    char** tokens3;
    const char* username;
    const char* password;
    const char* value;
    const char* verify;
    const char* checksum;
    const char* filename;
    
    //establishing a open temporary hdb connection
    hdb_connection* tmp;
    tmp = hdb_connect(hostname);
    
    //user authentication
    do {
        // Read up to 4095 bytes from the client
        bytes_read = recv(connectionfd, buffer1, sizeof(buffer1)-1, 0);
        
        // If the data was read successfully
        if (bytes_read > 0){
            
            // Add a terminating NULL character and print the message received
            buffer1[bytes_read] = '\0';
            // printf("Message received (%d bytes): %s\n", bytes_read, buffer1);
            tokens = str_split(buffer1, ',');
            
            //set user name and password to received bytes split by str_split
            username = *(tokens + 0);
            password = *(tokens + 1);
            //print user name in syslog
            syslog(LOG_INFO, "Username: %s", username);
            
            free(tokens);
            //setting user exists, authenticate, and verify token's return value to variables
            hdb_authenticate(tmp, "josh", "password");
            exists = hdb_user_exists(tmp, username);
            value = hdb_authenticate(tmp, username, password);
            verify = hdb_verify_token(tmp, value);
            
            if(exists == false){
                
                //if user does not exist
                strcpy(buffer1, "401 Unauthorized\n");
                syslog(LOG_ERR, "Authentication Failed. User: %s does not exist", username);
                send(connectionfd, buffer1, sizeof(buffer1)-1, 0);
                //exit(EXIT_FAILURE);
            }else{
                
                //if hdb_authenticate returns anything but NULL
                if (value != NULL) {
                    //print the token and user into syslog
                    syslog(LOG_INFO, "TOKEN is %s, for user: %s\n", value, username);
                }
                else{
                    //else print user unauthroized
                    syslog(LOG_ERR,"User Unauthorized\n\n\n");
                    //exit(EXIT_FAILURE);
                }
                
                if(strcmp(username, verify) == 0){
                    
                    //compare the result from hdb_verify and username if equal
                    //print Authentication Successful and send client HMDP response
                    syslog(LOG_INFO,"Authentication Successful");
                    sprintf(buffer1, "200 Authentication Successful\n              Token: %s\n\n", value);
                    send(connectionfd, buffer1, sizeof(buffer1)-1, 0);
                    
                
                }else{
                    //else print Unauthorized, and send HMDP response
                    syslog(LOG_INFO, "Unauthorized User");
                    sprintf(buffer1, "401 Unauthorized\n");
                    
                }
            }
            
            
            // Echo the data back to the client; exit loop if we're unable to send
            if (send(connectionfd, buffer1, sizeof(buffer1)-1, 0) == -1)
            {
                warn("Unable to send data to client");
                syslog(LOG_ERR, "Unable to send data to client");
                break;
            }
       }
    
        //file checking
        //receive files from client
        recv(connectionfd, buffer2, sizeof(buffer2)-1, 0);
        if (bytes_read > 0){
            // Add a terminating NULL character and print the message received
            buffer2[bytes_read] = '\0';
            
            recv(connectionfd, buffer2, sizeof(buffer2)-1, 0);
            bytes_read = sizeof(buffer2);
            
            syslog(LOG_DEBUG,"Receiving file list");
            printf("%s\n", buffer2);
            //checking if buffer is empty to return proper response
            if (buffer2 == 0) {
                sprintf(tempmsg, "204 No Files Requested\n\n");
                exit(EXIT_SUCCESS);
                break;
            }
            //setting tokens2 to every line sent from client
            tokens2 = str_split(buffer2, '\n');

            //start temporary message with files requested response
            sprintf(tempmsg,"\n302 Files Requested\nLength: %d\n\n", strlen(buffer2));
            
            
            //Prepare a clean message
            strcpy(buffer2, "");
            i = 0;
            while (*(tokens2 + i) != NULL) {
                //Tokenize the line to get filename and checksum separated by a space
                tokens3 = str_split(*(tokens2 + i), ' ');
                i++;
                
                //set filename and checksum
                filename = *(tokens3 + 0);
                checksum = *(tokens3 + 1);
                
                //check if file exists in hdb
                if(hdb_file_exists(tmp, username, filename) == false)
                {
                    syslog(LOG_INFO, "File: %s, does not exist", filename);
                    //if file does not exist add to the temp list for response
                    char str[1024];
                    sprintf(str,"%s\n", filename);
                    strcat(tempmsg, str);
                    
                //if file exists check if checksum is equal
                //if checksum is equal we know the file was never changed
                //and does not need to be added to list
                }else if((int *) hdb_file_checksum(tmp, username, filename) != (int *) atol(checksum)){
                    
                    //if checksum is not equal add file to list as modified and needs to be updated
                    syslog(LOG_INFO, "File: %s, has been modified", filename);
                    char str[1024];
                    sprintf(str,"%s\n",filename);
                    strcat(tempmsg, str);
                }else{
                    syslog(LOG_INFO, "No files have been modified, or added");
                }
            }
        }
        //Add file information onto the message
        strcat(buffer3, tempmsg);
        printf("%s", buffer3);
            // Echo the data back to the client; exit loop if we're unable to send
            if (send(connectionfd, buffer3, bytes_read, 0) == -1){
                    warn("Unable to send data to client");
                    
            }
                send(connectionfd, buffer3, bytes_read, 0);
        
        bytes_read = 0;
    }   while(bytes_read > 0);
    
    // Close the connection
    hdb_disconnect(tmp);
    close(connectionfd);
}

                         
                         
                         
int open_connection(struct addrinfo* addr_list){
    
    struct addrinfo* addr;
    int sockfd;
    // Iterate through each addrinfo in the list; stop when we successfully
    // connect to one
    for (addr = addr_list; addr != NULL; addr = addr->ai_next)
    {
        // Open a socket
        sockfd = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
         // Try the next address if we couldn't open a socket
         if (sockfd == -1)
             continue;
         // Stop iterating if we're able to connect to the server
         if (connect(sockfd, addr->ai_addr, addr->ai_addrlen) != -1)
             break; }
     // Free the memory allocated to the addrinfo list
     freeaddrinfo(addr_list);
     
     if (addr == NULL)
         err(EXIT_FAILURE, "%s", "Unable to connect");
     else
         return sockfd;
}
 
                         
char** str_split(char* str, const char split){
    //string split function is used to break down strings at different character or signs specified
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = str;
    char* last_comma = 0;
    char split_str[2];
    split_str[0] = split;
    split_str[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp){
        if (split == *tmp){
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (str + strlen(str) - 1);

    /* Add space for terminating null string so caller
     knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result){
        size_t x  = 0;
        char* token = strtok(str, split_str);

        while (token){
            assert(x < count);
            *(result + x++) = strdup(token);
            token = strtok(0, split_str);
        }
        assert(x == count - 1);
        *(result + x) = 0;
    }

return result;
}
                         
