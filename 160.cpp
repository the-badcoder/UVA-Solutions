/// Bismillah Hir Rahmanir Rahim

/**
    Practice like Cristiano Ronaldo
        Play Like Leo Messi..
**/

#include <bits/stdc++.h>

using namespace std;

#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define ff                    first
#define ss                    second
#define pb                    push_back
#define space                 " "
#define cubert(x)             (exp(log(x)/3))
#define all(x)                (x).begin(), (x).end()
#define clr(ar)               memset(ar, 0, sizeof(ar))
#define eprintf(...)          fprintf(stderr, __VA_ARGS__)

/*
template <class T> T gcd(T a,T b){ if(b == 0) return a; return gcd( b,a % b ); }
template <class T> T lcm(T a, T b ){ return ( a * b ) / gcd( a,b ); }
template<class T> string ToString(const T &x){ stringstream s; s << x; return s.str(); }
template<class T> int ToInteger(const T &x){ stringstream s; s << x; int r; s >> r; return r; }
*/

typedef  long long int            ll;
typedef  map<string,int>          msi;
typedef  map<int,int>	          mii;
typedef  map<char,int>            mci;
typedef  map<int,string>	      mis;
typedef  pair<int,int> 	          ii;
typedef  pair<string, int>        psi;
typedef  vector<int> 	          vi;
typedef  vector<string> 	      vs;
typedef  vector< ii >             vii;

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

#define sf                    scanf
#define pf                    printf

#define sf1(a)                scanf("%d", &a)
#define sf2(a,b)              scanf("%d %d",&a, &b)
#define sf3(a,b,c)            scanf("%d %d %d", &a, &b, &c)
#define sf4(a,b,c,d)          scanf("%d %d %d %d", &a, &b, &c, &d)

#define sf1ll(a)              scanf("%I64d", &a)
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

const int res = 100 + 5;
const ll mod = 1e8;


/**
        ACCEPT FAILURE.
**/

bool marks[ 105 ];
int n;
vi primes;
vii ans;

void seive()
{
    memset( marks, true, sizeof marks );

    for( int i = 4; i <= res; i += 2 ) marks[ i ] = false;

    primes.push_back( 2 );
    int sq = sqrt( res );

    for( int i = 3; i <= 100; i += 2 )
    {
        if( marks[ i ] == true )
        {
            primes.push_back( i );
            for( int j = i * i; j <= res; j += ( 2 * i ) )
            {
                marks[ j ] = false;
            }
        }
    }
}

int main()
{
    seive();

    //deb( primes.size() );

    while( sf1( n ) and n != 0 )
    {
        ans.clear();
        for( int i = 0; i < primes.size() and primes[ i ] <= n ; i++ )
        {
            int x = n;
            int freq = 0;

            while( x / primes[ i ] )
            {
                freq += ( x / primes[ i ] );
                x /= primes[ i ];
            }
            ans.push_back( { primes[ i ], freq } );
        }

        printf("%3d! =", n);
        for( int i = 0; i < ans.size(); i++ )
        {
            if( i and !( i % 15 ) ) printf("\n      ");
            printf("%3d", ans[ i ].ss );
        }
        printf("\n");
    }


    return 0;
}

