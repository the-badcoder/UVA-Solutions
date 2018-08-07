#include <bits/stdc++.h>


using namespace std;
const int res = 600;
using ll = long long;

template<class T> string ToString(const T &x)
{
    stringstream s;
    s << x;
    return s.str();
}

int main()
{
    //freopen("out.txt", "w", stdout );

    string s;
    while( getline( cin, s ) )
    {
        string ans = "";
        vector <int> v;
        int n;

        stringstream temp( s );

        while( temp >> n )
        {
            v.push_back( n );
        }

        string po = "x^";
        bool flag = false;


        for( int i = 0; i < v.size() - 1; i++ )
        {
            if( v[ i ] == 0 )
            {
                flag = true;
                if( flag == true and v[ i + 1 ] == 1 and i != v.size() - 2 )
                {
                    ans += " + ";
                }
                continue;
            }
            else
            {
                if( v[ i ] == 1 )
                {
                    if( (v.size() - i - 1) > 1 )
                    {
                        ans += po;
                        ans += ( ( v.size() - i - 1 ) + '0');
                    }
                    else
                    {
                        ans += "x";
                    }

                    flag = true;

                    if( v[ i + 1 ] == 1 and i != v.size() - 2 )
                    {
                        ans += " + ";
                    }
                }
                else
                {
                    flag = false;
                    string temp = ToString( v[ i ] );
                    if( temp[ 0 ] == '-' and temp == "-1" and ans.size() == 0)
                    {
                        temp.erase( temp.begin() + 1 );
                    }
                    else if( temp == "-1" )
                    {
                        ans += " - ";
                        temp.erase( temp.begin() );
                        temp.erase( temp.begin() );
                    }
                    else if( temp[ 0 ] == '-' and temp != "-1" )
                    {
                        ans += " - ";
                        temp.erase( temp.begin() );
                    }
                    else
                    {
                        ans += " + ";
                    }

                    ans += temp;
                    if( (v.size() - i - 1) > 1 )
                    {
                        ans += po;
                        ans += ( ( v.size() - i - 1 ) + '0');
                    }
                    else
                    {
                        ans += "x";
                    }
                    if( v[ i + 1 ] == 1  and i != v.size() - 2 )
                    {
                        ans += " + ";
                    }
                }
            }
        }

        int last = v[ v.size() - 1 ];
        if( ans.size() == 0 and last == 0 )
        {
            printf("0\n");
            continue;
        }
        else if( ans.size() == 0 and last < 0 )
        {
            printf("%d\n", last );
            continue;
        }
        else if( ans.size() == 0 and last > 0 )
        {
            printf("%d\n", last );
            continue;
        }

        if( ans[ 1 ] == '-' )
        {
            ans.erase( ans.begin() );
            ans.erase( ans.begin() + 1 );
        }
        else if( ans[ 1 ] == '+' )
        {
            ans.erase( ans.begin() );
            ans.erase( ans.begin() );
            ans.erase( ans.begin() );
        }

        if( last > 0 )
        {
            string temp = ToString( last );
            ans += " + ";
            ans += temp;
        }
        else if( last < 0 )
        {
            string temp = ToString( last );
            temp.erase( temp.begin() );
            ans += " - ";
            ans += temp;
        }

        cout << ans << endl;

    }
}
