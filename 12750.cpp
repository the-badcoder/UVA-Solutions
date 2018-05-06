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
const int res = 1e4 + 10;

int main()
{
    //WRITE;
    int test, loop = 0, digit, sum, total, ans, n, m;

    sf1( test );

    while( test-- && sf1( n ) )
    {
        vector <char> ch;
        vector <int> v;
        bool win = false, lose = false;

        for( int i = 0; i < n; i++ )
        {
            char x;
            cin >> x;
            if( x == 'L')
            {
                win = true;
            }

            ch.push_back( x );
        }

        if( win == false )
        {
            printf("Case %d: Yay! Mighty Rafa persists!\n", ++loop );
            continue;
        }
        int i;
        for( i = 0; i + 2 < ch.size(); i++ )
        {
            if( ch[i] != 'W' and ch[i+1] != 'W' and ch[i+2] != 'W' )
            {
                //printf("Case %d: %d\n", ++loop, i + 2 );
                lose = true;
                break;
            }
        }
        if( lose == true )
        {
            printf("Case %d: %d\n", ++loop, i + 3 );
        }
        else
        {
            printf("Case %d: Yay! Mighty Rafa persists!\n", ++loop );
        }
    }
    return 0;
}

