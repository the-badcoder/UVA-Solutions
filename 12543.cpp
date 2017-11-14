#include <bits/stdc++.h>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    int len, digit , maxi = 0, total;
    vector <string> v;
    string s, s1, s2;
    vector < pair < int , string > > vp;

    while( cin >> s )
    {
        if( s == "E-N-D" )
        {
            break;
        }
        digit = 0;
        s1 = "";

        for( int i = 0; i < s.size(); i++ )
        {

            if( isalpha(s[i]) || s[i] == '-' )
            {
                digit++;
                s1 += tolower( s[i] );

                if( digit > maxi )
                {
                    maxi = digit;
                    s2 = s1;
                }
            }

            vp.push_back( { maxi, s2 } );
        }
    }

    cout << vp[ vp.size() - 1].second << endl;
    vp.clear();

    return 0;
}
