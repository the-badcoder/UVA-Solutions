#include <bits/stdc++.h>

/// Kahn's Algorithm Topological Sort B| :D

using namespace std;
const int res = 1e5 + 5;

int in_degree[110];
vector <int> graph[250], topsort;

int main()
{
    int v, e, loop = 0;
    //freopen("output.txt", "w", stdout);

    while( scanf("%d", &v) != EOF )
    {
        memset( in_degree, 0, sizeof in_degree );
        string s, x;
        for( int i = 0; i <= 250; i++ )
        {
            graph[i].clear();
        }
        map < string, int > m;
        map < int, string > mm;

        for( int i = 0; i < v; i++ )
        {
            cin >> s;
            m[ s ] = i;
            mm[ i ] = s;
        }

        scanf("%d", &e );

        for( int i = 0; i < e; i++ )
        {
            string a, b;
            cin >> a >> b;

            graph[ m[a] ].push_back( m[b] );
            in_degree[ m[b] ]++;
        }

        priority_queue<int, vector <int>, greater<int> > q;
        // enqueue nodes with 0 incoming degree into priority queue.

        for( int i = 0; i < v; i++ )
        {
            if( in_degree[i] == 0 )
            {
                q.push( i );
            }
        }

        while( !q.empty() )
        {
            int u = q.top();
            topsort.push_back( u );
            q.pop();

            for( int i = 0; i < graph[u].size(); i++ )
            {
                int v = graph[u][i];
                //remove all outgoing edges from the vertex u;
                in_degree[v]--;
                // if such removal cause vertex v to have 0 incoming degree
                // enqueue it
                if( in_degree[v] == 0 )
                {
                    q.push( v );
                }
            }
        }

        printf("Case #%d: Dilbert should drink beverages in this order:", ++loop );

        for( auto it: topsort )
        {
            cout << " " << mm[ it ];
        }
        printf(".\n\n");
        topsort.clear();

    }
    return 0;
}
