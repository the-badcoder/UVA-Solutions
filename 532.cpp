#include <bits/stdc++.h>

using namespace std;

#define clr(ar)      memset(ar, 0, sizeof(ar))
#define sf3(a,b,c)   scanf("%d %d %d", &a, &b, &c)

char grid[35][35][35];
bool used[35][35][35];
int cost[35][35][35];

int fr[] = { 0, 0, 0, 0, 1, -1 };
int fc[] = { -1, 0, 1, 0, 0, 0 };
int fy[] = { 0, 1, 0, -1, 0, 0 };

int L, R, C, xx, yy, zz;

void bfs( int m, int n, int o )
{
    queue < pair < int, pair < int, int > > > q;

    q.push( make_pair( m, make_pair( n, o )  ) );

    used[m][n][o] = 1;
    cost[m][n][o] = 0;

    while( !q.empty() )
    {
        pair < int, pair <int, int > >  u = q.front();
        q.pop();

        xx = u.first;
        yy = u.second.first;
        zz = u.second.second;

        for( int i = 0; i < 6; i++ )
        {
            int x = xx + fr[i];
            int y = yy + fc[i];
            int z = zz + fy[i];

            if( ( x >= 0 && x < L ) && (y >= 0 && y < R ) && (z >= 0 && z < C ) && (grid[x][y][z] != '#') && (used[x][y][z] == 0) )
            {
                used[x][y][z] = 1;
                cost[x][y][z] = cost[xx][yy][zz] + 1;
                q.push( make_pair( x, make_pair( y, z ) )  );
            }
        }
    }
}


int main()
{
    int i1, i2, i3, d1, d2, d3;

    while( sf3( L, R, C ) && ( L || R || C ) )
    {
        for( int i = 0; i < L; i++ )
        {
            for( int j = 0; j < R; j++ )
            {
                for( int k = 0; k < C; k++ )
                {
                    cin >> grid[i][j][k];

                    if( grid[i][j][k] == 'S' )
                    {
                        i1 = i, i2 = j, i3 = k;
                    }
                    if( grid[i][j][k] == 'E' )
                    {
                        d1 = i, d2 = j, d3 = k;
                    }
                }
            }
        }

        bfs( i1, i2, i3 );

        if( cost[d1][d2][d3] == 0)
        {
            printf("Trapped!\n");
        }
        else
        {
            printf("Escaped in %d minute(s).\n", cost[d1][d2][d3]);
        }

        clr( used );
        clr( cost );
    }

    return 0;

}

