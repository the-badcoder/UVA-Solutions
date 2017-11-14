#include <bits/stdc++.h>

using namespace std;

const int res = 1e5 + 10;
//using ll = long long;

int a[res], tree[ res * 4 ], ans;

void build( int node, int b, int e )
{
    if( b == e )
    {
        tree[node] = a[b];
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = ( b + e ) / 2;
    build( left, b, mid );
    build( right, mid + 1, e );
    tree[node] = tree[left] * tree[right];
}

int query( int node, int b, int e, int i, int j )
{
    if( i > e || j < b )
    {
        return 1;
    }
    if( b >= i && e <= j )
    {
        return tree[node];
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = ( b + e ) / 2;
    int p1 = query( left, b, mid, i, j );
    int p2 = query( right, mid + 1, e, i, j );
    return p1 * p2;
}

void update( int node, int b, int e, int i, int value )
{
    if( i > e || i < b )
    {
        return;
    }
    if( b >= i && e <= i )
    {
        tree[node] = value;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = ( b + e ) / 2;
    update( left, b, mid, i, value );
    update( right, mid + 1, e, i, value );
    tree[node] = tree[left] * tree[right];
}

void reset()
{
    memset( tree, 0, sizeof tree );
    memset( a, 0, sizeof a );
}

int main()
{
    int test, n, q, loop = 0;

    while( scanf("%d %d",&n, &q ) != EOF )
    {
        reset();
        for( int i = 1; i <= n; i++ )
        {
            int x;
            scanf("%d", &x);
            if( x > 0 ) a[i] = 1;
            else if( x < 0 ) a[i] = -1;
            else if( x == 0 ) a[i] = 0;
        }

        build( 1, 1, n );

        for( int i = 1; i <= q; i++ )
        {
            int x, y;
            string s;
            cin >> s;
            scanf("%d%d", &x, &y );

            if( s == "C" )
            {
                if( y > 0 ) y = 1;
                else if( y < 0 ) y = -1;
                else y = 0;
                update( 1, 1, n, x, y );
            }

            if( s == "P" )
            {
                int ret = query( 1, 1, n, x, y );

                if( ret == 0 ){
                    printf("0");
                }
                if( ret > 0 ){
                    printf("+");
                }
                if( ret < 0 ){
                    printf("-");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
