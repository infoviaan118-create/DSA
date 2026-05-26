#include <stdio.h>
int findMaxSumOfSubArray(int arr[], int s, int ws)
{
    if (ws > s)
    {
        printf("Invalid Window Size...");
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < ws; i++)
    {
        sum += arr[i];
    }
    int maxSum = sum;

    for (int j = ws; j < s; j++)
    {
        sum += arr[j];
        sum -= arr[j-ws];
        if (sum > maxSum)
        {
            maxSum = sum;
        }
    }
    return maxSum;
}

int main()
{

    int arr[] = {10, 23, 405, 55, 65};
    int s = 5;
    int window_Size = 2;

    int max = findMaxSumOfSubArray(arr, s, window_Size);

    printf("The Max Sum Of Sub-Array is %d",max);

    return 0;
}