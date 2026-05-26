#include <stdio.h>

void reverse(int arr[], int n)
{
    int s = 0, e = n - 1;
   
    while (s<e)
    {
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++;
        e--;
    }
    
}
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{

    int arr[] = {10, 40, 30, 60, 33};
    int n = 5;
    display(arr, n);
    reverse(arr, n);
    display(arr, n);

    return 0;
}