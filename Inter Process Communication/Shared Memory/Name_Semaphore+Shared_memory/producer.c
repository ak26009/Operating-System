#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>  
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>


int main(){

    sem_t *lock = sem_open("/sem_lock", O_CREAT, 0666, 0);

    int fd;
    char* str;

    fd = shm_open("/shmfile",O_CREAT|O_RDWR,0666);
    ftruncate(fd,1024);
    str = mmap(NULL,1024,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

    strcpy(str,"Hello from producer\n");
    sem_post(lock);
    
}
