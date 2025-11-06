#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Thread function
void* print_numbers(void* arg) {
    for(int i = 0; i < 5; i++) {
        printf("Thread: %d\n", i);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t thread_id;

    // Create thread
    pthread_create(&thread_id, NULL, print_numbers, NULL);

    // Main thread work
    for(int i = 5; i < 10; i++) {
        printf("Main thread: %d\n", i);
        sleep(1);
    }

    // Wait for thread to finish
    pthread_join(thread_id, NULL);
    printf("Thread finished\n");
    return 0;
}
