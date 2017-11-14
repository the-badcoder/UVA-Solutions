/*
    Bismillah Hir Rahmanir Rahim
*/
///Author: Tareq Aziz Khan
#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    long long int n, fib1, fib2, sum, i;

    while(scanf("%lld", &n) == 1 )
    {
        if(n == 0)
        {
            break;
        }
        fib1 = sum = 0;
        fib2 = 1;

        for(i = 1; i<=n; i++)
        {
            sum = fib1 + fib2;
            fib1 = fib2;
            fib2 = sum;
        }

        printf("%lld\n", sum);

    }
    return 0;
}
