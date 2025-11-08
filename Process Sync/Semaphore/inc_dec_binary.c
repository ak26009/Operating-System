#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

sem_t room;
int count = 0;

void *incthread(void *data) {
  sem_wait(&room); 
  for (int i = 0; i < 20; i++) {
      count++;
      printf("inc: %d\n", count);
    }
    sem_post(&room); 
    return NULL;
}

void *decthread(void *data) {
    sem_wait(&room);  
    for (int i = 20; i > 0; i--) {
        count--;
        printf("dec: %d\n", count);
    }
    sem_post(&room);  
    return NULL;
}

int main(){
  sem_init(&room,0,1);
  
  pthread_t t1,t2;
  
  pthread_create(&t1,NULL,incthread,NULL);
  pthread_create(&t2,NULL,decthread,NULL);
  
  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  
}
