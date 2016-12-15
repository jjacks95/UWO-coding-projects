//
//  tcp_connect.c
//  
//
//  Created by Josh Jackson on 2015-11-05.
//
//
#include "tcp_connect.h"



struct addrinfo* get_sockaddr(const char* hostname, const char* port)
{
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

struct addrinfo* get_server_sockaddr(const char* port)
{
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

/**
int bind_socket(struct addrinfo* addr_list)
{
    struct addrinfo* addr;
    int sockfd;
    // Iterate over the addresses in the list; stop when we successfully bind to one
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
*/
int wait_for_connection(int sockfd)
{
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
    
    
    printf("Connection accepted from %s\n", ip_address);
    
    return connectionfd;

}


int open_connection(struct addrinfo* addr_list)
{
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
