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
    int test, loop = 0, total, best, n, low, high, T1, T2, Final, ATT, a[4], sum ;
    vector <int> v;
    cin >> test;

    while( test-- )
    {
        sum = 0;
        cin >> T1 >> T2 >> Final >> ATT;
        pf("Case %d: ", ++loop );
        for( int i = 0; i < 3; i++ )
        {
            int a;
            cin >> a;
            v.push_back(a);
        }

        sort( v.begin(), v.end(), greater<int>() );

        sum += ( v[0] + v[1] );
        best = sum / 2;
        //cout << best << endl;

        total = (T1 + T2 + Final + ATT + best);
        v.clear();

        if( total >= 90 )
        {
            cout << "" << "A" << endl;
        }
        else if( total >= 80 )
        {
            cout << "" << "B" << endl;
        }
        else if( total >= 70 )
        {
            cout << "" << "C" << endl;
        }
        else if( total >= 60 )
        {
            cout << "" << "D" << endl;
        }
        else if( total < 60 )
        {
            cout << "" << "F" << endl;
        }

    }
    return 0;

}
