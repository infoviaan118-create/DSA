#include <stdio.h>

void display(int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }
    printf("\n");
}

int ArraySum(int ar[], int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        // {20, 30, 40, 50};
        sum = sum + ar[i]; // 140
    }
    printf("\n");
    return sum;
}



int main()
{

    int arr[] = {20, 30, 40, 50};
    int brr[] = {201, 301, 401, 501, 44};

    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(brr) / sizeof(brr[0]);

    display(arr, n);
    display(brr, m);

    printf("%d", ArraySum(arr, n));
    printf("%d", ArraySum(brr, m));

    return 0;
}