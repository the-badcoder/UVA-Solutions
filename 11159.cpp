#include <bits/stdc++.h>

using namespace std;

#define READ                   freopen("input.txt", "r", stdin);
#define WRITE                  freopen("output.txt", "w", stdout);
#define space                  " "
#define clr(ar)                memset( ar, -1, sizeof ar )

#define sf1(a)                scanf("%d", &a)
#define sf2(a,b)              scanf("%d %d",&a, &b)
#define sf3(a,b,c)            scanf("%d %d %d", &a, &b, &c)
#define sf4(a,b,c,d)          scanf("%d %d %d %d", &a, &b, &c, &d)

#define sf1ll(a)              scanf("%lld", &a)
#define sf2ll(a,b)            scanf("%lld %lld", &a, &b)
#define sf3ll(a,b,c)          scanf("%lld %lld %lld", &a, &b, &c)


typedef pair< int, int >        ii;
typedef vector< int >           vi;
typedef vector< ii >            vii;

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

const int res = 1005;
const int mod = 1e8 + 7;
#define ll long long
#define ull unsigned long long

void reset();

vi graph[ res ];
int match[res];
bool seen[ res ];

int Aug( int u )
{
    if( seen[ u ] ) return 0;
    seen[ u ] = true;

    for( int i = 0; i < graph[ u ].size(); i++ )
    {
        int v = graph[ u ][ i ];
        if( match[ v ] == -1 || Aug( match[ v ] ) )
        {
            match[ v ] = u;
            return 1;
        }
    }

    return 0;
}


int main()
{
    //WRITE;
    int test, n, m, a[res], b[res], loop = 0;

    sf1( test );

    while( test-- )
    {
        sf1( n );

        for( int i = 0; i < n; i++ )
        {
            sf1( a[i] );
        }

        sf1( m );

        for( int i = 0; i < m; i++ )
        {
            sf1( b[i] );
        }

        reset();
        int maxi = 0;
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < m; j++ )
            {
                if( a[i] != 0 )
                {
                    if( b[j] % a[i] == 0 or b[j] == 0 )
                    {
                        //deb( a[i], b[j] );
                        graph[ i ].push_back( j );
                        int temp = graph[i].size();
                        maxi = max( maxi, temp );
                    }
                }
                else if( a[i] == 0 and b[j] == 0 )
                {
                    graph[i].push_back( j );
                }
            }
        }

        int MCBM = 0;

        for( int i = 0; i < res; i++ )
        {
            memset( seen, false, sizeof seen );
            //deb( Aug( i ) );
            MCBM += Aug( i );
        }

        printf("Case %d: %d\n", ++loop, MCBM );
    }

    return 0;

}

void reset()
{

    for( int i = 0; i < res; i++ )
    {
        graph[i].clear();
        seen[ i ] = false;
    }
    clr( match );

}



