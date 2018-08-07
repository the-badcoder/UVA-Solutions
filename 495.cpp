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

const int res = 1e5 + 5;
const ll mod = 1e9 + 7;


/**
        ACCEPT FAILURE.
**/

string dp[ 5050 ];

string addCalc( string x, string y )
{
    string ret;
    int one, two, a, b, carry = 0, adding;
    reverse( all( x ) );
    reverse( all( y ) );

    for( int i = 0; i < max( x.size(), y.size() ); i++ )
    {
        if( i < x.size() )
        {
            one = x[ i ] - '0';
        }
        else {
            one = 0;
        }
        if( i < y.size() )
        {
            two = y[ i ] - '0';
        }
        else {
            two = 0;
        }
        adding = one + two + carry;
        carry = 0;

        if( adding > 9 )
        {
            //string temp = ( ( adding % 10 ) + '0' );
            ret.push_back( ( adding % 10 ) + '0' );
            carry = adding / 10;
        }
        else {
            ret.push_back( adding + '0' );
        }
    }
    if( carry )
    {
        ret.push_back( carry + '0' );
    }
    reverse( all( ret ) );

    return ret;
}

string pre_cal( int n )
{
    if( n == 0 )
    {
        dp[ n ] = '0';
    }
    if( n == 1 )
    {
        dp[ n ] = '1';
    }

    if( !dp[ n ].size() )
    {
        dp[ n ] = addCalc( pre_cal( n - 1 ), pre_cal( n - 2 ) );
    }

    return dp[ n ];
}

int main()
{
    int n;

    while( scanf("%d",&n ) == 1 )
    {
        cout << "The Fibonacci number for " << n << " is " << pre_cal( n ) << endl;
    }


    return 0;
}

