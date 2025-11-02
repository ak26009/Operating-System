#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Parent process PID = %d\n", getpid());

    pid_t pid = fork();

    if (pid == 0) {
        // child
        char *args[] = {"./add", "5", "7", NULL};
        execv("./add", args);
    } else {
        // parent
        wait(NULL);
        printf("Child completed.\n");
    }

    return 0;
}
