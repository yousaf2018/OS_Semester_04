#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
int sum=0;
sem_t mutex;

void* thread(void* arg)
{
    printf("\nEntered..\n");
	//Critical Section
	sem_wait(&mutex);
	for(int i=0;i<10000000;i++)
		sum+=1;
	sem_post(&mutex);
}

void* thread2(void* arg)
{
    printf("\nEntered..\n");
	//Critical Section
	sem_wait(&mutex);
	for(int i=0;i<10000000;i++)
		sum-=1;
	sem_post(&mutex);
}

int main()
{
//Initializing Semaphore to a value
	sem_init(&mutex, 0, 1);

    pthread_t t1,t2,t3,t4,t5,t6;
    pthread_create(&t1,NULL,thread,NULL);
		pthread_create(&t2,NULL,thread,NULL);
		pthread_create(&t3,NULL,thread,NULL);
		pthread_create(&t4,NULL,thread2,NULL);
		pthread_create(&t5,NULL,thread2,NULL);
		pthread_create(&t6,NULL,thread2,NULL);
    pthread_join(t1,NULL);
		pthread_join(t2,NULL);
		pthread_join(t3,NULL);
		pthread_join(t4,NULL);
		pthread_join(t5,NULL);
		pthread_join(t6,NULL);
    sem_destroy(&mutex);
		printf("Sum :) %d\n",sum);
    return 0;
}
