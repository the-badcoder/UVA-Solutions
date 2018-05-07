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

int main()
{
    int test, a, b, c, loop = 0;

    sf1( test );

    while( test-- && sf3( a, b , c ) )
    {
        set<int> leju, rony, sujon;
        int lYes = 0, rYes = 0, sYes = 0, lNo = 0, rNo = 0, sNo = 0;

        for( int i = 0; i < a; i++ )
        {
            int x;
            sf1( x );
            leju.insert( x );
        }
        for( int i = 0; i < b; i++ )
        {
            int x;
            sf1( x );
            rony.insert( x );
        }
        for( int i = 0; i < c; i++ )
        {
            int x;
            sf1( x );
            sujon.insert( x );
        }

        for( auto it: leju )
        {
            if( ( rony.find( it ) == rony.end() ) and ( sujon.find( it ) == sujon.end() ) )
            {
                lYes++;
            }
            else if( ( rony.find( it ) == rony.end() ) and ( sujon.find( it ) != sujon.end() ) )
            {
                rNo++;
            }
            else if( ( rony.find( it ) != rony.end() ) and ( sujon.find( it ) == sujon.end() ) )
            {
                sNo++;
            }
        }

        for( auto it: rony )
        {
            if( ( leju.find( it ) == leju.end() ) and ( sujon.find( it ) == sujon.end() ) )
            {
                rYes++;
            }
            else if( ( leju.find( it ) == leju.end() ) and ( sujon.find( it ) != sujon.end() ) )
            {
                lNo++;
            }
            else if( ( leju.find( it ) != leju.end() ) and ( sujon.find( it ) == sujon.end() ) )
            {
                sNo++;
            }
        }
        for( auto it: sujon )
        {
            if( ( rony.find( it ) == rony.end() ) and ( leju.find( it ) == leju.end() ) )
            {
                sYes++;
            }
            else if( ( rony.find( it ) == rony.end() ) and ( leju.find( it ) != leju.end() ) )
            {
                rNo++;
            }
            else if( ( rony.find( it ) != rony.end() ) and ( leju.find( it ) == leju.end() ) )
            {
                lNo++;
            }
        }

        printf("Case #%d:\n", ++loop );
        printf("%d %d\n%d %d\n%d %d\n", lYes, lNo / 2, rYes, rNo / 2, sYes, sNo / 2 );



    }
    return 0;
}
