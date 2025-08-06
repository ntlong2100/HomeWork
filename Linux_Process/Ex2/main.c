#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
 
int main() {
    setenv("MY_COMMAND", "ls", 1);
 
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork fail!!!");
        return 1;
    }
    else if (pid == 0) {
    
        char *cmd = getenv("MY_COMMAND");
        if (cmd == NULL) {
            fprintf(stderr, "not found MY_COMMAND\n");
            exit(1);
        }
 
        execlp(cmd, cmd, NULL);
 
        perror("execlp fail!!!");
        exit(1);
    } 
    else {
        wait(NULL);
    }
 
    return 0;
}
