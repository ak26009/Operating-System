#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t bathroom; 
// it is all most like mutex exclusion
void* person(void* name) {
    char* person_name = (char*)name;

    printf("%s is waiting to use the bathroom...\n", person_name);

    sem_wait(&bathroom);
    printf("%s entered the bathroom \n", person_name);

    sleep(10); 

    printf("%s is leaving the bathroom ️\n", person_name);
    
    sem_post(&bathroom); 
    
    return NULL;
}

int main() {
    pthread_t p1, p2;
    sem_init(&bathroom, 0, 1);

    pthread_create(&p1, NULL, person, "Alice");
    pthread_create(&p2, NULL, person, "Bob");

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    
    sem_destroy(&bathroom);
    return 0;
}
