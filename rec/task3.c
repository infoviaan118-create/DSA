#include <stdio.h>

// 48 ->
// 2|48
// 2|24
// 2|12
// 2|6
// 3|3
//  |1
// 18 ->

// 2|18
// 3|9
// 3|3
//  |1

// 48-> 2 * 2 * 2 * 2 * 3
// 18-> 2 * 3 * 3

// gcd = 2 * 3 = 6


    // gcd(48,18)
int gcd(int a, int b)
{   
    if(b==0){
        return a;
    }
    // 48%18
    // 18%12
    // 12%6
    // 6%0

    return gcd(b,a%b);  
       // gcd(18,12)
       // gcd(12,6)
       // gcd(6,0)
}

int main()
{
    int g = gcd(36, 18);
    printf("%d", g);

    return 0;
}