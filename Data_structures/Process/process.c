#include <stdio.h>
#include <sys/types.h>   // pid_t
#include <unistd.h>      // fork(), getpid(), getppid()
#include <sys/wait.h>    // wait()

int main() {
    pid_t pid;

    int *ptr = malloc(sizeof(int) * 5);
    for(int i = 0 ; i < 5 ;i++){
        ptr[i] = 100;
    }

    pid = fork();

    if (pid == 0) {
        printf("Child: PID = %d, Parent PID = %d\n", getpid(), getppid());


    for(int i = 0 ; i < 5 ;i++){
    printf("%d \n" , ptr[i]);
       
    }
    printf("parent done");

    } else if (pid > 0) {
        printf("Parent: PID = %d, Child PID = %d\n", getpid(), pid);
        for(int i = 0 ; i < 5 ;i++){
        printf("child : %d \n" , ptr[i]);
    }
        for(int i = 0 ; i < 5 ;i++){
        ptr[i] = 300;
    }
        for(int i = 0 ; i < 5 ;i++){
        printf("child : %d \n" , ptr[i]);
    }
        wait(NULL);
    printf("child done");

        
    } else {
        perror("fork failed");
    }

    return 0;
}
