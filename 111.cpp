#include <bits/stdc++.h>

using namespace std;

int lcs[100][100];

int main()
{
    int n, m, i, j, x[30], y[30];

    scanf("%d", &n);

    for( int i = 0; i < n; ++i )
    {
        scanf("%d", &m);

        x[ m - 1 ] = i;
    }

    while( scanf("%d", &m) != EOF )
    {
        y[ m - 1 ] = 0;
        for( i = 1; i < n; ++i )
        {
            scanf("%d", &m);
            y[ m - 1 ] = i;
        }

        for( int i = 0; i <= n; i++ )
        {
            for( int j = 0; j <= n; j++ )
            {
                if( i == 0 || j == 0 )
                {
                    lcs[i][j] = 0;
                }
                else if( x[ i - 1] == y[ j - 1] )
                {
                    lcs[i][j] = lcs[ i - 1 ][ j - 1 ] + 1;
                }
                else
                {
                    lcs[i][j] = max( lcs[i-1][j], lcs[i][j-1] );
                }
            }
        }
        printf("%d\n", lcs[n][n] );
    }
    return 0;

}


