#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int balance = 1000;
pthread_mutex_t lock;

void* deposit(void* arg) {
    int amount = 500;
    pthread_mutex_lock(&lock);
    balance += amount;
    printf("Deposited %d | New balance: %d\n", amount, balance);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* withdraw(void* arg) {
    int id = *(int*)arg;
    pthread_mutex_lock(&lock);
    if (balance >= 200) {
        balance -= 200;
        printf("Thread %d withdrew 200 | New balance: %d\n", id, balance);
    } else {
        printf("Thread %d tried to withdraw but insufficient balance.\n", id);
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t t1, t2[5];
    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, deposit, NULL);
    for (int i = 0; i < 5; i++)
        pthread_create(&t2[i], NULL, withdraw, &i);

    pthread_join(t1, NULL);
    for (int i = 0; i < 5; i++)
        pthread_join(t2[i], NULL);

    pthread_mutex_destroy(&lock);
    printf("Final Balance: %d\n", balance);
    return 0;
}
