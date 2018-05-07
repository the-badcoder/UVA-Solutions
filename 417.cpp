/// Bismillah Hir Rahmanir Rahim

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair <int, int>;
using vii = vector<ii>;

#define ff                    first
#define ss                    second
#define sz(x)                 (x).size()
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

const int res = 1e6 + 10;
const ll mod = 1e9 + 7;

map <string, int> m;

void pre_calc()
{
    queue < string > q;
    int digit = 1;
    string s;

    for( char c = 'a'; c <= 'z'; c++ )
    {
        q.push( string( 1, c ) );
    }

    while( !q.empty() )
    {
        s = q.front();
        q.pop();

        m[ s ] = digit++;

        if( s.size() == 5 ){
            continue;
        }

        for( char c = s[ s.size() - 1 ] + 1; c <= 'z'; c++ )
        {
            //deb( c, s, s + c );
            q.push( s + c );
        }
    }
}

int main()
{
    pre_calc();

    string s;

    while( cin >> s )
    {
        if( m.find( s ) != m.end() )
        {
            printf("%d\n", m[ s ] );
        }
        else {
            printf("0\n");
        }
    }

    return 0;
}

