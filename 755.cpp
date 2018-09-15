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

char convert( char ch )
{
    if( ch == 'A' or ch == 'B' or ch == 'C' ) return '2';
    else if( ch == 'D' or ch == 'E' or ch == 'F' ) return '3';
    else if( ch == 'G' or ch == 'H' or ch == 'I' ) return '4';
    else if( ch == 'J' or ch == 'K' or ch == 'L' ) return '5';
    else if( ch == 'M' or ch == 'N' or ch == 'O' ) return '6';
    else if( ch == 'P' or ch == 'R' or ch == 'S' ) return '7';
    else if( ch == 'T' or ch == 'U' or ch == 'V' ) return '8';
    else if( ch == 'W' or ch == 'X' or ch == 'Y' ) return '9';
}


int main()
{
#ifdef LM10
    //freopen("in.txt", "r", stdin );
    //freopen("out.txt", "w", stdout );
#endif // LM10

    int test, n;
    bool isLine = false;

    sf1( test );

    while( test-- && sf1( n ) )
    {
        getchar();
        vector < pair < string, int > > v;
        map < string, int > m;
        set < pair < string, int > > st;

        if( isLine == true ) printf("\n");
        isLine = true;

        while( n-- )
        {
            string s;
            cin >> s;

            string temp = "";
            for( int i = 0; i < s.size(); i++ )
            {
                char ch = s[ i ];
                if( ch == '-' )
                {
                    continue;
                }
                if( isalpha( ch ) )
                {
                    temp += convert( ch );
                }
                else
                {
                    temp += ch;
                }
            }
            m[ temp ]++;
        }

        for( auto it: m )
        {
            if( it.ss == 1 ) continue;
            string temp = "";

            for( int i = 0; i < 3; i++ )
            {
                temp += it.ff[i];
            }
            temp += "-";
            for( int i = 3; i < 7; i++ )
            {
                temp += it.ff[i];
            }
            v.push_back( { temp, it.ss } );

            //cout << temp << space << temp.size() << endl;
        }

        if( v.size() == 0 ) printf("No duplicates.\n");
        else
        {
            for( auto it: v ) deb( it.ff, it.ss );
        }
    }


    return 0;
}

