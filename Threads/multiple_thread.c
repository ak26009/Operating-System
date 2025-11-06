#include<stdio.h>
#include<pthread.h>

void* num(void* arg){
  int num = *(int*)arg;

  printf("Thread %d\n",num);
  return NULL;

}

int main(){
  pthread_t t[3];
  int id[3] = {1,2,3};
  
  for(int i=0; i<3 ; i++){
    pthread_create(&t[i],NULL,num,&id[i]);    
  }
  
  for(int i=0; i<3 ; i++){
    pthread_join(t[i],NULL);
  }
  printf("All thread completed\n");
  
  return 0;
}
