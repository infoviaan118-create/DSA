#include <stdio.h>

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binarySearch(int arr[], int low, int high, int key)
{
    // {65, 2, 23, 12, 11}
    //  1 <= 4
    while (low <= high)
    {   
        // 5/2
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)  // 23 < 2
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1; // 1
        }
    }
    return -1;
}

int main()
{

    int arr[] = {11,13,14,16,17};
    int n = 5;

    printArr(arr, n);
    int r = binarySearch(arr, 0, n - 1, 19);

    if (r != -1)
    {
        printf("Element found At index of %d", r);
    }
    else
    {
        printf("Element Not found");
    }

    return 0;
}