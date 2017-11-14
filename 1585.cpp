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

int main()
{
    int test, sum, digit ;
    string s;

    cin >> test;
    cin.ignore();

    while( test-- ){
        cin >> s;
        digit = sum = 0;

        for( int i = 0; i < s.size(); i++ ){
            if( s[i] == 'O' ){
                digit++;
                sum += digit;
            }
            else {
                digit = 0;
                sum += 0;
            }
        }
        cout << sum << endl;
    }

}
