#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

int count=0;
//pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
sem_t mutex;
void* print(void* arg)
{

  printf(" Thread ID: %ld \n",pthread_self());
  //pthread_mutex_lock( &mutex1 );
  sem_wait(&mutex);
  for(int i=0;i<30;i++)
  {
    count= count+1;
  printf("\n Thread %ld and count %d\n",pthread_self(), count);
  }
 // pthread_mutex_unlock( &mutex1 );
 sem_post(&mutex);
  printf("\n %ld is finished \n",pthread_self());
}
int main()
{

 pthread_t tid1[3],tid2;
  int iter1,iter2;
  int input  ;
  char *input1="Thread 2";

  sem_init(&mutex,0,2);
  for(int i=0;i<2;i++){
  input =i+1;
  iter1=pthread_create(&tid1[i],NULL, print, &input);
  }
  // iter2=pthread_create(&tid2,NULL, print, (void *) input1);
  for(int i=0;i<3;i++)
   pthread_join(tid1[i],NULL);
  //pthread_join(tid2,NULL);
  //sem_destroy(&mutex);

 return 0;
}
