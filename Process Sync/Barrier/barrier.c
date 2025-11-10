#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_barrier_t ba;
int a, b;

void *num1(void *arg) {
    a = 4;
    printf("num1: a = %d\n", a);
    pthread_barrier_wait(&ba);
    return NULL;
}

void *num2(void *arg) {
    b = 6;
    printf("num2: b = %d\n", b);
    pthread_barrier_wait(&ba);
    return NULL;
}

void *add(void *arg) {
    pthread_barrier_wait(&ba);
    printf("add: sum = %d\n", a + b);
    return NULL;
}

int main(void) {
    pthread_t t1, t2, t3;
    pthread_create(&t1, NULL, num1, NULL);
    pthread_create(&t2, NULL, num2, NULL);
    pthread_create(&t3, NULL, add,  NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    pthread_barrier_destroy(&ba);
    return 0;
}
