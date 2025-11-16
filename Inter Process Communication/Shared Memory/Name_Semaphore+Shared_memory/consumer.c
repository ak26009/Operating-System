#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>  
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>

int main(){

    sem_t *lock = sem_open("/sem_lock", 0);

    int fd;
    char* str;

    fd = shm_open("/shmfile",O_CREAT|O_RDWR,0666);
    //ftruncate(fd,sizeof(int));
    str = mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

    sem_wait(lock);

    printf("%s",str);

    printf("data transfer successfully!!\n");
    
    sem_unlink("/sem_lock");
    shm_unlink("/shmfile");
}
