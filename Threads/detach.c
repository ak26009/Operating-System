#include<stdio.h>
#include<pthread.h>

void* work(void*arg){
  printf("Thread is working...\n");
}

int main(){
  pthread_t t;
  pthread_create(&t,NULL,work,NULL);
  pthread_detach(t);
  printf("In main\n");
  pthread_exit(NULL);
  return 0;
}
