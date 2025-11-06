#include <stdio.h>
#include <pthread.h>

int sharedVar = 0;         // Global variable
pthread_mutex_t lock;      // Mutex

void* threadFunc(void* arg) {
    pthread_mutex_lock(&lock);        // Lock
    sharedVar += 1;                   // Access global variable
    printf("Thread updated sharedVar = %d\n", sharedVar);
    pthread_mutex_unlock(&lock);      // Unlock
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&lock, NULL);  // Initialize mutex

    pthread_create(&t1, NULL, threadFunc, NULL);
    pthread_create(&t2, NULL, threadFunc, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);     // Destroy mutex

    return 0;
}
