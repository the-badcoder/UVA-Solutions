#include <bits/stdc++.h>

using namespace std;

int L[1005][1005];

int LCS( string s, string s1, int m, int n )
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
    string s, s1;
    int len, len1, loop = 0;

    while( getline(cin, s) )
    {
        if( s == "#" )
        {
            break;
        }
        getline( cin, s1 );
        len = s.size();
        len1 = s1.size();

        printf("Case #%d: you can visit at most %d cities.\n", ++loop, LCS(s, s1, len, len1));

    }
    return 0;
}
