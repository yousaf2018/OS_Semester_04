#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include<pthread.h>

int m, n, p, q, c, d, k, sum = 0,l,counter=1;
int first[100][100], second[100][100], multiply[100][100];

void *mul(void* threadid)
{
printf("I am came in thread\n");
for (k = 0; k < p; k++) {
  sum = sum + first[c][k]*second[k][d];
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
   printf("Number of threads %d:",no_of_threads);
   pthread_t threads[no_of_threads];
    for (c = 0; c < p; c++)
      for (d = 0; d < q; d++)
            second[c][d]=rand()%10+1;
            for (c = 0; c < m; c++) {
              for (d = 0; d < q; d++) {
                printf("I am creating thread no:%d\n",counter);
                rc=pthread_create(&threads[c], NULL, mul, (void*) p);
                pthread_join(threads[c],NULL);
                multiply[c][d] = sum;
                sum = 0;
                counter++;
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
