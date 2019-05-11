//
// Created by wxl on 2019-05-11.
//

#include "apue.h"
int main(void){
    int c;
    while ((c=getc(stdin)) !=EOF){
        if(putc(c,stdout) == EOF){
            err_sys("output error");
        }
    }

    if(ferror(stdin)){
        err_sys("input error");
    }

    exit(0);
}

