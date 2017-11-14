/// Bismillah Hir Rahmanir Rahim

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair <int, int>;
using vii = vector<ii>;

#define ff                    first
#define ss                    second
#define pb                    push_back
#define space                 " "
#define all(x)                (x).begin(), (x).end()
#define eprintf(...)          fprintf(stderr, __VA_ARGS__)

/*
template <class T> T gcd(T a,T b){ if(b == 0) return a; return gcd( b,a % b ); }
template <class T> T lcm(T a, T b ){ return ( a / gcd( a,b ) ) * b; }
template<class T> string ToString(const T &x){ stringstream s; s << x; return s.str(); }
template<class T> int ToInteger(const T &x){ stringstream s; s << x; int r; s >> r; return r; }
*/

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

#define pf                    printf
#define sf1(a)                scanf("%d", &a)
#define sf2(a,b)              scanf("%d %d",&a, &b)
#define sf3(a,b,c)            scanf("%d %d %d", &a, &b, &c)
#define sf4(a,b,c,d)          scanf("%d %d %d %d", &a, &b, &c, &d)

#define sf1ll(a)              scanf("%lld", &a)
#define sf2ll(a,b)            scanf("%lld %lld", &a, &b)
#define sf3ll(a,b,c)          scanf("%lld %lld %lld", &a, &b, &c)
#define sf4ll(a,b,c,d)        scanf("%lld %lld %lld %lld", &a, &b, &c, &d)

#define READ                  freopen("in.txt", "r", stdin);
#define WRITE                 freopen("out.txt", "w", stdout);
/// The End.

void check_time()
{
#ifdef the_badcoder
    eprintf("%.5lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}

const int res = 1e7 + 10;
const ll mod = 1e9 + 7;

char mark[ res ];
vector <int> prime, factors;

void seive()
{
    mark[ 0 ] = mark[ 1 ] = 1;
    prime.push_back( 2 );

    for( int i = 4; i <= res; i += 2 )
    {
        mark[ i ] = 1;
    }
    int sq = sqrt( res );

    for( int i = 3; i <= sq; i += 2 )
    {
        if( mark[ i ] == 0 )
        {
            for( int j = i * i; j <= res; j += ( 2 * i ) )
            {
                mark[ j ] = 1;
            }
        }
    }

    for( int i = 3; i <= res; i += 2 )
    {
        if( mark[ i ] == 0 )
        {
            prime.push_back( i );
        }
    }
}

ll benefit( ll a, ll c )
{
    ll ans = 1;

    for( int i = 0; i <= 3000 && prime[i] <= a && prime[i] <= c; i++ )
    {
        ll x = 0, y = 0;
        while( a % prime[i] == 0 )
        {
            a /= prime[i];
            x++;
        }
        while( c % prime[i] == 0 )
        {
            c /= prime[i];
            y++;
        }
        //deb( x, y );
        ll temp = prime[i];

        if( y > x )
        {
            for( int j = 1; j <= y; j++ )
            {
                ans *= temp;
            }
        }
    }

    if( c > 1 && a == 1 )
    {
        ans *= c;
    }

    return ans;
}

int main()
{
    seive();
    int n, a, b, c, sum, total, test;

    sf1( test );

    while( test-- && sf2( a, b ) )
    {
        if( b % a != 0 )
        {
            printf("NO SOLUTION\n");
        }
        else
        {
            ll ans = benefit( a, b );
            printf("%lld\n", ans );
        }
    }
    return 0;
}

