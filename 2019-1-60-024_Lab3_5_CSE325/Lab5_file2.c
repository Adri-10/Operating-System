#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>


int main(){
    DIR *dirptr=opendir(".");
    if(dirptr==NULL){
        printf("Cannot open directory\n");
        exit(1);
    }
    struct dirent *entry = readdir(dirptr);
    while(entry != NULL){
        printf("[%ld] [%u] [%u] [%s]\n",entry->d_ino, entry->d_reclen, entry->d_type, entry->d_name);
        entry = readdir(dirptr);
    }
    closedir(dirptr);
    return 0;
}
