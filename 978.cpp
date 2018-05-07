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
   // WRITE;
    int test, n, sb, sg;
    bool newline = false;
    sf1( test );

    while( test-- )
    {
        if( newline )
        {
            printf("\n");
        }
        newline = true;

        priority_queue <int> blue, green;
        bool barmy = false, garmy = false;
        vector < pair <int, char> > v;
        sf3( n, sb, sg );

        for( int i = 0; i < sb; i++ )
        {
            int x;
            sf1( x );
            blue.push( x );
        }
        for( int i = 0; i < sg; i++ )
        {
            int x;
            sf1( x );
            green.push( x );
        }

        while( true )
        {
            if( blue.size() == 0 or green.size() == 0 )
            {
                break;
            }
            v.clear();
            for( int i = 0; i < n; i++ )
            {
                if( blue.empty() or green.empty() )
                {
                    break;
                }
                int x = blue.top();
                int y = green.top();
                blue.pop();
                green.pop();

                //deb("Hy", x, y );

                if( x > y )
                {
                    v.push_back( { x - y, 'b' } );
                }
                else if( y > x )
                {
                    v.push_back( { y - x , 'g' } );
                }
            }
            //deb("HY", v.size() );

            if( v.size() == 0 )
            {
                continue;
            }

            for( auto it: v )
            {
                if( it.ss == 'b' )
                {
                    blue.push( it.ff );
                }
                else
                {
                    green.push( it.ff );
                }
            }
        }

        //deb( blue.size(), green.size() );

        if( blue.size() == 0 and green.size() == 0 )
        {
            printf("green and blue died\n");
        }
        else if( blue.size() == 0 )
        {
            printf("blue wins\n");
            while( !green.empty() )
            {
                int x = green.top();
                green.pop();
                printf("%d\n", x );
            }
            //printf("\n");
        }
        else if( green.size() == 0 )
        {
            printf("green wins\n");
            while( !blue.empty() )
            {
                int x = blue.top();
                blue.pop();
                printf("%d\n", x );
            }
            //printf("\n");
        }

    }
    return 0;
}
