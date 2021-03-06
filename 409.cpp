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

const int res = 1e4 + 10;
const ll mod = 1e9 + 7;


/**
        ACCEPT FAILURE.
**/


int main()
{
#ifdef LM10
    //freopen("in.txt", "r", stdin );
    freopen("out.txt", "w", stdout );
#endif // LM10

    int n, m, sum, total, ans, loop = 0;

    bool isLine = false;

    while( scanf("%d %d", &n, &m ) == 2 )
    {
        string dummy;
        //getline( cin, dummy );

//        if( isLine == true )
//        {
//            printf("\n");
//        }
//        isLine = true;

        vector < pair < string, int > > v;
        map < string, bool > mark;

        for( int i = 0; i < n; i++ )
        {
            string s;
            cin >> s;
            mark[ s ] = true;
        }

        getchar();

        int maxi = 0;

        for( int j = 0; j < m; j++ )
        {
            string x;
            getline( cin, x );
            string temp = "";
            int digit = 0;

            for( int i = 0; i < x.size(); i++ )
            {
                char low = tolower( x[ i ] );
                if( isalpha( low ) )
                {
                    temp += low;
                }
                else
                {
                    if( mark[ temp ] == true ){
                        digit++;
                    }
                    temp = "";
                }
                if( i == x.size() - 1 )
                {
                    if( mark[ temp ] == true ){
                        digit++;
                    }
                }
            }
            v.push_back( { x, digit } );
            maxi = max( maxi, digit );
            digit = 0;
        }

        printf("Excuse Set #%d\n", ++loop );

        for( auto it: v )
        {
            //deb( it.ff, it.ss, maxi );
            if( it.ss == maxi )
            {
                cout << it.ff << endl;
            }
        }
        printf("\n");

    }

    return 0;
}

