#include <stdio.h>
#include <pthread.h>

// Compile with -pthread
// Create a mutex this ready to be locked!
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

int sum = 0;

void *countgold(void *param) {

    // Same thread that locks the mutex must unlock it
    // Critical section is just 'sum += 1'
    // However locking and unlocking a million times
    // has significant overhead in this simple answer

    pthread_mutex_lock(&m);

    // Other threads that call lock will have to wait until we call unlock

    for (int i = 0; i < 10000000; i++) {
	sum += 1;
    }
    pthread_mutex_unlock(&m);
    return NULL;
}


void *countgold2(void *param) {

    // Same thread that locks the mutex must unlock it
    // Critical section is just 'sum += 1'
    // However locking and unlocking a million times
    // has significant overhead in this simple answer

    pthread_mutex_lock(&m);

    // Other threads that call lock will have to wait until we call unlock

    for (int i = 0; i < 10000000; i++) {
	sum -= 1;
    }
    pthread_mutex_unlock(&m);
    return NULL;
}
int main() {
    pthread_t tid1, tid2,tid3,tid4,tid5,tid6;
    pthread_create(&tid1, NULL, countgold, NULL);
    pthread_create(&tid2, NULL, countgold, NULL);
    pthread_create(&tid3, NULL, countgold, NULL);
    pthread_create(&tid4, NULL, countgold2, NULL);
    pthread_create(&tid5, NULL, countgold2, NULL);
    pthread_create(&tid6, NULL, countgold2, NULL);

    //Wait for both threads to finish:
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    pthread_join(tid4, NULL);
    pthread_join(tid5, NULL);
    pthread_join(tid6, NULL);
    printf("ARRRRG sum is %d\n", sum);
    return 0;
}
