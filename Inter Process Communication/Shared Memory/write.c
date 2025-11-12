#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd;
    int *count;

    fd = shm_open("/myshm", O_CREAT | O_RDWR, 0666);
    ftruncate(fd, sizeof(int));
    count = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    *count = 0;

    while (1) {
        (*count)++;
        printf("Writer: count = %d\n", *count);
        sleep(1);
    }

    return 0;
}
