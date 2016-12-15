#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 

#define MAX_MSG_SIZE 1024

/*
 * This function receives receives two numbers from the client and sends the sum back
 */

void doProcessing (int connfd)
{
  int numbytes;
  char recvBuff[MAX_MSG_SIZE], sendBuff[MAX_MSG_SIZE];
  time_t ticks; 
  int a, b, sum;
  int rv;

  memset(recvBuff, '0',sizeof(recvBuff));
  memset(sendBuff, '0', sizeof(sendBuff)); 
 
  /*receive data from the client*/
  numbytes = recv(connfd,recvBuff,sizeof(recvBuff)-1,0);
  if (numbytes == -1){
       perror("recv");
       exit(1);
  }
  recvBuff[numbytes] = '\0';

  /*Extract the two numbers */
  sscanf(recvBuff, "%d %d", &a,&b);

  sum = a + b;

  snprintf(sendBuff, sizeof(sendBuff), "%d", sum);
  send(connfd, sendBuff, strlen(sendBuff),0); 

  close(connfd);
}

int main(int argc, char *argv[])
{
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr; 
    int rv;

    /*Command line argument: port number*/

    if(argc != 2)
    {
        printf("\n Usage: %s port \n",argv[0]);
        return 1;
    }

    /*Socket creation and binding*/

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd <  0) {
      perror("Error in socket creation");
      exit(1);
    }
    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1])); 

    rv = bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 
    if (rv <  0) {
      perror("Error in binding");
      exit(1);
    }


    listen(listenfd, 10); 

    /*Accept connection and call the doProcessing function */

    while(1)
    {
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 
        doProcessing(connfd);
        sleep(1);
     }
}
