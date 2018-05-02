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
const int mod = 1e6;

void reset();

int n, total, ans, digit, loop = 0;
bool blankline = false;
ll a[20];

int main()
{
    //WRITE;
    while( sf1( n ) != EOF )
    {
        vector <int> v;
        ll sum;
        bool zero = false;
        for( int i = 0; i < n; i++ )
        {
            int x;
            sf1ll( a[i] );

            if( a[i] == 0 )
            {
                zero = true;
            }

        }

        ll maxi = 0;

        for( int i = 0; i < n; i++, sum = 1 )
        {
            for( int j = i; j < n; j++ )
            {
                sum *= a[j];
                maxi = max( maxi, sum );
            }
        }
        //deb( maxi );

        if( zero == true and maxi < 0 )
        {
            printf("Case #%d: The maximum product is %lld.\n\n", ++loop, 0ll );
        }
        else
        {
            printf("Case #%d: The maximum product is %lld.\n\n", ++loop, maxi );
        }
    }

    return 0;
}

void reset()
{


}

