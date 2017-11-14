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
   int num, road, sum, c = 0;


   while( cin >> num >> road ){
    if( num == 0 && road == 0){
        break;
    }
    sum = ( num - 1 ) / road; //// Just easy one -_- but it takes a lots of time to solve it on UVA oj :/
     //// i tried  num / road :p

    if( sum > 26 ) {
        cout << "Case " << ++c << ": ";
        cout << "impossible" << endl;
    }
    else {
        cout << "Case " << ++c << ": ";
        cout << sum << endl;
    }

   }
    return 0;
}
