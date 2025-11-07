 #include <stdio.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t lock;  


void *incthread(void *data) {
    pthread_mutex_lock(&lock); 
    for (int i = 0; i < 20; i++) {
        count++;
        printf("inc: %d\n", count);
    }
    pthread_mutex_unlock(&lock); 
    return NULL;
}


void *decthread(void *data) {
    pthread_mutex_lock(&lock);  
    for (int i = 20; i > 0; i--) {
        count--;
        printf("dec: %d\n", count);
    }
    pthread_mutex_unlock(&lock);  
    return NULL;
}

int main() {
    pthread_t incid, decid;
    

    pthread_mutex_init(&lock, NULL);
    

    pthread_create(&incid, NULL, incthread, NULL);
    

    pthread_create(&decid, NULL, decthread, NULL);

   
    pthread_join(incid, NULL);
    pthread_join(decid, NULL);


    pthread_mutex_destroy(&lock);

    return 0;
}
