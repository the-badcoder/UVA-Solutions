#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

/// Approach: Varient Of Floyd-Warshall.

int main()
{
    int V, E, u, v, w, Q, Graph[106][106], loop = 0;

    while( scanf("%d %d %d", &V, &E, &Q ) && ( V || E|| Q ) )
    {
        for (int i = 1; i <= V; i++)
        {
            for (int j = 1; j <= V; j++)
                Graph[i][j] = INF;
            Graph[i][i] = 0;
        }

        for (int i = 1; i <= E; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            Graph[u][v] = Graph[v][u] = w;
        }

        for (int k = 1; k <= V; k++)  // common error: remember that loop order is k->i->j
        {
            for (int i = 1; i <= V; i++)
            {
                for (int j = 1; j <= V; j++)
                {
                    Graph[i][j] = min( Graph[i][j], max( Graph[i][k], Graph[k][j] ) );
                }
            }
        }

        if( loop != 0 )
        {
            printf("\n");
        }
        printf("Case #%d\n", ++loop );

        while( Q-- )
        {
            int s, d;
            scanf("%d %d", &s, &d );

            if( Graph[s][d] == INF )
            {
                printf("no path\n");
            }
            else
            {
                printf("%d\n", Graph[s][d] );
            }
        }
    }
    return 0;
}
