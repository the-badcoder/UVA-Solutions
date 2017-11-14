#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test, n;
    vector <int> v;

    while( cin >> test && test != 0 )
    {

        for( int i = 0; i < test; i++ )
        {
            cin >> n;
            v.push_back(n);
        }
        sort( v.begin(), v.end() );

        //printf("%d", v[0]);
        for( int i = 0; i < test; i++ )
        {
            printf("%d", v[i]);
            if( i != (test-1) )
                printf(" ");
        }
        cout << endl;
        v.clear();
    }

    return 0;

}


