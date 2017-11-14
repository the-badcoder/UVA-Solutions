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

const int res = 65050;
const ll mod = 1e9 + 7;

bitset<10000010> bs;
bool is_prime[65100], is_carmichael[65100];

void sieve(long long ub )
{
    bs.set();
    bs[0] = bs[1] = 0;

    for(long long i = 2; i <= ub + 1; i++)
    {
        if( bs[i] )
        {
            is_prime[i] = true;
            for(long long j = i * i; j <= ub + 1; j += i)
            {
                bs[j] = 0;
            }
        }
    }
}
ll bigmod ( ll b, ll p, ll m )
{
    ll res = 1 % m, x = b % m;
    while ( p )
    {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}

bool check( int n )
{
    if( is_prime[ n ] )
    {
        return false;
    }
    for( int i = 2; i < n; i++ )
    {
        if( bigmod( i, n, n ) != i )
        {
            return false;
        }
    }
    return true;
}

int main()
{
    sieve(65000);
    int n, sum, total, ans;

    while( sf1( n ) && n != 0 )
    {
        if( is_prime[ n ] == 0 && check( n ) == true )
        {
            printf("The number %d is a Carmichael number.\n", n );
        }
        else
        {
            printf("%d is normal.\n", n );
        }
    }

    return 0;
}

