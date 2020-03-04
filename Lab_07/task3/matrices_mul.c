#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include<pthread.h>

int m, n, p, q, c, d, k, sum = 0,l,counter=1,start=0,end;
int first[100][100], second[100][100], multiply[100][100];

void *mul(void* threadid)
{
printf("I am came in thread\n");
for (c = start; c < end; c++) {
  for (d = 0; d < q; d++) {
    for (k = 0; k < p; k++) {
      sum = sum + first[c][k]*second[k][d];
    }
    multiply[c][d] = sum;
    sum = 0;

  }
}

}
int main()
{
  printf("Enter number of rows and columns of first matrix\n");
  scanf("%d%d", &m, &n);
  for (c = 0; c < m; c++)
    for (d = 0; d < n; d++)
           first[c][d]=rand()%10+1;
  printf("Enter number of rows and columns of second matrix\n");
  scanf("%d%d", &p, &q);

    int no_of_threads=n*p,t=1,rc;
    end=no_of_threads/4;
    int thread_for_cores=4;
   printf("Number of threads %d:",no_of_threads);
   pthread_t threads[thread_for_cores];
    for (c = 0; c < p; c++)
      for (d = 0; d < q; d++)
            second[c][d]=rand()%10+1;
            
            int i;

            for(i=0;i<4;i++)
            {
              printf("I am creating thread no:%d\n",counter);
              rc=pthread_create(&threads[i], NULL, mul, (void*) p);
              pthread_join(threads[i],NULL);
              counter++;
              start=end;
              if(i==3)
              {
                end=m;
              }
              else
              {
                end=end+end;
              }

            }
    printf("Product of the matrices:\n");

    for (c = 0; c < m; c++) {
      for (d = 0; d < q; d++)
        printf("%d\t", multiply[c][d]);

      printf("\n");
    }


 pthread_exit(NULL);
  return 0;
}
