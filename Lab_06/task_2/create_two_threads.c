#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int t=0;
void *PrintHello1(void* threadid)
{
	long tid;
	tid= (long)threadid;
    int i;
    for(tid=1;tid<=100000;tid++)
    {
    t++;
       printf("Thread 1 value of gloable:%d\n",t);
    }
	printf("Hello World, It's me with thread ID 1!\n");
	pthread_exit(NULL); 
}
void *PrintHello2(void* threadid)
{
	long tid;
	tid= (long)threadid;
    for(tid=1;tid<=100000;tid++)
    {
       t--;
       printf("Thread 2 value of gloable:%d\n",t);
    }
	printf("Hello World, It's me with thread ID:2!\n");
	pthread_exit(NULL); 
}
int main()
{
	pthread_t thread1,thread2;
	int rc;
	printf("In main, creating thread.\n");
	rc = pthread_create(&thread1, NULL, PrintHello1, (void*) t);
    rc = pthread_create(&thread2, NULL, PrintHello2, (void*) t);
	pthread_exit(NULL);
	return 0;
}
