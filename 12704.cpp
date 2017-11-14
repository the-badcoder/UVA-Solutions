/*
        Bismillah Hir Rahmanir Rahim
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
#include <bitset>
#include <algorithm>
///Container End.

/// **** So be patient. Indeed, the promise of ALLAH is truth - QURAN - 30:60 ****

using namespace std;

///Macro Start..
#define PI           acos(-1.0)
#define Pi           3.141592653589793
#define LL           long long
#define pii          pair <int, int>
#define ppi          pair <pii, int>
#define ff           first
#define ss           second
#define sz(a)        int((a).size())
#define pb           push_back
#define sf           scanf
#define pf           printf
#define mp           make_pair
#define nn           '\n'
#define ll           long long int
#define ul           unsigned long
#define ull          unsigned long long
#define mod          1000000007
#define SIZE         2000001
#define mem(a,b)     memset(a,b,sizeof(a))
#define all(c)       (c).begin(), (c).end()
#define READ         freopen("input.txt", "r", stdin);
#define WRITE        freopen("output.txt", "w", stdout);
///Macro End.

bool status[SIZE];

int add( int a, int b )
{
    return a + b;
}
int main()
{
    #ifndef ONLINE_JUDGE
            ///READ
            ///WRITE
    #endif // ONLINE_JUDGE

   int test;
   double a, b, c, s, l, x, y, sum;

   cin >> test;

   while( test-- ){
    cin >> a >> b >> c;

    x = sqrt(( 0 - a ) * ( 0 - a ) + ( 0 - b ) * (0 - b));
    //cout << x << endl;

    s = abs( x + c );
    l = abs( c - x );

    printf("%.2lf %.2lf\n", l, s );

   }
    return 0;
}

