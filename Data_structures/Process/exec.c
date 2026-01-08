#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    int a = 10;

    if (pid == 0) {
        // Child process
        printf("Child: I am going to exec ls\n");

        execl("/bin/ls", "ls", "-l", NULL);

        // This runs ONLY if exec fails
        perror("exec failed");
    } 
    else if (pid > 0) {
        // Parent process
        printf("Parent: waiting for child to finish\n");
        wait(NULL);
        printf("Parent: child finished, back to parent\n");
    } 
    else {
        perror("fork failed");
    }
     
    printf(" a = %d" , a);


    return 0;
}
