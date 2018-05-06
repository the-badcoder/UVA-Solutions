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

const int res = 1e6 + 10;
const int mod = 1e8 + 7;
#define ll long long
#define ull unsigned long long

void reset();

int n, m, sum, total, ans, digit, dp[ res ];
int a[res];
char ch;
map <int, int> mp;

int main()
{
    sf2( n, m );

    for( int i = 0; i < n; i++ )
    {
        sf1( a[i] );
    }

    while( m-- )
    {
        int u, v;
        getchar();
        scanf("%c", &ch);
        sf2( u, v );

        if( ch == 'M' ){
            a[ u ] = v;
        }
        else
        {
            reset();

            for( int i = u; i < v; i++ )
            {
                if( ++dp[ a[i] ] == 1 )
                {
                    digit++;
                }
            }

            for( int i = u; i < v; i++ )
            {
                dp[ a[i] ] = 0;
            }
//            deb("Hy");
//            deb( digit );
            printf("%d\n", digit );
        }
    }


    return 0;
}

void reset()
{
    digit = 0;

}
