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
#include <iomanip>
#include <math.h>
#include <bitset>
#include <algorithm>
///Container End.

/// **** So be patient. Indeed, the promise of ALLAH is truth - QURAN - 30:60 ****

using namespace std;

///Macro Start..
#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define INF                   2147483647
#define LL                    long long
#define pii                   pair <int, int>
#define ppi                   pair <pii, int>
#define ff                    first
#define ss                    second
#define sz(a)                 int((a).size())
#define pb                    push_back
#define sf                    scanf
#define pf                    printf
#define mp                    make_pair
#define nn                    '\n'
#define space                 " "
#define ll                    long long int
#define ul                    unsigned long
#define ull                   unsigned long long
#define mod                   1000000007
#define SIZE                  2000001
#define mem(a,b)              memset(a,b,sizeof(a))
#define all(c)                (c).begin(), (c).end()
#define READ                  freopen("input.txt", "r", stdin);
#define WRITE                 freopen("output.txt", "w", stdout);
#define sf1(a)                scanf("%d",&a)
#define sf2(a,b)              scanf("%d %d",&a,&b)
#define sf3(a,b,c)            scanf("%d %d %d", &a,&b, &c)
#define sf4(a,b,c, d)         scanf("%d %d %d %d", &a,&b, &c, &d)
#define sf1ll(a)              scanf("%I64d",&a)
#define sf2ll(a,b)            scanf("%I64d %I64d",&a,&b)
#define sf3ll(a,b,c)          scanf("%I64d %I64d %I64d", &a,&b, &c)
#define sf4ll(a,b,c, d)       scanf("%I64d %I64d %I64d %I64d", &a,&b, &c, &d)
///Macro End.

int main()
{
    int test, n, m, sum, total, a[15], b[15], loop = 0, flag;

    cin >> test;

    while( test-- )
    {
        cin >> n >> m;
        sum = 0;
        flag = 0;
        for( int i = 0; i < n; i++ )
        {
            cin >> a[i];
        }
        for( int i = 0; i < n; i++ )
        {
            cin >> b[i];
        }
        for( int i = 0; i < n; i++ )
        {
            if( a[i] <= b[i] )
            {
                sum += a[i];
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if( sum <= m && flag == 0 )
        {
            printf("Case %d: Yes\n", ++loop );
        }
        else
        {
            printf("Case %d: No\n", ++loop );
        }
    }
    return 0;
}

