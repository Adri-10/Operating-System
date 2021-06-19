#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>


int main(int argc, char *argv[]){
    if(argc!=2){
        printf("Invalid number of arguments.\n");
        printf("Usage: PROG_NAME FILE_NAME\n");
        exit(0);
    }
    char *filename = argv[1];
    char string[1024];
    printf("Creating a file %s ... \n",filename);
    creat(filename,0644);
    // open file for writing only
    int fd = open(filename,O_WRONLY,0);
    int sz; //actual size of the file
    if(fd==-1){
        printf("Error opening file\n");
        exit(0); // exit from program
    }
    printf("File Descriptior: %d\n", fd);
    char str[1024];
    strcpy(str,"Hello World");
    sz = write(fd, str, 1024);
    close(fd);

    char buf[1024]; //hold value to be read
    fd = open(filename,O_RDONLY,0);
    // include error checking here
     if(fd==-1){
        printf("Error opening file\n");
        exit(0); // exit from program
    }
    read(fd,string, 1024);
    printf("%s", string);
    close(fd); // close file
    return 0;
}
