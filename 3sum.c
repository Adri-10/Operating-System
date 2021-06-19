#include <stdio.h>
#include <pthread.h>
#include<stdlib.h>
#include<unistd.h>
int sum=0;
void *runner(void *no)
{
    int *number,i;
    number=(int*)no;

    for(i=1;i<=*number;i++)
    {
        sum=sum + i;
    }
   // pthread_exit(NULL);
}


 int main()
{
    int n;
     pthread_t tid [2];
     //pthread_attr_t attr[2];
    printf("Enter Number Up to Which You want to Sum :");
    scanf("%d",&n);
    int i,rc;
    for(i=0; i<2; i++){
    //printf("Creating thread %d\n",i);
    rc = pthread_create(&tid[i],NULL,runner,(void *)&n);
     pthread_join(tid[i], NULL);
     printf("Sum of thread %d is: %d \n",i,sum);
    if (rc!=0)
        {
            printf("ERROR! return code from pthread_create() is %d\n", rc);

            //exit(NULL);

        }
    }
   printf("\n");
   printf("Final Sum by 2 thread is : %d \n",sum);
  // return 0;
}
