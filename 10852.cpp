
/// Bismillah Hir Rahmanir Rahim

#include <bits/stdc++.h>

using namespace std;

#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define ff                    first
#define ss                    second
#define mp                    make_pair
#define pb                    push_back
#define eb                    emplace_back
#define mod                   1e7
#define INF                   2147483647
#define space                 " "
#define all(x)                (x).begin(), (x).end()
#define clr(ar)               memset(ar, 0, sizeof(ar))

/*
template <class T> T gcd(T a,T b){ if(b == 0) return a; return gcd( b,a % b ); }
template <class T> T lcm(T a, T b ){ return ( a * b ) / gcd( a,b ); }
template<class T> string ToString(const T &x){ stringstream s; s << x; return s.str(); }
template<class T> int ToInteger(const T &x){ stringstream s; s << x; int r; s >> r; return r; }
*/


typedef  long long int           ll;
typedef  map<string,int>         msi;
typedef  map<int,int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<char,int>           mci;
typedef  map<int,string>	     mis;
typedef  pair<int,int> 	         pii;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef  vector<int> 	         vi;
typedef  vector<string> 	     vs;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  vector< pii >           vii;


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

#define READ                  freopen("input.txt", "r", stdin);
#define WRITE                 freopen("output.txt", "w", stdout);
/// The End.

const int sz = 1e7 + 7;
bool flag[sz];

vector <ll> primes;

void seive( int n )
{
    memset( flag , true, sizeof( flag ) );
    flag[0] = flag[1] = true;

    for( int i = 4; i <= n; i += 2 )
    {
        flag[i] = false;
    }

    for( int i = 3; i*i <= n; i += 2 )
    {
        if( flag[i] == true )
        {
            for( int j = i * i; j <= n; j += 2 * i )
            {
                flag[j] = false;
            }
        }
    }
}

int main()
{
    int n, sum, lprime, total, test;

    cin >> test;

    while( test-- )
    {
        cin >> n;
        seive( n );

        sum =  ( n / 2 ) + 1;

        //cout << sum << endl;

        for( int i = 1; i <= n; i++ )
        {
            if( i >= sum )
            {
                if( flag[i]== true )
                {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}

