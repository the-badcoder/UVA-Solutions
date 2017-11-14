#include <bits/stdc++.h>

using namespace std;

int L[200][200];

int main()
{
    vector < string > a, b;
    string s, s1, X, Y;

    while( !cin.eof() )
    {
        a.clear();
        b.clear();

        while( cin >> X && X[0] != '#' )
        {
            a.push_back( X );
        }

        while( cin >> Y && Y[0] != '#' )
        {
            b.push_back( Y );
        }

        int m = a.size();
        int n = b.size();

        for( int i = 0; i <= m; i++ )
        {
            for( int j = 0; j <= n; j++ )
            {
                if( i == 0 or j == 0 )
                {
                    L[i][j] = 0;
                }

                else if( a[i-1] == b[j-1] )
                {
                    L[i][j] = L[i-1][j-1] + 1;
                }

                else
                {
                    L[i][j] = max( L[i-1][j], L[i][j-1] );
                }
            }
        }

        vector < string > v( 200 );
        int indx = L[m][n];
        int i = m, j = n;

        while( i > 0 and j > 0 )
        {
            if( a[i-1] == b[j-1] )
            {
                v[indx-1] = a[i-1];
                i--;
                j--;
                indx--;
            }

            else if( L[i-1][j] >= L[i][j-1] )
            {
                i--;
            }
            else
            {
                j--;
            }
        }

        for( int i = 0; i < L[m][n]; i++ )
        {
            if( i > 0 and i < L[m][n] )
            {
                cout << " ";
            }
            cout << v[i];

            if( i == L[m][n] - 1 )
            {
                printf("\n");
            }


        }
    }


    return 0;
}
