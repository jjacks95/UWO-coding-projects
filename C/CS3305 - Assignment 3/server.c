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
#include <netdb.h>
#include <sys/wait.h>
#include <signal.h>
#include <pthread.h>
#include <semaphore.h>
#include <sched.h>

#define MAX_MSG_SIZE 1024

//global vairables

//thread mutex
pthread_mutex_t mutex;
//connection queue
int* queue;
//connection count
int count_con = 0;
//file descriptor count
int count_fd = 0;


//handleRequest method
void *handleRequest(){
    
    int numbytes, num, i, product;
    
    //setting the receiving and sending buffers
    char recvBuff[MAX_MSG_SIZE], sendBuff[MAX_MSG_SIZE];
    
        //locking threads
        pthread_mutex_lock(&mutex);
    
        //check connections exits
        while (count_fd == 0) {
                sleep(1);
            }
    
            /*receive data from the client*/
            memset(recvBuff, '0',sizeof(recvBuff));
            memset(sendBuff, '0', sizeof(sendBuff));
    
            //receive data from client
            numbytes = recv(queue[count_con-count_fd],recvBuff,sizeof(recvBuff)-1,0);
                if (numbytes == -1){
                    perror("recv");
                    exit(1);
                }
            recvBuff[numbytes] = '\0';
            sscanf(recvBuff, "%d", &num);
            printf("Number Received: %d\n", num);
    
            //multiple the number received by 10
            product = num * 10;
    
            //send new product back to client
            snprintf(sendBuff, sizeof(sendBuff), "%d", product);
            send(queue[count_con-count_fd], sendBuff, strlen(sendBuff),0);
    
        //close connection decrement count and unlock threads
        close(queue[count_con-count_fd]);
        count_fd--;
        pthread_mutex_unlock(&mutex);
    
    pthread_exit(NULL);

}
int main(int argc, char* argv[]){
    
    //intialize vairables with command line arguments
    pthread_t t[atoi(argv[2])];
    int size = atoi(argv[3]);
    int threads = atoi(argv[2]);
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr;
    int rv, rc;
    /*Command line argument: port number*/
    
    
    //check for correct number of arguments
    if(argc != 4)
    {
        printf("\n Usage: %s port number, number of threads, size of connection array \n",argv[0]);
        return EXIT_FAILURE;
    }
    
    //malloc size of queue for connections
    queue = malloc(size * sizeof(queue[0]));
    /*Socket creation and binding*/

    //listen for incoming connections
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd <  0) {
      perror("Error in socket creation");
      exit(1);
    }
    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));
    
    //bind socket
    rv = bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (rv <  0) {
      perror("Error in binding");
      exit(1);
    }

    //initialize threads
    pthread_mutex_init(&mutex,NULL);
    
    //create number of threads specified by command line
    for (int i = 0; i < threads; i++)
    {
        
        rc = pthread_create(&t[i], NULL, handleRequest,(void *) NULL);
    
    }
    /*Accept connection and call the doProcessing function */
    listen(listenfd, 10);

    
    while(1)
    {
        //accept connections store the file descriptor and increment counts
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
        queue[count_con] = connfd;
        count_con++;
        count_fd++;
        sleep(1);

     }
    close(listenfd);

}
