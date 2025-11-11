#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int value = 3;
pthread_rwlock_t rd1 ;

void* read1(){
    while(1){
        sleep(1);
        pthread_rwlock_rdlock(&rd1);
        printf("read1 value : %d\n",value);
        pthread_rwlock_rdlock(&rd1);
    }
}

void* read2(){
    while(1){
        sleep(1);
        pthread_rwlock_rdlock(&rd1);
        printf("read2 value : %d\n",value);
        pthread_rwlock_rdlock(&rd1);
    }
}

void* read3(){
    while(1){
        sleep(1);
        pthread_rwlock_rdlock(&rd1);
        printf("read3 value : %d\n",value);
        pthread_rwlock_rdlock(&rd1);
    }
}

void* write1(){
    while(1){
        sleep(1);
        pthread_rwlock_rdlock(&rd1);
        printf("write1 value : %d\n",++value);
        pthread_rwlock_rdlock(&rd1);
    }
}

void* write2(){
    while(1){
        sleep(1);
        pthread_rwlock_rdlock(&rd1);
        printf("write2 value : %d\n",++value);
        pthread_rwlock_rdlock(&rd1);
    }
}

int main(){
    pthread_t r1,r2,r3,w1,w2;

    pthread_create(&r1,NULL,read1,NULL);
    pthread_create(&r2,NULL,read2,NULL);
    pthread_create(&r3,NULL,read3,NULL);
    pthread_create(&w1,NULL,write1,NULL);
    pthread_create(&w2,NULL,write2,NULL);

    pthread_join(r1,NULL);
    pthread_join(r2,NULL);
    pthread_join(r3,NULL);
    pthread_join(w1,NULL);
    pthread_join(w2,NULL);

    pthread_rwlock_destroy(&rd1);
}
