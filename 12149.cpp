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
   int n, sum , i;

   while(cin >> n){
    if( n == 0) {
        break;
    }
    sum = 0;
    for( i = 1; i <= n; i++ ){
        sum += i * i;
    }
    printf("%d\n", sum);
   }
    return 0;
}
