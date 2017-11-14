/// Bismillah Hir Rahmanir Rahim

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <math.h>
#include <ctime>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;


#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define ff                    first
#define ss                    second
#define mp                    make_pair
#define pb                    push_back
#define eb                    emplace_back
#define mod                   1e7
#define EPS                   1e-9
#define INF                   INT_MAX
#define space                 " "
#define all(x)                (x).begin(), (x).end()
#define clr(ar)               memset(ar, 0, sizeof(ar))
#define DFS_BLACK             1
#define DFS_WHITE             0

/*
template <class T> T gcd(T a,T b){ if(b == 0) return a; return gcd( b,a % b ); }
template <class T> T lcm(T a, T b ){ return ( a * b ) / gcd( a,b ); }
template<class T> string ToString(const T &x){ stringstream s; s << x; return s.str(); }
template<class T> int ToInteger(const T &x){ stringstream s; s << x; int r; s >> r; return r; }
*/

const int dr[] = { -1, 1, 0, 0 }; /// 4 side moves.
const int dc[] = { 0, 0, -1, 1 };
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 }; /// 8 side moves.
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

typedef  long long int           ll;
typedef  map<string,int>         msi;
typedef  map<string, string>     mss;
typedef  map<int,int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<char,int>           mci;
typedef  map<int,string>	     mis;
typedef  pair<int,int> 	         ii;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef  vector<int> 	         vi;
typedef  vector<string> 	     vs;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  vector< ii >            vii;

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

char grid[1010][1010];
bool used[1010][1010];
int dist[1010][1010];
queue < ii > q;

int R, C, nodes, edges, rstart, cstart, endr, endc;

void bfs( int m, int n )
{
    used[m][n] = 1;
    dist[m][n] = 0;
    q.push( { m, n } );

    while( !q.empty() )
    {
        ii u = q.front();
        q.pop();

        for( int i = 0; i < 4; i++ )
        {
            int r = u.ff + dr[i];
            int c = u.ss + dc[i];
            //deb( r, c );

            //if( r < 0 || r >= R || c < 0 || c >= C ) return;

            if( (r >= 0 && r < R && c >= 0 && c < C ) && grid[r][c] != 'X' && used[r][c] == 0 )
            {
                used[r][c] = 1;
                dist[r][c] = dist[u.ff][u.ss] + 1;
                q.push( { r, c } );

            }
        }
    }

}


int main()
{

    while( sf2( R, C ) && R || C )
    {
        sf1( nodes );

        clr( used );
        clr( dist );
        clr( grid );

        for( int i = 0; i < nodes; i++ )
        {
            int x, bomb;
            sf2( x, bomb );

            while( bomb-- )
            {
                int y;
                sf1( y );
                grid[x][y] = 'X';
            }
        }
        sf2( rstart, cstart );
        bfs( rstart, cstart );
        sf2( endr, endc );

        deb(dist[endr][endc]);
    }
}


