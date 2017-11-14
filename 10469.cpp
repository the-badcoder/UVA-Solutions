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
   int n, n1, sum , i;

   while( scanf("%d %d", &n, &n1) != EOF ){
    printf( "%d\n", n^n1 );   /// Just XOR
   }
    return 0;
}
