#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char message[] = "Hello from writer process!";
    
    mkfifo("myfifo", 0666); 
    fd = open("myfifo", O_WRONLY); 
    
    write(fd, message, sizeof(message));
    close(fd);
    
    return 0;
}
