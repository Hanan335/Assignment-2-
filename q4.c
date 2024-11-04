#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    for (int i = 0; argv[1][i] != '\0'; i++) {

        int k = isdigit(argv[1][i]);
        if (k==0) { 
            printf("Not a positive natural number \n");
            return 0;
        }
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        printf("Not a positive natural number greater than 0 \n");
        return 0;
    }

    pid_t pid = fork();

    if (pid < 0) {
        printf(" Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        printf("Child of PID -  %d: Collatz sequence for %d , ", getpid(), n);
        while (n != 1) {
            printf("%d", n);
            if (n % 2 == 0) {
                n = n / 2;
            } else {
                n = 3 * n + 1;
            }
        }
        printf("%d",n);
    } else {
        wait(NULL);
        printf("Sequence generation complete.\n", getpid());
    }

    return 0;
}
