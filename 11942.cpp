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
   int test, a, b, c, d, e, f, g, h, i ,j;

   cin >> test;
   cout << "Lumberjacks:" << endl;
   while(test--){

       cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;

       if( a > b && b > c && c > d && d > e && e > f && f > g && g > h && h > i && i > j){
        cout << "Ordered" << endl;
       }
       else if( a < b && b < c && c < d && d < e && e < f && f < g && g < h && h < i && i < j ){
        cout << "Ordered" << endl;
       }
       else {
        cout << "Unordered" << endl;
       }
   }
    return 0;
}
