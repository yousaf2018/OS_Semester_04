#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *PrintHello(void* threadid)
{
	long tid;
	tid= (long)threadid;
	printf("Hello World, It's me with thread ID: %ld!\n",tid);
	pthread_exit(NULL); 
}

int main()
{
	pthread_t thread;
	int rc, t=1;
	printf("In main, creating thread.\n");
	rc = pthread_create(&thread, NULL, PrintHello, (void*) t);
	pthread_exit(NULL);
	return 0;
}
