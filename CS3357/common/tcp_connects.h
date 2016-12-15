//
//  tcp_connect.h
//  
//
//  Created by Josh Jackson on 2015-11-05.
//
//
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>
#include <string.h>
#include <syslog.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <err.h>
#include <dirent.h>
#include <unistd.h>
#include <assert.h>
#include <hdb.h>
#include <hfs.h>

#define LOG_EMERG   0 /* system is unusable */
#define LOG_ALERT   1 /* action must be taken immediately */
#define LOG_CRIT    2 /* critical conditions */
#define LOG_ERR     3 /* error conditions */
#define LOG_WARNING 4 /* warning conditions */
#define LOG_NOTICE  5 /* normal but significant condition */
#define LOG_INFO    6 /* informational */
#define LOG_DEBUG   7 /* debug-level messages */
#define BACKLOG     25
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
struct addrinfo* get_sockaddr(const char* hostname, const char* port);

struct addrinfo* get_server_sockaddr(const char* port);

int bind_socket(struct addrinfo* addr_list);

int wait_for_connection(int sockfd);

void handle_connection(int connectionfd, const char* hostname);

int open_connection(struct addrinfo* addr_list);

char** str_split(char* a_str, const char a_delim);



