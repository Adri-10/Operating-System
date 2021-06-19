#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
    int n,pipeDC1[2], pipeDC2[2];
    char *message;

    if(pipe(pipeDC1) == -1) {
            printf("Finding Error in Pipe Descriptor 1\n");
            exit(1);
    }

    if(pipe(pipeDC2) == -1) {
            printf("inding Error in Pipe Descriptor 2\n");
            exit(1);
    }

    pid_t pid = fork();

    if(pid < 0) {
    	printf("Failed to create child\n");
    	return 1;
    }
    if(pid == 0) {
    	close(pipeDC1[0]);
    	printf("Inside child process %d\n",(int)getpid());


        printf("Enter the integer number: ");
        scanf("%d", &n);
        printf("\nSending to the parent...\n");
        write(pipeDC1[1], &n, sizeof(n));
        close(pipeDC1[1]);

        wait(NULL);

        printf("Inside child process %d\n", (int)getpid());
        close(pipeDC2[1]);

        char *result = calloc(256, 4);

        read(pipeDC2[0], result, sizeof(result));
        printf("Received result: %d is an %s number\n", n, result);
        close(pipeDC2[0]);


        printf("Child Terminated\n");
        exit(1);
    }
    else {
    	sleep(5);
    	close(pipeDC1[1]);

    	printf("Inside parent process %d\n", (int)getpid());

    	read(pipeDC1[0], &n, sizeof(n));

    	printf("Received result: %d\n", n);
    	close(pipeDC1[0]);


    	if(n%2!= 0) {
    		message = "odd ";
    	}
    	else {
    		message = "even ";
    	}

    	close(pipeDC2[0]);
    	printf("\nSending result to the child...\n");
    	write(pipeDC2[1], message, sizeof(message));
    	close(pipeDC2[1]);

    	wait(NULL);
    	printf("Parent terminated\n");
    }

    return 0;
}
