#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd;
    int *count;

    fd = shm_open("/myshm", O_RDONLY, 0666);
    count = mmap(NULL, sizeof(int), PROT_READ, MAP_SHARED, fd, 0);

    while (1) {
        printf("Reader: count = %d\n", *count);
        sleep(1);
    }

    return 0;
}
