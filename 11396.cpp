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

vector <int> graph[310];
bool visited[305], color[305];
bool flag = true;
int u, v, a, b;

bool bfs( int start )
{
    queue <int> q;
    q.push( start );

    visited[start] = true;

    while( !q.empty() )
    {
        u = q.front();
        q.pop();

        for( int i = 0; i < graph[u].size(); i++ )
        {
            v = graph[u][i];

            if( visited[v] == false )
            {
                color[v] = 1 - color[u];
                q.push( v );
                visited[v] = 1;
            }
            else if( color[v] == color[u] )
            {
                flag = false;
                break;
            }

        }
    }
    return flag;
}

void reset( int n )
{
    for( int i = 1; i <= n; i++ )
    {
        graph[i].clear();
    }
}

int main()
{
    int nodes, edges;
    while( sf1(nodes) && nodes != 0 )
    {
        reset( nodes );
        flag = true;

        while( scanf("%d %d",&a, &b) && (a != 0 || b != 0) )
        {
            graph[a].push_back( b );
            graph[b].push_back( a );
        }

        //memset( visited, 0, sizeof( visited) );
        memset( visited, 0, sizeof visited );
        memset( color, 0, sizeof color );

        bfs( 1 );

        if( flag )
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
