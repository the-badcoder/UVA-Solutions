/// Bismillah Hir Rahmanir Rahim

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair <int, int>;
using vii = vector<ii>;

#define ff                    first
#define ss                    second
#define pb                    push_back
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

void check_time()
{
#ifdef the_badcoder
    eprintf("%.5lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}

const int res = 900;
const ll mod = 1e9 + 7;

bool check( string s, int n )
{
    ll rem = 0;

    for( int i = 0; i < s.size(); i++ )
    {
        rem = ( rem * 10 + s[i] - '0' ) % n;
    }
    if( rem == 0 )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    string s;
    bool flag = false;

    while( cin >> s )
    {
        if( flag == true )
        {
            printf("\n");
        }
        flag = true;

        int lp = 0 , hf = 0, bf = 0;

        if( check( s, 4 ) == 0 && check( s, 100 ) == 1 || check( s, 400 ) == 0 )
        {
            lp = 1;
            printf("This is leap year.\n");
        }
        if( check( s, 15 ) == 0 )
        {
            hf = 1;
            printf("This is huluculu festival year.\n");
        }
        if( lp == 1 && check( s, 55 ) == 0 )
        {
            bf = 1;
            printf("This is bulukulu festival year.\n");
        }
        if( lp == 0 and bf == 0 and hf == 0 )
        {
            printf("This is an ordinary year.\n");
        }

    }
    return 0;
}

