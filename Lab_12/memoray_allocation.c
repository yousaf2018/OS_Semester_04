#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr, i , n1, n2,sum=0;
    printf("Enter size: ");
    scanf("%d", &n1);

    ptr = (int*) malloc(n1 * sizeof(int));

    //printf("Addresses of previously allocated memory: ");
    printf("Enter your input values\n");
    for(i = 0; i < n1; ++i){
         //printf("%u\n",ptr + i);
        scanf("%d",ptr + i);
        printf("Address is assigned to it is :> %u\n",ptr + i);
        sum += *(ptr + i);
    }
    printf("Sum of input value is :> %d\n",sum);

    printf("\nEnter the new size: ");
    scanf("%d", &n2);

    // rellocating the memory
    ptr = realloc(ptr, n2 * sizeof(int));

    //printf("Addresses of newly allocated memory: ");
    for(i = 0; i < n2; ++i)
                 printf("Newly Address is assigned to it is :> %u with values %d\n",ptr + i,*(ptr + i));
  
    free(ptr);

    return 0;
} 
