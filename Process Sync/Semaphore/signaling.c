#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t signal_sem; // unnamed semaphore for signaling

void* producer(void* arg) {
    printf("Producer: Preparing data...\n");
    sleep(2); // simulate work
    printf("Producer: Done! Signaling consumer.\n");
    sem_post(&signal_sem); // send signal
    return NULL;
}

void* consumer(void* arg) {
    printf("Consumer: Waiting for producer signal...\n");
    sem_wait(&signal_sem); // wait for signal
    printf("Consumer: Got the signal! Consuming data now.\n");
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Initialize semaphore with 0 because consumer should wait
    sem_init(&signal_sem, 0, 0);

    pthread_create(&t1, NULL, consumer, NULL);
    pthread_create(&t2, NULL, producer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&signal_sem);
    return 0;
}
