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

///Macro End.


using namespace std;

bool status[1000001];
bool isprime( int n )
{
    for( int i = 2; i < n; i++ ){
        if( n % i == 0 ){
            return false;
        }
    }
    return true;
}
int main()
{
    /// I May Not Be Able To Solve Today's Problems, But I Will Learn, And Obiviously I Can Solve Every Problems One Day :)

    int n, i, j, x, sum, total;
    char s[25];

    while( scanf("%s", s) != EOF )
    {
        sum = 0;
        for( i = 0; i < strlen(s); i++ )
        {
            if( s[i] >= 'a' && s[i] <= 'z' )
            {
                sum += s[i] - 96;
            }
            else if( s[i] >= 'A' && s[i] <= 'Z')
            {
                sum += s[i] - 38;
            }
        }
        //cout << sum << endl;

        /* for( int i = 2; i <= 1000000; i++ )
        {
            status[i] = true;
        }
        //int sq = sqrt(sum);
        for( int i = 2; i <= 1000000; i++ )
        {
            if( status[i] == true )
            {
                for( int j = 2 * i; j <= 1000000; j+=i )
                {
                    status[j] = false;
                }
            }
        }
        if( status[sum] == true )
        {
            printf("It is a prime word.\n");
        }
        else
        {
            printf("It is not a prime word.\n");
        }
        */
        if( isprime(sum) == true ){
            printf("It is a prime word.\n");
        }
        else {
            printf("It is not a prime word.\n");
        }

    }

    return 0;
}
