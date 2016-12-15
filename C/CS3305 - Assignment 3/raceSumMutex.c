#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <pthread.h>
#include <semaphore.h>
#include <sched.h>


pthread_mutex_t mutex;

long long sum = 0;
long N;

void *requestHandler()
{

   int i;
  

   for (i=0; i < N+1; i++)
   {
     pthread_mutex_lock(&mutex);
       sum = sum + i;
     pthread_mutex_unlock(&mutex);
   }
  pthread_exit(NULL);
}

int main(int argc, char* argv[])
{


  pthread_t t1,t2;
  int rc1,rc2;

  N = atoi(argv[1]);

  pthread_mutex_init(&mutex,NULL);

  rc1 = pthread_create(&t1,NULL,requestHandler, (void *) NULL);
  rc2 = pthread_create(&t2,NULL,requestHandler, (void *) NULL);
  
  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  printf("sum is %lld\n", sum);
  pthread_exit(NULL);
}
