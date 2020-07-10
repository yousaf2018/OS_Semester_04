#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
int chopSticks[5]={0};
sem_t chopSticksLock;
void *dining_table(void *wno)
{
  int i =1;
  while(i==1){
  if((chopSticks[((*((int *)wno)+1)%5)]==0)&&(chopSticks[((*((int *)wno)+4)%5)]==0)){
    sem_wait(&chopSticksLock);
    chopSticks[((*((int *)wno)+1)%5)]=1;
    chopSticks[((*((int *)wno)+4)%5)]=1;
    printf("I am eating now philospher %d\n",(*((int *)wno)));
    chopSticks[((*((int *)wno)+1)%5)]=0;
    chopSticks[((*((int *)wno)+4)%5)]=0;
    printf("I am done with eating philospher %d\n",(*((int *)wno)));
    sem_post(&chopSticksLock);
    break;
  }
  else{
    printf("I am waiting for eating philospher %d\n", (*((int *)wno)));
    continue;
  }

}
}
int main()
{
 pthread_t philospher[5];
 sem_init(&chopSticksLock,0,1);
 for(int i = 0; i < 5; i++) {
 printf("I am philospher %d\n",i+1);
 pthread_create(&philospher[i], NULL, dining_table,&i);
 }
 for(int i = 0; i < 5; i++) {
 pthread_join(philospher[i], NULL);
 }
 sem_destroy(&chopSticksLock);
 return 0;

}
