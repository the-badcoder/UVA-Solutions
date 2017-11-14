#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int weight[1002], cost[1002], n , cap;
int dp[1002][55];

int knapsack( int i, int w )
{
    if( i >= n )
        return 0;

    if( dp[i][w] != -1 )
        return dp[i][w];

    int taka1 = 0, taka2 = 0;

    if( w + weight[i] <= cap )
    {
        taka1 = cost[i] + knapsack( i + 1, w + weight[i] );
        //cout << taka1 << endl;
    }

    taka2 = knapsack( i + 1, w );
    //cout << taka2 << endl;

    dp[i][w] = max( taka1, taka2 );

    return dp[i][w];
}
int main()
{
    int test, x, sum, total, q;

    scanf("%d", &test );

    while( test-- )
    {
        scanf("%d", &n );

        for( int i = 0; i < n; i++ )
        {
            scanf("%d %d", &cost[i], &weight[i] );
        }

        sum = 0;

        scanf("%d", &q );

        for( int i = 0; i < q; i++ )
        {
            scanf("%d", &cap );

            memset( dp, -1, sizeof dp );
            sum += knapsack( 0, 0 );
        }

        printf("%d\n", sum );
    }
    return 0;
}
