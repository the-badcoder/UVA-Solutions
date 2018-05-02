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
const int mod = 1e6;

void reset();


int main()
{
    int i,j,k,pos;
    int b1, g1, c1, b2, g2, c2, b3, g3, c3;
    int sum, mini, moves[10];

    while(scanf("%d %d %d %d %d %d %d %d %d", &b1, &g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3) ==9 )
    {
        memset( moves, 0, sizeof moves );
        mini = INT_MAX ;
        moves[0] = b2+b3+c1+c3+g1+g2;
        moves[1] = b2+b3+g1+g3+c1+c2;
        moves[2] = c2+c3+b1+b3+g1+g2;
        moves[3] = c2+c3+g1+g3+b1+b2;
        moves[4] = g2+g3+b1+b3+c1+c2;
        moves[5]= g2+g3+c1+c3+b1+b2;

        for( k = 5; k >= 0; k-- )
        {

            if( mini >= moves[k])
            {
                mini = moves[k];
                pos = k;
            }

        }

        if( pos == 0 )printf("BCG");
        else if( pos == 1 ) printf("BGC");
        else if( pos == 2 ) printf("CBG");
        else if( pos == 3 ) printf("CGB");
        else if( pos == 4 ) printf("GBC");
        else if( pos == 5 ) printf("GCB");

        printf(" %d\n", mini);
    }
    return 0;
}

void reset()
{


}

