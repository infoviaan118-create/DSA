#include <stdio.h>

void bubble(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{

    int arr[] = {65, 2, 23, 12, 11};
    printArr(arr, 5);
    printf("\n\n");
    bubble(arr, 5);
    printf("\nSorted Array : ");
    printArr(arr, 5);

    return 0;
}