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

ll dp[6][7850];
int a[] = { 1, 5, 10, 25, 50 };
int test, loop = 0, n;
ll sum, total, ans, maxi, digit;

ll rec( int i, int add )
{
    //deb( i, add );
    if( i >= 5 )
    {
        if( add == 0 )
        {
            return 1;
        }
        return 0;
    }
    if( dp[ i ][ add ] != -1 )
    {
        return dp[ i ][ add ];
    }

    ll x1 = 0, x2 = 0;

    if( (add - a[i]) >= 0 )
    {
        x1 = rec( i, add - a[i] );
    }
    x2 = rec( i + 1, add );
    return dp[ i ][ add ] = x1 + x2;

}
int main()
{
    reset();
    while( sf1( n ) != EOF )
    {
        //reset();
        sum = rec( 0, n );
        printf("%lld\n", sum );
    }
    return 0;
}

void reset()
{
    memset( dp, -1, sizeof dp );
    sum = 0;

}

