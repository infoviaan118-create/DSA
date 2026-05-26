#include <stdio.h>

// 0 1 1 2 3 5 8 


int fibo(int n){ //3
    // base case
    if (n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1;
    }

    return  fibo(n-1)+fibo(n-2);
}





int main() {



    int n= 10;
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", fibo(i)); // 0  1  1 2
    }



     return 0;
}   
