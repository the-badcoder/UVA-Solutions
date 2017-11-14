//Bismillah Hir Rahmanir Rahim
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <string.h>
#define MAX 1000000

using namespace std;

int main()
{
   int test, a, b, c, total, sum;

   cin >> test;

   while(test--){
    cin >> a >> b >> c;

    total = a + ( a - b );

    sum = c * total / ( a + b );

    if( sum < 0 ){
        cout << 0 << endl;
    }
    else {
        cout << sum << endl;
    }
   }
    return 0;
}
