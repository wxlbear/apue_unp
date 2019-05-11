//
// Created by wxl on 2019-05-11.
//

#include "apue.h"
#include <sys/wait.h>

static void sig_int(int);

int main() {
    char buf[MAXLINE];
    pid_t  pid;
    int status;

    // regist signal listener
    if(signal(SIGINT, sig_int) == SIG_ERR){
        err_sys("signal error");
    }


    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL){
        if(buf[strlen(buf)-1] == '\n'){
            buf[strlen(buf)-1] = 0;
        }
        if((pid= fork()) < 0){
            err_sys("fork error");
        } else if(pid == 0){
            execlp(buf, buf, (char *)0);
            err_ret("could n't execute: %s", buf);
            exit(127);
        }

        if((pid = waitpid(pid, &status, 0)) < 0){
            err_sys("waitpid error");
        }
        printf("%% ");
    }

    exit(0);
}

void sig_int(int signo){
    printf("interrupt\n%%");
}
