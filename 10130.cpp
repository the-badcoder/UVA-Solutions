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
#define sf4ll(a,b,c,d)        scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &d)

#define READ                  freopen("in.txt", "r", stdin);
#define WRITE                 freopen("out.txt", "w", stdout);
/// The End.

void check_time()
{
#ifdef the_badcoder
    eprintf("%.5lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}

const int res = 1e3 + 10;
const ll mod = 1e9 + 7;


/**
        ACCEPT FAILURE.
**/

int n, g, a[ res ], p[ res ], w[ res ], cost, total, ans, sum;
int dp[ res ][ res ][ 35 ];

int rec( int i, int taken, int weight )
{
    if( i == n ) return 0;
    if( dp[ i ][ taken ][ weight ] != -1 ) return dp[ i ][ taken ][ weight ];

    int curr = 0, next = 0;

    if( w[ i ] + taken <= weight )
    {
        next = rec( i + 1, w[ i ] + taken, weight ) + p[ i ];
    }
    //else next = 0;
    curr = rec( i + 1, taken, weight );

    return dp[ i ][ taken ][ weight ] = max( curr, next );
}


int main()
{
    #ifdef LM10
        freopen("in", "r", stdin );
        freopen("out", "w", stdout );
    #endif // LM10

    int test, loop = 0;

    sf1( test );

    while( test-- && sf1( n ) )
    {
        memset( dp, -1, sizeof dp );
        sum = total = 0;
        for( int i = 0; i < n; i++ )
        {
            sf2( p[ i ], w[ i ] );
        }
        sf1( g );

        for( int i = 0; i < g; i++ )
        {
            sf1( a[ i ] );
        }

        for( int i = 0; i < g; i++ )
        {
            sum += rec( 0, 0, a[ i ] );
        }

        printf("%d\n", sum );
    }
    return 0;
}

