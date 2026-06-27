#include <stdio.h>

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k; // 0 1 1 
    int n1 = m - l + 1; // n1= 2
    int n2 = r - m;     // n2= 0

    int L[n1], R[n2];
            // 2<2
    for (i = 0; i < n1; i++)
    {
        // L[65,2]
        L[i] = arr[l + i];
    }
                // 0<0
    for (j = 0; j < n2; j++)
    {
        // R[2]
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;//0
        // 0<2 && 0<0
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // 0< 0
    while (i < n1)
    {   
        
        arr[k] = L[i];
        i++;
        k++;
    }
    // 0 < 1
    while (j < n2)
    {

        // {65, 2, 23, 12, 11};
        arr[k] = R[j];
        j++; // 1
        k++; // 2
    }

    printArr(arr, 5);
}


void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {   
        
        int m = (l + r) / 2;

        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{

    int arr[] = {65, 2, 23, 12, 11};
    printArr(arr, 5);
    printf("\n\n");
    mergesort(arr, 0, 5 - 1);
    printf("\nSorted Array : ");
    printArr(arr, 5);

    return 0;
}
