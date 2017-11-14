#include <bits/stdc++.h>
using namespace std;
int n, cs, k, cal, ans;
int a[1005], b[1005];
map < int, int > mp;
vector < int > cmprs;

int tr[5005];

 #define READ                  freopen("in.txt", "r", stdin);
    #define WRITE                 freopen("out.txt", "w", stdout);

int main()
{
    //READ;
    //WRITE;
    while( scanf( "%d", &n ) == 1 )
    {
        mp.clear();
        if( !n )
        {
            printf( "Case %d: 0\n", ++cs );
            continue;
        }
        if( n==-1 ) break;
        cmprs.clear();
        for( int i=0; i<n; i++ )
        {
            scanf( "%d %d", &a[i], &b[i] );
            cmprs.push_back( a[i] );
            cmprs.push_back( b[i] );
        }
        sort( cmprs.begin(), cmprs.end() );
        k = 0;
        for( int i=0; i<cmprs.size(); i++ )
        {
            if( mp[ cmprs[i] ] == 0 ) mp[ cmprs[i] ] = ++k;
        }
        memset( tr, 0, sizeof tr );
//        for( int i=0; i<cmprs.size(); i++ ) cout << cmprs[i] << ": " << mp[ cmprs[i] ] << "\n";
        for( int i=0; i<n; i++ )
        {
//            cout << a[i] << " " << b[i] << "\n";
//            cout << mp[ a[i] ] << " " << mp[ b[i] ] + 1 << "\n";
            tr[ mp[ a[i] ] ]++;
            tr[ mp[ b[i] ] + 1 ]--;
        }
        ans = 0;
        for( int i=1; i<=k; i++ )
        {
            tr[i] += tr[i-1];
            cal = tr[i];
            ans = max( cal, ans );
        }
        printf( "Case %d: %d\n", ++cs, ans );
    }
    return 0;
}
