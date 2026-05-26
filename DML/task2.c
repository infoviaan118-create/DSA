#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter The Array Size : ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int)); //

    for (int j = 0; j < n; j++)
    {
        printf("Enter The Value : ");
        scanf("%d", (arr + j));
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }

    free(arr);
    return 0;
}