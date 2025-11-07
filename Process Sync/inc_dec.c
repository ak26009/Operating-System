#include <stdio.h>
#include <pthread.h>

int count = 0;

void *incthread(void *data) {
    for (int i = 0; i <= 20; i++) {
        count++;
        printf("inc: %d\n", count);
    }
    return NULL;
}

void *decthread(void *data) {
    for (int i = 20; i >= 0; i--) {
        count--;
        printf("dec: %d\n", count);
    }
    return NULL;
}

int main() {
    pthread_t incid, decid;

    pthread_create(&incid, NULL, incthread, NULL);
    
    pthread_create(&decid, NULL, decthread, NULL);

    pthread_join(incid, NULL);
    pthread_join(decid, NULL);

    return 0;
}
