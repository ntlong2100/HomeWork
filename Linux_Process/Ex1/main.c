#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    printf("Parent begin!!!\n");
    pid_t pid = fork();

    if(pid < 0){
        perror("Fork fail!!!\n");
        return 1;
    }
    else if(pid == 0){
        printf("Child process!!!\n");
        printf("My pid = %d\n", getpid());
        exit(5);
    }
    else{
        printf("Parent process!!!\n");
        printf("My pid = %d, Child pid = %d\n", getpid(), pid);
        
        int status;
        wait(&status);
        
        if (WIFEXITED(status)) {
            int exit_code = WEXITSTATUS(status);
            printf("Normal termination with exit code: %d\n", exit_code);
        }
        else {
            printf("abnormal termination!!!\n");
        }
    }

    return 0;
}

