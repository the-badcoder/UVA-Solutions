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

void check_time()
{
#ifdef the_badcoder
    eprintf("%.5lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}

const int res = 1e5 + 10;
const ll mod = 1e9 + 7;

int n, sum, total, ans, commando, loop;
vii v;
vi need;

void reset()
{
    v.clear();
    need.clear();
    ans = sum = total = 0;
}

int main()
{
    //WRITE;
    while( sf1( n ) && n )
    {
        reset();
        for( int i = 0; i < n; i++ )
        {
            int a, b;
            sf2( a, b );
            v.push_back( { b, a } );
            sum += a;
        }

        sort( all( v ) );
        reverse( all( v ) );

        if( v.size() == 1 )
        {
            printf("Case %d: %d\n", ++loop, v[0].ff + v[0].ss );
            continue;
        }

        if( v.size() == 2 )
        {
            ans += v[0].ss;
            ans += v[1].ss;

            if( v[0].ff > v[1].ss )
            {
                int temp = v[0].ff - v[1].ss;
                need.push_back( temp );
            }
            need.push_back( v[1].ff );
            ans += *max_element( all( need ) );
            printf("Case %d: %d\n", ++loop, ans );
            continue;
        }


        if( v[0].ff > v[1].ss )
        {
            int temp = v[0].ff - v[1].ss;
            need.push_back( temp );
        }
        need.push_back( v[1].ff );

        for( int i = 2; i < v.size(); i++ )
        {
            sort( all( need ) );
            need.erase( unique( all( need ) ), need.end() );
            int maxi = *max_element( all( need ) );

            //deb( v[i].ss, v[i].ff, maxi );

            if( maxi > v[i].ss )
            {
                int temp = maxi - v[i].ss;
                need.clear();
                need.push_back( temp );
                //need.erase( remove( all( need ), maxi ), need.end() );
            }
            else
            {
                need.clear();
            }
            need.push_back( v[i].ff );
        }

        int maxi = *max_element( all( need ) );
        sum += maxi;
        printf("Case %d: %d\n", ++loop, sum );
    }



    return 0;
}

