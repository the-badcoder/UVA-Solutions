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

#define sf1ll(a)              scanf("%I64d", &a)
#define sf2ll(a,b)            scanf("%I64d %I64d", &a, &b)
#define sf3ll(a,b,c)          scanf("%I64d %I64d %I64d", &a, &b, &c)

#define READ                  freopen("input.txt", "r", stdin);
#define WRITE                 freopen("output.txt", "w", stdout);
/// The End.

#define DFS_BLACK 1
#define DFS_WHITE 0

const int maxn = 1e6 + 5;
vector <int> Ts, graph[maxn];
bool used[maxn], color[maxn], used1[maxn];
bool Hascycle;

void dfs( int v );
void reset( int n );

void dfs2( int u )
{
    used1[u] = color[u] = DFS_BLACK;

    for( int i = 0; i < graph[u].size(); i++ )
    {
        if( color[ graph[u][i] ] )
        {
            Hascycle = true;
            return;
        }
        else if( used1[ graph[u][i] ] == DFS_WHITE )
        {
            dfs2( graph[u][i] );
        }
    }
    color[u] = 0;
}

int main()
{
    int nodes, edges, u, v, a, b;

    while( sf2( nodes, edges )  )
    {
        reset( nodes );
        if( nodes == 0 && edges == 0 )
        {
            break;
        }
        Ts.clear();
        memset( used, 0, sizeof used );
        memset( used1, 0, sizeof used1 );
        memset( color, 0, sizeof color );

        for( int i = 0; i < edges; i++ )
        {
            sf2( u, v );

            graph[u].push_back( v );
        }
        for( int i = 1; i <= nodes; i++ )
        {
            if( used[i] == false )
            {
                dfs(i);
                dfs2(i);
            }
        }

        if( Hascycle == true )
        {
            printf("IMPOSSIBLE\n");
        }
        else
        {
            reverse( all( Ts ) );

            printf("%d\n", Ts[0] );
            for( int i = 1; i < Ts.size(); i++ )
            {
                printf("%d\n", Ts[i] );
            }
            //cout << endl;
        }
        //Ts.clear();
    }
    return 0;
}

void dfs( int v )
{
    used[v] = true;

    for( auto i: graph[v] )
    {
        if( used[i] == DFS_WHITE )
        {
            dfs( i );
        }
    }
    Ts.push_back( v );
}

void reset( int n )
{
    Hascycle = false;
    for( int i = 1; i <= n; i++ )
    {
        graph[i].clear();
    }
}
