#include <stdio.h>

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high)
{
    int temp;
    int pivot = arr[high];
    int t = low - 1;
    // p = 11
    // t0
    // {65, 2, 23, 12, 11}
    // {2, 65, 23, 12, 11}
    // 0 4
                // 4<4
    for (int i = low; i < high; i++)
    {   

        // 12<11
        if (arr[i] < pivot)
        {
            t++;
            temp = arr[t];   
            arr[t] = arr[i]; 
            arr[i] = temp;  
        }
    }
    // p = 11
    // t0
    // {65, 2, 23, 12, 11}
    // {2, 65, 23, 12, 11}
    // {2,11, 23, 12, 65}
    // 0 4
    temp = arr[t + 1];
    arr[t + 1] = arr[high];
    arr[high] = temp;

    return t + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        // {65, 2, 23, 12, 11}
        // 0 4
        int pi = partition(arr, low, high);
            // 0 0
            // 2 4
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{

    int arr[] = {65, 2, 23, 12, 11};
    printArr(arr, 5);
    printf("\n\n");
    quickSort(arr, 0, 5 - 1);
    printf("\nSorted Array : ");
    printArr(arr, 5);

    return 0;
}
