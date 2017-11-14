#include <bits/stdc++.h>

using namespace std;

#define DFS_BLACK 1
#define DFS_WHITE 0

const int maxn = 3e4 + 10;
vector <int> graph[105];
vector <int> topoSort;
bool used[105];

void reset();

void dfs( int u )
{
    used[u] = DFS_BLACK;

    for( auto to: graph[u] )
    {
        if( used[to] == DFS_WHITE )
        {
            dfs( to );
        }
    }
    topoSort.push_back( u );
}

int main()
{
    int n, m, u, v;

    while( scanf("%d %d", &n, &m) == 2 )
    {
        memset( used, 0, sizeof used );
        topoSort.clear();
        reset();

        if( n == 0 && m == 0 )
        {
            break;
        }

        for( int i = 0; i < m; i++ )
        {
            scanf("%d %d", &u, &v );
            graph[u].push_back( v );
        }

        for( int i = 1; i <= n; i++ )
        {
            if( used[i] == DFS_WHITE )
            {
                dfs(i);
            }
        }
        reverse( topoSort.begin(), topoSort.end() );

        printf("%d", topoSort[0] );

        for( int i = 1; i < topoSort.size(); i++ )
        {
            printf(" %d", topoSort[i] );
        }
        printf("\n");
    }
}

void reset()
{
    for( int i = 0; i < 105; i++ )
    {
        graph[i].clear();
    }
}
