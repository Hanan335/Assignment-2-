#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void takeoff() {
    printf("Child Process of PID  %d , Drone is  taking off\n", getpid());
    sleep(2); 
    printf("Child Process of PID %d ,Takeoff complete.\n", getpid());
}

void land() {
    printf("Parent Process of PID %d, Drone is landing \n", getpid());
    sleep(2); 
    printf("Parent Process of PID  %d, Landing complete.\n", getpid());
}

int main() {
    
    pid_t pid = fork();

    if (pid < 0) {
        printf(" Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        takeoff();
    } else {
        wait(2); 
        land();
    }

    printf("Operations complete.\n", getpid());
    return 0;
}
