#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork fail!!!\n");
        return 1;
    }
    else if (pid == 0) {
    	printf("Child process!!!\n");
	sleep(10);
	printf("Child process, END!!!\n");
    } 
    else {
    	printf("Parent process!!!\n");
    	exit(0);
    	}
    
    return 0;
}
