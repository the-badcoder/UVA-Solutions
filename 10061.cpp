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

const int res = 900;
const ll mod = 1e9 + 7;

vector <int> prime;
vii v;
bitset<10000010> bs;

void sieve(long long ub )
{
    bs.set();
    bs[0] = bs[1] = 0;
    for( int i = 2; i <= ub + 1; i++ )
    {
        if( bs[i] )
        {
            prime.push_back( i );
            for(long long j = i * i; j <= ub + 1; j += i )
            {
                bs[j] = 0;
            }
        }
    }
}

void factFactorize( int base )
{
    for( int i = 0; i < prime.size() && prime[i] <= base; i++ )
    {
        int x = base;
        int freq = 0;

        while( x % prime[i] == 0)
        {
            freq++;
            x = x / prime[i];
        }
        //deb( prime[i], freq );
        if( freq == 0 )
        {
            continue;
        }
        v.push_back( { prime[i], freq } );
    }
}

int factorialPrimePower ( int n, int p );
ll factorailDigitExended( ll n, ll base );

int main()
{
    sieve(900);

    int n, b;

    while( sf2( n, b ) == 2 )
    {
        v.clear();
        factFactorize( b );
        int mini = INT_MAX;

        for( auto it: v )
        {
            int ans = factorialPrimePower( n, it.ff );
            //deb( ans, it.ss );
            mini = min( mini, ans / it.ss );
        }

        ll digit = factorailDigitExended( n, b );

        printf("%d %lld\n", mini, digit );
    }

    return 0;
}

ll factorailDigitExended( ll n, ll base )
{
    double x = 0;

    for( int i = 1; i <= n; i++ )
    {
        x += log10( i ) / log10( base );
    }
    ll res = ( (ll) x ) + 1;

    return res;
}


int factorialPrimePower ( int n, int p )
{
    int freq = 0;
    int x = n;

    while ( x )
    {
        freq += x / p;
        x = x / p;
    }

    return freq;
}

