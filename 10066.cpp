#include <bits/stdc++.h>

using namespace std;

int L[1005][1005];

int LCS( int s[], int s1[], int m, int n )
{
    int L[m+1][n+1];
    int i, j;

    for( int i = 0; i <= m; i++ )
    {
        for( int j = 0; j <= n; j++ )
        {
            if( i == 0 || j == 0 )
            {
                L[i][j] = 0;
            }
            else if( s[i-1] == s1[j-1] )
            {
                L[i][j] = L[i-1][j-1] + 1;
            }
            else
            {
                L[i][j] = max( L[i-1][j], L[i][j-1] );
            }
        }
    }
    return L[m][n];
}

int main()
{
    int n, m, loop = 0, digit, a[101], b[101];

    while( cin >> n >> m && n || m )
    {
        for( int i = 0; i < n; i++ )
        {
            cin >> a[i];
        }
        for( int i = 0; i < m; i++ )
        {
            cin >> b[i];
        }
        printf("Twin Towers #%d\n", ++loop );
        printf("Number of Tiles : %d\n\n", LCS( a, b, n, m ));
    }
    return 0;
}
