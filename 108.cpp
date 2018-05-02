#include <bits/stdc++.h>

using namespace std;

#define READ                   freopen("input.txt", "r", stdin);
#define WRITE                  freopen("output.txt", "w", stdout);
#define space                  " "
#define clr(ar)                memset( ar, 0, sizeof ar )

#define sf1(a)                scanf("%d", &a)
#define sf2(a,b)              scanf("%d %d",&a, &b)
#define sf3(a,b,c)            scanf("%d %d %d", &a, &b, &c)

#define sf1ll(a)              scanf("%lld", &a)
#define sf2ll(a,b)            scanf("%lld %lld", &a, &b)
#define sf3ll(a,b,c)          scanf("%lld %lld %lld", &a, &b, &c)

template<class T1> void deb(T1 e1)
{
    cout << e1 << endl;
}
template<class T1,class T2> void deb(T1 e1, T2 e2)
{
    cout << e1 << space << e2 << endl;
}
template<class T1,class T2,class T3> void deb(T1 e1, T2 e2, T3 e3)
{
    cout << e1 << space << e2 << space << e3 << endl;
}

using ll = long long;
const int res = 1e5 + 10;

void reset();
int n, sum, total, ans, a[105][105], digit;

int main()
{
    sf1( n );

    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < n; j++ )
        {
            sf1( a[i][j] );
            if( j > 0 )
            {
                a[i][j] += a[i][j-1];
            }
        }
    }

    int maxi = INT_MIN;

    for( int l = 0; l < n; l++ )
    {
        for( int r = l; r < n; r++ )
        {
            sum = 0;
            for( int i = 0; i < n; i++ )
            {
                if( l > 0 )
                {
                    sum += a[i][r] - a[i][l-1];
                }
                else {
                    sum += a[i][r];
                }

                if( sum < 0 )
                {
                    sum = 0;
                }
                else {
                    maxi = max( maxi, sum );
                }
            }
        }
    }
    printf("%d\n", maxi );

    return 0;
}

void reset()
{

}

