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

const int res = 1e5 + 10;
void reset();

void reconstruct_print(int finish, int a[], int p[])
{
    int x = finish;
    stack<int> s;
    for (; p[x] >= 0; x = p[x]) s.push(a[x]);
    printf("%d\n", a[x]);
    for (; !s.empty(); s.pop()) printf("%d\n", s.top());
}

int main()
{
    /// CODE SOURCE MY CP3 BOOK :D
    int n, a[res], test, L[res], L_id[res], P[res], sum, total, len, ans, digit, x, i = 0;

    while( sf1( x ) == 1 )
    {
        a[i++] = x;

    }

    n = i;
    int lis = 0, lis_end = 0;

    for( int i = 0; i < n; i++ )
    {
        int pos = lower_bound( L, L + lis, a[i] ) - L;
        L[pos] = a[i];
        L_id[pos] = i;
        P[i] = pos ? L_id[pos - 1] : -1;

        if (pos + 1 > lis)
        {
            lis = pos + 1;
            lis_end = i;
        }
    }

    printf("%d\n-\n", lis );
    reconstruct_print( lis_end, a, P );

    return 0;
}

