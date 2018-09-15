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

template<class T> double ToInteger(const T &x){ stringstream s; s << x; double r; s >> r; return r; }

const int res = 1e4 + 10;
const ll mod = 1e9 + 7;


/**
        ACCEPT FAILURE.
**/


bool existP = true, existI = true, existU = true;
string s;
double P, U, I;

void solve( int pos )
{
    string temp = "";
    int i = 0;

    for( i = pos + 1; !isalpha( s[ i ] ); i++ )
    {
        temp += s[ i ];
    }
    double value = ToInteger( temp );

    //deb("HY", value );

    if( s[ i ] == 'm' ) {
        value /= 1000.0;
    }
    else if( s[ i ] == 'k' )
    {
        value *= 1000.0;
    }
    else if( s[ i ] == 'M' )
    {
        value *= 1000000.0;
    }

    if( s[ pos - 1 ] == 'P' ) existP = false, P = value;
    else if( s[ pos - 1 ] == 'U' ) existU = false, U = value;
    else if( s[ pos - 1 ] == 'I' ) existI = false, I = value;
}

int main()
{
#ifdef LM10
    //freopen("in", "r", stdin );
    //freopen("out", "w", stdout );
#endif // LM10


    int n, loop = 0;
    double sum, total, ans;
    int digit;
    bool isLine = false;

    sf1( n );
    cin.ignore();

    while( n-- )
    {
//        if( isLine == true ) printf("\n");
//        isLine = true;

        existI = existP = existU = true;
        P = U = I = 0.0;

        getline( cin, s );

        int firstEqSign = s.find_first_of("=");
        int lastEqSign = s.find_last_of("=");

        solve( firstEqSign );
        solve( lastEqSign );

        //deb( P, U, I );

        printf("Problem #%d\n", ++loop );

        if( existI )
        {
            printf("I=%.2fA\n", P / U );
        }
        else if( existP )
        {
            printf("P=%.2fW\n", U * I );
        }
        else if( existU )
        {
            printf("U=%.2fV\n", P / I );
        }

        printf("\n");

    }

    return 0;
}


