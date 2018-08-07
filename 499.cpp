#include <bits/stdc++.h>


using namespace std;
const int res = 600;
using ll = long long;

int main()
{
    string s;

    while( getline( cin, s ) )
    {
        int upCase[ 64 ] = { 0 }, lowCase[ 64 ] = { 0 };

        for( int i = 0; i < s.size(); i++ )
        {
            char ch = s[ i ];
            if( ch >= 'A' and ch <= 'Z' )
            {
                upCase[ ch - 'A' ]++;
            }
            else if( ch >= 'a' and ch <= 'z' )
            {
                lowCase[ ch - 'a' ]++;
            }
        }
        int maxi = 0;

        for( int i = 0; i < 26; i++ )
        {
            if( upCase[ i ] > maxi )
            {
                maxi = upCase[ i ];
            }
            if( lowCase[ i ] > maxi )
            {
                maxi = lowCase[ i ];
            }
            //cout << "HY " << maxi << " " << i + 'A' << " " << i + 'a' << endl;
        }

        for( int i = 0; i < 26; i++ )
        {
            if( upCase[ i ] == maxi )
            {
                printf("%c", 'A' + i );
            }
        }
        for( int i = 0; i < 26; i++ )
        {
            if( lowCase[ i ] == maxi )
            {
                printf("%c", 'a' + i );
            }
        }
        printf(" %d\n", maxi );
    }
}
