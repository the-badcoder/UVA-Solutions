#include <bits/stdc++.h>

using namespace std;

#define READ                   freopen("input.txt", "r", stdin);
#define WRITE                  freopen("output.txt", "w", stdout);
#define space                  " "
#define clr(ar)                memset( ar, 0, sizeof ar )

#define sf1(a)                scanf("%d", &a)
#define sf2(a,b)              scanf("%d %d",&a, &b)
#define sf3(a,b,c)            scanf("%d %d %d", &a, &b, &c)

#define sf1ll(a)              scanf("%lld", &a)
#define sf2ll(a,b)            scanf("%lld %lld", &a, &b)
#define sf3ll(a,b,c)          scanf("%lld %lld %lld", &a, &b, &c)

template<class T1> void deb(T1 e1)
{
    cout << e1 << endl;
}
template<class T1,class T2> void deb(T1 e1, T2 e2)
{
    cout << e1 << space << e2 << endl;
}
template<class T1,class T2,class T3> void deb(T1 e1, T2 e2, T3 e3)
{
    cout << e1 << space << e2 << space << e3 << endl;
}

using ll = long long;
const int res = 1e4 + 10;

void reset();

int d, sum, total, ans, digit, n, m, loop = 0, a[210], x;
ll dp[210][21][210];

ll rec( int i, int taken, ll rem )
{
    //deb( a[i], taken, rem );
    if( taken == x  )
    {
        if( rem == 0 ){
        return 1;
        }
        else {
            return 0;
        }
    }
    if( i == n ){
        return 0;
    }
    if( dp[ i ][ taken ][ rem ] != -1 ){
        return dp[ i ][ taken ][ rem ];
    }
    dp[i][taken][rem] = rec( i + 1, taken + 1, ( rem + a[i] ) % d ) + rec( i + 1, taken, ( rem % d ) );
    return dp[ i ][ taken ][ rem ];
}

int main()
{
    while( sf2( n, m ) && n || m )
    {
        reset();
        for( int i = 0; i < n; i++ )
        {
            sf1( a[i] );
        }
        printf("SET %d:\n", ++loop );
        for( int i = 1; i <= m; i++ )
        {
            sf2( d, x );
            reset();
            printf("QUERY %d: %lld\n", i, rec( 0, 0, 0 ) );
        }
    }

    return 0;
}

void reset()
{
    memset( dp, -1, sizeof dp );
    sum = 0;
}

