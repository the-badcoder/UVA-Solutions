#include <bits/stdc++.h>

using namespace std;

#define READ            freopen("input.txt", "r", stdin);
#define WRITE           freopen("output.txt", "w", stdout);
#define ll              long long int
#define space           " "
#define clr(ar)         memset( ar, 0, sizeof ar )


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

const int res = 1e5 + 9;

int main()
{
    /// Approach: Subset Sum.

    //WRITE;
    int test, n, a[205];
    string s;
    vector < int > v, ans;

    sf1( test );
    cin.ignore();

    while( test-- )
    {
        getline( cin, s );

        istringstream x( s );

        int i = 0, sum = 0, y, total;
        bool flag = true;

        for( i = 0; x >> a[i]; i++  );

        for( int k = 0; k < i; k++ )
        {
            sum += a[k];
        }

        total = sum / 2;

        v.push_back( 0 );

        for( int j = 0; j < i; j++ )
        {
            y = a[j];
            //deb( y );
            int sz = v.size();

            for( int k = 0; k < sz; k++ )
            {
                v.push_back( y + v[k] );
            }
        }

        for( auto it: v )
        {
            if( it * 2 == sum )
            {
                flag = false;
                break;
            }
        }

        if( flag == false )
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        v.clear();


        v.clear();


    }

    return 0;

}
