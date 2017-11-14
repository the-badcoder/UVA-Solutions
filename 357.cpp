#include <bits/stdc++.h>

using namespace std;

#define READ            freopen("input.txt", "r", stdin);
#define WRITE           freopen("output.txt", "w", stdout);
#define ll              long long int
#define space           " "
#define clr(ar)         memset( ar, 0, sizeof ar )
#define setdp(ar)       memset( dp, -1, sizeof dp )


#define sf1(a)                scanf("%d", &a)
#define sf2(a,b)              scanf("%d %d",&a, &b)
#define sf3(a,b,c)            scanf("%d %d %d", &a, &b, &c)

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
/// ............................................................///

const int res = 3e3 + 9;

ll target, n, m, sum, total, dp[6][30005];
int coin[] = { 50, 25, 10, 5 , 1 };

ll rec( ll i, ll value )
{
    if( i >= 5 ){
        if( value == 0 )
            return 1;
        else
            return 0;
    }

    if( dp[i][value] != -1 )
        return dp[i][value];

    ll taka1 = 0, taka2 = 0;

    if( value - coin[i] >=0 )
        taka1 = rec( i, value - coin[i] );
    taka2 = rec( i + 1, value );

    return dp[i][value] = taka1 + taka2;
}

int main()
{
    //WRITE;
    setdp( dp );
    while( scanf("%lld", &target) == 1 )
    {

        if( rec( 0, target ) > 1 ){
        printf("There are %lld ways to produce %lld cents change.\n", rec( 0, target ), target );
        }
        else {
            printf("There is only %lld way to produce %lld cents change.\n", rec( 0, target ), target );
        }
    }
}
