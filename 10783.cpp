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
    int test, x, y, sum , loop = 0;

    cin >> test;

    while( test-- ){
        cin >> x >> y;
        sum = 0;
        for( int i = x; i <= y; i++ ){
            if( i % 2 == 1 ){
                sum += i;
            }
        }
        printf("Case %d: %d\n", ++loop, sum);
    }
    return 0;
}
