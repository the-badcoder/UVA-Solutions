#include <bits/stdc++.h>

using namespace std;

#define WRITE freopen("output.txt", "w", stdout);

vector <int> graph[1000];
int nodes, edges, u, v, a, b, start, finish, comp, x, digit;
int dist[1000], visited[1000], path[10000];
string s, s1, ch, ch1;

void printpath( int u );
void reset();
void reset2();

void bfs( int n , int s )
{
    queue <int> q;
    q.push( s );

    visited[s] = 1;
    dist[s] = 1;
    path[s] = -1;

    while( !q.empty() )
    {
        u = q.front();
        q.pop();

        for( int i = 0; i < graph[u].size(); i++ )
        {
            if( visited[ graph[u][i] ] == 0 )
            {
                v = graph[u][i];
                visited[v] = 1;
                dist[v] = dist[u] + 1;
                path[v] = u;
                q.push( v );
            }
        }
    }

}

int main()
{
    //WRITE;
    int test, n, x, y, l, l1;
    map <string, int> m;

    cin >> test;

    while( test-- )
    {
       scanf("%d %d", &nodes, &edges);

        for( int i = 0; i < nodes; i++ )
        {
            cin >> s >> s1;

            x = s[0] - 65;
            y = s1[0] - 65;

            graph[x].push_back( y );
            graph[y].push_back( x );
        }

        for( int i = 0; i < edges; i++ )
        {
            cin >> ch >> ch1;
            reset();

            l = ch[0] - 65;
            l1 = ch1[0] - 65;

            start = l;
            bfs( nodes, start );
            printpath(l1);
            printf("\n");

        }
        if( test ) printf("\n");
        reset2();
    }

}

void printpath( int u )
{
    if( u == start )
    {
        printf("%c", u+65);
        return ;
    }
    printpath( path[u] );
    printf("%c", u+65 );
}

void reset()
{
    for( int i = 0; i < 1005; i++ ){
        visited[i] = 0;
        path[i] = 0;
        dist[i] = 0;
    }
}

void reset2()
{
    for( int i = 0; i < 1005; i++ ){
        graph[i].clear();
    }
}
