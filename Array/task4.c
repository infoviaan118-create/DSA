#include <stdio.h>
void findTargetedSum(int arr[], int s, int trSum){

        int sum = 0;
        int found = 0;
        for (int i = 0; i < s; i++)
        {
            for (int j = i+1; j < s; j++)
            {   
                sum = arr[i] + arr[j];
                if (sum==trSum)
                {
                    printf("(%d, %d) ",arr[i],arr[j]);
                    found++;
                }
            }
        }
        if (!found) 
        {
            printf("No Pairs Found...");
        }
        
}


int main()
{

    int arr[] = {10, 20, 30, 40, 60};
    int s = 5;
    int targetSum = 65;

    findTargetedSum(arr, s, targetSum);

    return 0;
}