#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

//A counting semaphore basically allows N threads to access a shared resource at the same time, 
//while any extra threads wait (block) until one of those N threads finishes and releases its slot.
// only 3 cars can park at once
sem_t parkingLot;

void* car(void* arg) {
    int car_id = *(int*)arg;

    printf("Car %d is waiting to park...\n", car_id);
    sem_wait(&parkingLot); // try to occupy a spot

    printf("Car %d has parked 🚗\n", car_id);
    sleep(2); // stays parked for 2 seconds

    printf("Car %d is leaving 🏁\n", car_id);
    sem_post(&parkingLot); // free the spot

    return NULL;
}

int main() {
    pthread_t cars[6];
    int car_ids[6];

    // Initialize counting semaphore with 3
    sem_init(&parkingLot, 0, 3);

    for (int i = 0; i < 6; i++) {
        car_ids[i] = i + 1;
        pthread_create(&cars[i], NULL, car, &car_ids[i]);
    }

    for (int i = 0; i < 6; i++) {
        pthread_join(cars[i], NULL);
    }

    sem_destroy(&parkingLot);
    return 0;
}
