#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>


int main() {
    pid_t pid = fork();
    if(pid<0){
       printf("fork failed\n");
    }
    
    else if(pid>0){ 
        wait(NULL);
        printf("Hello Child! My childid is %d\n", getpid());
    }
       
    else{ 
        printf("Hello Parent! My parentid is %d\n", getppid());
        exit(0);
    }
    return 0;
}
