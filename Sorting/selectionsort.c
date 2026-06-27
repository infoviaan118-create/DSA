#include <stdio.h>

void selectionSort(int arr[], int n)
{
    // {65,25,12,13,11}
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        printArr(arr,n);
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
    selectionSort(arr, 5);
    printf("\nSorted Array : ");
    printArr(arr, 5);

    return 0;
}