#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 5;

    int s = n;
    int *arr = (int *)malloc(n * sizeof(int));

    for (int  i = 0; i < n; i++)
    {
        printf("Enter The Value : ");
        scanf("%d",(arr+i));
    }

    
    for (int i = 0; i < n; i++)
    {
        printf("%d ",*(arr+i));
    }

    // void * 
    // old mem is safe 
    // 2 para , jisme aapko realloc us var ka name , memory

    n=10;
    arr = (int *)realloc(arr, n*sizeof(int));
    // 12 13 14 15 16 gv gv gv gv gv 


    for (int j = s; j < n; j++) // 10 < 10 
    {
        printf("Enter The Value : ");
        scanf("%d", (arr + j));
    }

    printf("\n");
    for (int j = 0; j < n; j++)
    {
        printf("%d ", *(arr + j));
    }

    return 0;
}
