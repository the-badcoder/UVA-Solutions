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
#define ll          long long int
///Macro End.

using namespace std;

bool status[1000001];

ll is_prime( ll n )
{
    ll sq = sqrt(n);
    for( ll i = 2; i <= sq; i++ )
    {
        if( n % i == 0 )
        {
            return 0;
        }
    }
    return 1;
}

ll  rev( ll  n )
{
    ll sum = 0, rem;

    while( n != 0 )
    {
        rem = n % 10;
        sum = sum * 10 + rem;
        n /= 10;
    }
    return sum;
}
int main()
{
    /// I May Not Be Able To Solve Today's Problems, But I Will Learn, And Obiviously I Can Solve Every Problems One Day :)
    ll i, j, n, sq, x, y;

    while( scanf("%lld", &n) == 1 )
    {
        x = rev(n);

        if( is_prime(n) != 1 )
        {
            printf("%lld is not prime.\n", n);
        }
        else if( is_prime(x) == 0 || x == n )
        {
            printf("%lld is prime.\n", n);
        }
        else
        {
            printf("%lld is emirp.\n", n);
        }

    }
    return 0;
}
