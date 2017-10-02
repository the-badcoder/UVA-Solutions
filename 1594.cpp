/// Bismillah Hir Rahmanir Rahim

#include <bits/stdc++.h>

using namespace std;

#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define ff                    first
#define ss                    second
#define pb                    push_back
#define space                 " "
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
typedef  map<string, string>      mss;
typedef  map<int,int>	          mii;
typedef  map<ll, ll>              mll;
typedef  map<char,int>            mci;
typedef  map<int,string>	      mis;
typedef  pair<int,int> 	          ii;
typedef  pair<string, int>        psi;
typedef  pair<string, string>     pss;
typedef  vector<int> 	          vi;
typedef  vector<string> 	      vs;
typedef  vector<char>	          vc;
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
#define sf2ll(a,b)            scanf("%I64d %I64d", &a, &b)
#define sf3ll(a,b,c)          scanf("%I64d %I64d %I64d", &a, &b, &c)
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

template<class T> int ToInteger(const T &x){ stringstream s; s << x; int r; s >> r; return r; }


const int res = 2e5 + 10;
const ll mod = 1e9 + 7;

bool flag[ res ];

int main()
{
    //WRITE;
    int test, n, a[50], sum, total;
    string s, ch;
    map < string, bool > m;
    vs v;

    sf1( test );

    while( test-- && sf1( n ) )
    {

        s = "", ch = "";
        memset( flag, false, sizeof flag );

        for( int i = 1; i <= n; i++ )
        {
            sf1( a[i] );
        }

        for( int i = 1; i <= n; i++ )
        {
            ch += "0";
        }

        //deb( ch );

        while( true )
        {
            s = "";
            int temp = a[1];
            for( int i = 1; i < n; i++ )
            {
                a[i] = abs( a[i] - a[i+1] );
                //deb( a[i] );
                s += (abs( a[i] - a[i+1] ) + '0');
            }
            a[ n ] = abs( a[ n ] - temp );
            s += ( abs( a[1] - a[n] ) + '0' );

            if( s == ch ){
                printf("ZERO\n");
                break;
            }
            else if( m[ s ] == false ){
                m[ s ] = true;
                continue;
            }
            else if( m[ s ] == true ){
                printf("LOOP\n");
                break;
            }
        }
        m.clear();
    }
    return 0;
}
