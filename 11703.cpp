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
const int res = 1e6 + 10;
const int mod = 1e6;

void reset();

int dp[ res ];

void pre_calc()
{
    dp[ 0 ] = 1;

    for( int i = 1; i <= res; i++ )
    {
        double x = i;
        dp[ i ] = ( (dp[ (int) ( floor( x - sqrt( x ) ) ) ] % mod ) + ( dp[ (int) floor( log( x ) ) ] % mod ) + ( dp[ (int) floor( x * sin(x)  * sin( x ) ) ] % mod ) );
        dp[ i ] %= mod;
    }
}

int main()
{
    int n;
    pre_calc();

    while( sf1( n ) && n != -1 )
    {
        printf("%d\n", dp[ n ] );
    }
    return 0;
}

void reset()
{

}

