#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>


double average = 0.0;
int min ;
int max ;
int count; 
int numbers[1000];


void* Average(void* arg) {
    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    average = sum / count; 
    
}


void* Max(void* arg) {
    for (int i = 0; i < count; i++) {
        if (numbers[i] > max) {
            max = numbers[i]; 
        }
    }
}


void* Min(void* arg) {
    for (int i = 0; i < count; i++) {
        if (numbers[i] < min) {
            min= numbers[i]; 
        }
    }
}

int main(int argc, char* argv[]) {
   
   count = argc;
   count = count -1;

    for (int i = 0; i < count; i++) {
        numbers[i] = atoi(argv[i + 1]);
    }

    
    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, Average, NULL);
    pthread_create(&t2, NULL, Max, NULL);
    pthread_create(&t3, NULL, Min, NULL);


    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    
    printf("The average value is: %.3f\n", average);
    printf("The minimum value is: %d\n", min);
    printf("The maximum value is: %d\n", max);

    return 0;
}
