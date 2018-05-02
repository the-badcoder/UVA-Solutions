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

int a[25], weight[25], sum, total, ans, n, test, digit, i, x;

void reset()
{
    i = x = n = 0;
    clr( a );
    clr( weight );
}

bool rec( int i, int one, int two, int n )
{
    if( i == n )
    {
        if( one == two ){
            return true;
        }
        return false;
    }

    bool yes = rec( i + 1, one + weight[i], two, n );
    bool no = rec( i + 1, one, weight[i] + two, n );
    //deb( yes, no );

    return yes or no;
}

int main()
{
    sf1( test );
    cin.ignore();

    while( test-- )
    {
        reset();
        string s;
        getline( cin, s );
        stringstream ss( s );

        while( ss >> x )
        {
            weight[ i++ ] = x;
            n++;
        }

        if( rec( 0, 0, 0, n ) ){
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
        ss.clear();
    }

    return 0;
}
