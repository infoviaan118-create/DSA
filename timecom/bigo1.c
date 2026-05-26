#include <stdio.h>

int main()
{
    // O(1)
    int a = 10;
    int arr[5];
    arr[0] = a;
    printf("%d", arr[0]);

    // big O(n)
    int n = 200;
    for (int i = 1; i < n; i++)
    {
        /* code */
    }
    int nn = 20;
    for (int j = 1; j < nn; j++)
    {
        /* code */
    }

    for (int i = 1; i < n; i++)
    {
        for (int i = 0; i < 5; i++)
        {
            /* code */
        }
    }

    // big o(n^2)
    int n = 5;
    for (int i = 1; i < n; i++)
    {
        for (int i = 0; i < n; i++)
        {
            /* code */
        }
    }

    for (int i = 1; i < n; i /= 2)
    {
    }

    for (size_t i = 0; i < n; i++)
    {
        /* code */
    }

    //  space
    int a;            // o(1)
    int arr[n]        // o(n)
        int arr[n][n] // o(n^2)

        return 0;
}