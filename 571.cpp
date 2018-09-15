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


int main()
{
    //freopen("out.txt", "w", stdout);
    int a, b, n;

    while( sf3( a, b, n ) == 3 )
    {
        if( a == n and b == n )
        {
            printf("fill A\n");
            printf("success\n");
        }
        else if( a == n )
        {
            printf("fill A\n");
            printf("success\n");
        }
        else if( b == n )
        {
            printf("fill B\n");
            printf("success\n");
        }
        else if( a > n and b > n )
        {
            int maxi = max( a, b );
            int x = 0, y = 0;

            if( a != maxi )
            {
                x = a, y = 0;
                printf("fill A\n");
                x = 0, y = a;
                printf("pour A B\n");
                x = a, y = a;
                printf("fill A\n");

                while( x != n or y != n )
                {
                    while( true )
                    {
                        y++;
                        x--;
                        if( x == 0 or y == b ) break;
                    }

                    printf("pour A B\n");

                    if( x == n or y == n )
                    {
                        printf("success\n");
                        break;
                    }

                    if( x == 0 )
                    {
                        printf("fill A\n");
                        x = a;
                    }
                    else
                    {
                        y = 0;
                        printf("empty B\n");
                    }
                }
            }
            else {
                x = 0, y = b;
                printf("fill B\n");
                x = b, y = 0;
                printf("pour B A\n");
                x = b, y = b;
                printf("fill B\n");

                while( x != n or y != n )
                {
                    while( true )
                    {
                        y--;
                        x++;
                        if( x == a or y == 0 ) break;
                    }

                    printf("pour B A\n");

                    if( x == n or y == n )
                    {
                        printf("success\n");
                        break;
                    }

                    if( y == 0 )
                    {
                        printf("fill A\n");
                        y = b;
                    }
                    else
                    {
                        x = 0;
                        printf("empty A\n");
                    }
                }
            }
        }
        else
        {
            int maxi = max( a, b );
            int x = 0, y = 0;

            if( b == maxi )
            {
                y = b, x = 0;
                printf("fill B\n");
                while( x != n or y != n )
                {
                    while( true )
                    {
                        x++;
                        y--;
                        if( x == a or y == 0 ) break;
                    }
                    printf("pour B A\n");
                    if( x == n or y == n )
                    {
                        printf("success\n");
                        break;
                    }
                    if( y == 0 )
                    {
                        printf("fill B\n");
                        y = b;
                    }
                    else
                    {
                        x = 0;
                        printf("empty A\n");
                    }
                }
            }
            else
            {
                x = a, y = 0;
                printf("fill A\n");

                while( x != n or y != n )
                {
                    while( true )
                    {
                        x--;
                        y++;
                        if( x == 0 or y == b ) break;
                    }
                    printf("pour A B\n");
                    if( x == n or y == n )
                    {
                        printf("success\n");
                        break;
                    }
                    if( x == 0 )
                    {
                        printf("fill A\n");
                        x = a;
                    }
                    else
                    {
                        y = 0;
                        printf("empty B\n");
                    }
                }
            }
        }
    }

    return 0;
}

