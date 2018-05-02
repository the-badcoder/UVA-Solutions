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

int a[110], dp[105][50005];
int test, sum, total, n, digit;

int rec( int i, int w )
{
    //deb("HY", i, w );
    if( i == n )
    {
        return 0;
    }
    if( dp[i][w] != -1 )
    {
        return dp[i][w];
    }
    int profit1 = 0, profit2 = 0;
    if( ( w - a[i] ) >= 0 )
    {
        profit1 = rec( i + 1, w - a[i] ) + a[i];
    }
    profit2 = rec( i + 1, w );
    //deb( profit1, profit2, w );
    return dp[ i ][ w ] = max( profit1, profit2 );
}

int main()
{
    sf1( test );

    while( test-- && sf1( n ) )
    {
        reset();
        for( int i = 0; i < n; i++ )
        {
            sf1( a[i] );
            sum += a[i];
        }
        int ans = rec( 0, sum / 2 );
        int rem = sum - ans;
        int benefit = abs( rem - ans );
        //deb( ans, rem, benefit );
        printf("%d\n", benefit );

    }
    return 0;
}

void reset()
{
    memset( dp, -1, sizeof dp );
    sum = 0;
}

