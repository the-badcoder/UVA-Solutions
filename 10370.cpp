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



int main()
{
#ifndef ONLINE_JUDGE
    ///READ
    ///WRITE
#endif // ONLINE_JUDGE

     int test, n, a[1001], sum, digit;
     double avg, total;

     cin >> test;

     while( test-- ){
        cin >> n;
        sum = digit = 0;
        for( int i = 0; i < n; i++ ){
            cin >> a[i];
            sum += a[i];
        }
        avg = (double) sum / n;
        //cout << avg << endl;

        for( int i = 0; i < n; i++ ){
            if( avg < a[i] )
                digit++;
        }
        //cout << digit << endl;
        total = (double) ( 100 * digit ) / n;
        pf("%.3lf%%\n", total);
     }

    return 0;

}
