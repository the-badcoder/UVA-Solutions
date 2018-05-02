/// Bismillah Hir Rahmanir Rahim

/**
    Practice like Cristiano Ronaldo
        Play Like Leo Messi..
**/

#include <bits/stdc++.h>

using namespace std;

#define ff                    first
#define ss                    second
#define space                 " "
#define all(x)                (x).begin(), (x).end()
#define clr(ar)               memset(ar, 0, sizeof(ar))
#define eprintf(...)          fprintf(stderr, __VA_ARGS__)

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

#define sf1(a)                scanf("%d", &a)
#define sf2(a,b)              scanf("%d %d",&a, &b)
#define sf3(a,b,c)            scanf("%d %d %d", &a, &b, &c)
#define sf4(a,b,c,d)          scanf("%d %d %d %d", &a, &b, &c, &d)

#define READ                  freopen("in.txt", "r", stdin);
#define WRITE                 freopen("out.txt", "w", stdout);
/// The End.


const int res = 1e5 + 10;
const ll mod = 1e9 + 7;

int nodes;
vi graph[res];
vii bridges;
vi points;
int dfs_num[res], dfs_low[res], dfs_parent[res], rootChildren, dfsRoot, dfsNumberCounter, cc;
bool articulation_vertex[res];
int Rank[res], p[res];
vi setSize;
int numSets;

struct DisjointSet
{
    void make_set( int n )
    {
        numSets = n;       /// it will count number of disjointset.
        //setSize.assign(n, 1); /// initially setsize is 1;

        for( int i = 1; i <= n; i++ )
        {
            Rank[i] = 0;      /// at first time all rank  == 0;
            p[i] = i;         /// parent[i] == i;
        }
    }

    int findSet( int i )
    {
        return ( p[i] == i ) ? i : ( p[i] = findSet( p[i] ) ); /// Path Comperssions.
    }

    bool isSameSet( int i, int j )
    {
        return findSet(i) == findSet(j); /// return true or false;
    }

    void unionSet( int i, int j )
    {
        if( !isSameSet( i, j ) )
        {
            numSets--;
            int x = findSet( i ), y = findSet( j ); /// Finding Parents.

            if( Rank[x] > Rank[y] )
            {
                p[y] = x;
                //setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                //setSize[y] += setSize[x];

                if( Rank[x] == Rank[y] )
                {
                    Rank[y]++;
                }
            }
        }
    }

    int numofdisjointset()
    {
        return numSets;    /// Return component or numofdisjointset;
    }


} UF;

void reset();

void articulationPointAndBridge( int u )
{
    dfs_low[u] = dfs_num[u] = ++dfsNumberCounter;

    for( int i = 0; i < graph[u].size(); i++ )
    {
        int v = graph[u][i];

        if( dfs_num[v] == 0 )
        {
            dfs_parent[v] = u;

            if( u == dfsRoot )
            {
                rootChildren++;  // special case.
            }

            articulationPointAndBridge( v );

            dfs_low[u] = min( dfs_low[u], dfs_low[v] );

            if( dfs_low[v] >= dfs_num[u] )
            {
                articulation_vertex[u] = true; // for point.
            }
            if( dfs_low[v] > dfs_num[u] )
            {
                //printf("Edge (%d %d) is a bridge.\n", u, v ); // for bridge.
                bridges.push_back( { u, v } );
            }
        }
        else if( v != dfs_parent[u] )
        {
            dfs_low[u] = min( dfs_low[u], dfs_num[v] ); // a back edge and not direct cycle, update dfs_low[u].
        }
    }
}

int main()
{
    //WRITE;
    int edges, sum, total, test, loop = 0, q;
    bool newline = false;

    while( sf3( nodes, edges, q ) == 3 )
    {
        if( nodes == 0 and edges == 0 and q == 0 ){
            break;
        }
        if( newline )
        {
            printf("-\n");
        }
        newline = true;

        reset(); /// reset everything
        UF.make_set( nodes );

        while( edges-- )
        {
            int u, v;
            sf2( u, v );
            //u--, v--; // for 0 based.
            graph[u].push_back( v );
            graph[v].push_back( u );
        }

        for( int i = 1; i <= nodes; i++ ) // for bridges printing.
        {
            /// be carefull about 0 and 1 based index.
            if( dfs_num[i] == 0 )
            {
                dfsRoot = i;
                rootChildren = 0;
                articulationPointAndBridge( i );
                articulation_vertex[dfsRoot] = (rootChildren > 1);
            }
        }

        for( auto it: bridges )
        {
            int u = it.ff, v = it.ss;
            UF.unionSet( it.ff, it.ss );
        }

        while( q-- )
        {
            int u, v;
            sf2( u, v );
            if( UF.isSameSet( u, v ) )
            {
                printf("Y\n");
            }
            else {
                printf("N\n");
            }
        }
    }
}


void reset()
{
    for( int i = 1; i <= res; i++ )
    {
        graph[i].clear();
    }
    bridges.clear();
    memset( articulation_vertex, false, sizeof articulation_vertex );
    memset( dfs_num, 0, sizeof dfs_num );
    memset( dfs_low, 0, sizeof dfs_low );
    memset( dfs_parent, 0, sizeof dfs_parent );
    dfsNumberCounter = 0;
    dfsRoot = 0;
    cc = 0;
    rootChildren = 0;
}
