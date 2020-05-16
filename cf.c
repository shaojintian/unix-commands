#include <unistd.h>
#include <stdio.h>

#define BUFFSIZE 4096

int main(void){
    int n;
    char buf[BUFFSIZE];
    //n=xxx >0
    //must do n=xxx operation
    while((n=read(STDIN_FILENO,buf,BUFFSIZE))>0){
        //do write
        if(write(STDOUT_FILENO,buf,n)!=n){
            printf("write error\n");
            return 0;
        }
    }
    //error
    if(n<0){
        printf("read error\n");
        return 1;
    }
    return 0;
}