#include <stdio.h>

int main(int argc,char* argv){
    char c;
    while((c=getc(stdin))!=EOF){
        if(putc(c,stdout)==EOF){
            printf("err putc\n");
            return 1;
        }
    }
    //error in stdin
    //EOF:err or true EOF
    if(ferror(stdin)){
        printf("err input\n");
    }
    return 0;
}