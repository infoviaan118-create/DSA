#include <stdio.h>

// WAP to find The factorial of a number using recursion
//  Base Case
//  Recursive call / self call

int findFact(int n)
{
    //  Base Case
    if (n==1)
    {
        return 1
    }
    
    //  Recursive call / self call
    return n*findFact(n-1);
}
// 1
// r 2 * ff(1)
// r 3 * ff(2)
// r 4 * ff(3)
// r 5 * ff(4)
// main-> ff(5)

int main()
{

    int num = 5;
    int r = findFact(num);
    printf("%d", r);
    
    return 0;
}