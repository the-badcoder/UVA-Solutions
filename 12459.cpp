/*
    Bismillah Hir Rahmanir Rahim

    *MAY ALLAH HELP ME*
*/

///Containers Start..
#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <math.h>
#include <algorithm>
///Container End.

/// **** So be patient. Indeed, the promise of ALLAH is truth - QURAN - 30:60 ****

///Macro Start..
#define mx          100000000
#define PI          acos(-1.0)
#define LL          long long
#define pii         pair <int, int>
#define ppi         pair <pii, int>
#define ff          first
#define ss          second
#define sz(a)       int((a).size())
#define pb          push_back
#define mp          make_pair
#define nn          '\n'
#define all(c)      (c).begin(), (c).end()
#define tr(c, i)    for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define prsnt(c,x)  ((c).find(x) != (c).end())
#define cprsnt(c,x)  (find(all(c), x) != (c).end())
///Macro End.

using namespace std;
int fibo( int n )
{
    if( n == 0 || n == 1 ) return 0;
    else return ( n - 1) + ( n - 2 );
}
int main()
{
    /// I Should Always Be Patient, No Matter My Code Works, Or Not.
    long long int n, fibo1, fibo2 , sum ;

    while( cin >> n && n != 0 )
    {
        fibo1 = 0;
        fibo2 = 1;
        for( int i = 1; i <= n; i++ )
        {
            sum = fibo1 + fibo2;
            fibo1 = fibo2;
            fibo2 = sum;
        }
        printf("%lld\n", sum);
    }
    return 0;
}
