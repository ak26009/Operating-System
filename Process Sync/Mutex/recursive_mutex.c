#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;

void* thread1_func(void* arg) {
    
    pthread_mutex_lock(&mutex);
    printf("Thread 1: Locked once\n");

    pthread_mutex_lock(&mutex);
    printf("Thread 1: Locked twice\n");

    sleep(2);

    pthread_mutex_unlock(&mutex);
    printf("Thread 1: Unlocked once\n");

    pthread_mutex_unlock(&mutex);
    printf("Thread 1: Unlocked twice\n");
    return NULL;
}

void* thread2_func(void* arg) {
    sleep(1);

    printf("Thread 2: Trying to lock mutex...\n");
    pthread_mutex_lock(&mutex);
    printf("Thread 2: Locked mutex!\n");

    pthread_mutex_unlock(&mutex);
    printf("Thread 2: Unlocked mutex!\n");
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_mutexattr_t attr;

    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);

    pthread_mutex_init(&mutex, &attr);

    pthread_create(&t1, NULL, thread1_func, NULL);
    pthread_create(&t2, NULL, thread2_func, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_mutexattr_destroy(&attr);

    return 0;
}
