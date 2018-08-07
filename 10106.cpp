#include <bits/stdc++.h>


using namespace std;
const int res = 600;
using ll = long long;

int main()
{
    string x, y;

    while( cin >> x )
    {
        cin >> y;
        reverse( x.begin(), x.end() );
        reverse( y.begin(), y.end() );
        int a[ res ];
        memset( a, 0, sizeof( a ) );

        for( int i = 0; i < x.length(); i++ )
        {
            for( int j = 0; j < y.length(); j++ )
            {
                a[ i + j ] += ( x[ i ] - '0' ) * ( y[ j ] - '0' );
                //cout << a[ i + j ] << endl;
            }
        }

        for( int i = 0; i < res - 1; i++ )
        {
            a[ i + 1 ] += a[ i ] / 10;
            a[ i ] %= 10;
        }

        int i = res - 1;
        while( i > 0 and a[ i ] == 0 ){
            i--;
        }
        for( ; i >= 0 ; i-- )
        {
            cout << a[ i ];
        }
        printf("\n");
    }


    return 0;
}
