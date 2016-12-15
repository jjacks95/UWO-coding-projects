//
//  udp_connect.c
//  
//
//  Created by Josh Jackson on 2015-11-25.
//
//

#include "udp_connect.h"

struct addrinfo* get_udp_sockaddr(const char* node, const char* port, int flags)
{
    struct addrinfo hints;
    struct addrinfo* results;
    int retval;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;      // Return socket addresses for our local IPv4 addresses
    hints.ai_socktype = SOCK_DGRAM; // Return UDP socket addresses
    hints.ai_flags = flags;         // Socket addresses should be listening sockets
    retval = getaddrinfo(node, port, &hints, &results);
    if (retval != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(retval));
        exit(EXIT_FAILURE);
    }
    return results;
}

int bind_socket(struct addrinfo* addr_list){
    
 struct addrinfo* addr;
 int sockfd;
 // Iterate over the addresses in the list;
 //stop when we successfully bind to one
 
    for (addr = addr_list; addr != NULL; addr = addr->ai_next){
        // Open a socket
        sockfd = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
        // Move on to the next address if we couldn't open a socket
            if (sockfd == -1)
                continue;
        // Try to bind the socket to the address/port
        if (bind(sockfd, addr->ai_addr, addr->ai_addrlen) == -1){
            // If binding fails, close the socket, and move on to the next address
            close(sockfd);
            continue;
        }
        else{
            // Otherwise, we've bound the address to the socket, so stop processing
            break;
        }
    }
 
    // Free the memory allocated to the address list
    freeaddrinfo(addr_list);
    
    // If addr is NULL, we tried every address and weren't able to bind to any
    if (addr == NULL){
        err(EXIT_FAILURE, "%s", "Unable to bind");
    }
    else{
        // Otherwise, return the socket descriptor
        return sockfd;
    }

}

int create_server_socket(char* port){
    
    struct addrinfo* results = get_udp_sockaddr(NULL, port, AI_PASSIVE);
    int sockfd = bind_socket(results);
    return sockfd;
}



message* create_message(){
    
    return (message*)malloc(sizeof(message));
}


message* receive_message(int sockfd, host* source){
    
    message* msg = create_message();
    
    // Length of the remote IP structure
    source->addr_len = sizeof(source->addr);
    
    // Read message, storing its contents in msg->buffer, and
    // the source address in source->addr
    msg->length = recvfrom(sockfd, msg->buffer, sizeof(msg->buffer), 0,(struct sockaddr*)&source->addr,&source->addr_len);
    
    // If a message was read
    if (msg->length > 0)
    {
        // Convert the source address to a human-readable form,
        // storing it in source->friendly_ip
        inet_ntop(source->addr.sin_family, &source->addr.sin_addr,
                  source->friendly_ip, sizeof(source->friendly_ip));
        // Return the message received
        return msg;
    
    }else {
        // Otherwise, free the allocated memory and return NULL
        free(msg);
        return NULL;
    }
}


int send_message(int sockfd, message* msg, host* dest){
    
    return sendto(sockfd, msg->buffer, msg->length, 0, (struct sockaddr*)&dest->addr, dest->addr_len);
}


int create_client_socket(char* hostname, char* port, host* server){
    
    int sockfd;
    struct addrinfo* addr;
    struct addrinfo* results = get_udp_sockaddr(hostname, port, 0);
    // Iterate through each addrinfo in the list;
    // stop when we successfully create a socket
    
    for (addr = results; addr != NULL; addr = addr->ai_next)
    {
        // Open a socket
        sockfd = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
        
        // Try the next address if we couldn't open a socket
        if (sockfd == -1)
            continue;
        
        // Copy server address and length to the out parameter 'server'
        memcpy(&server->addr, addr->ai_addr, addr->ai_addrlen);
        memcpy(&server->addr_len, &addr->ai_addrlen, sizeof(addr->ai_addrlen));
        
        // We've successfully created a socket; stop iterating
        break;
    }

    // Free the memory allocated to the addrinfo list
    freeaddrinfo(results);
    // If we tried every addrinfo and failed to create a socket
    if (addr == NULL)
    {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }
    else {
        // Otherwise, return the socket descriptor
        return sockfd;
    }
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




