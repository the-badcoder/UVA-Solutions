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

template<class T> int ToInteger(const T &x)
{
    stringstream s;
    s << x;
    int r;
    s >> r;
    return r;
}


const int res = 1e5 + 10;
const ll mod = 1e9 + 7;

int a[res];

int main()
{
    //WRITE;
    int n, len, rail, wrong, digit, sum, ans;

    while( true )
    {
        sf1( n );

        if( n == 0 )
        {
            break;
        }
        while( true )
        {
            sf1( a[0] );

            if( a[0] == 0 )
            {
                printf("\n");
                break;
            }

            for( int i = 1; i < n; i++ )
            {
                sf1( a[i] );
            }

            stack <int> s;
            int curr = 1, i = 0;

            while( curr <= n )
            {
                s.push( curr );

                while( !s.empty() and s.top() == a[ i ] )
                {
                    s.pop();
                    i++;

                    if( i >= n )
                    {
                        break;
                    }
                }
                curr++;
            }

            if( s.empty() ) printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}

