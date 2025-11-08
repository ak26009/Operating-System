#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int ready = 0; 

void* wait_thread(void* arg) {
    pthread_mutex_lock(&lock);
    while (ready == 0) { 
        printf("Waiting for signal...\n");
        pthread_cond_wait(&cond, &lock);
        // this tells the thread to go to sleep , until and unless u get a signal and release the mutex lock!!! 
    }
    printf("Got the signal! Proceeding...\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* signal_thread(void* arg) {
    pthread_mutex_lock(&lock);
    printf("Doing some work...\n");
    ready = 1;
    pthread_cond_signal(&cond); 
    printf("Signal sent!\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, wait_thread, NULL);
    pthread_create(&t2, NULL, signal_thread, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
