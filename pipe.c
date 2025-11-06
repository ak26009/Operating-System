#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        // Child Process
        close(fd[1]);               // Close write end
        char msg[100];
        read(fd[0], msg, sizeof(msg));
        printf("Child received: %s\n", msg);
    } else {
        // Parent Process
        close(fd[0]);               // Close read end
        write(fd[1], "Hello from parent!", 19);
    }
}
// tyring pipe to transfer data from parent to child
