/*
    Bismillah Hir Rahmanir Rahim
*/
/// Author: Tareq Aziz Khan

#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
    int test;
    string s;

    cin >> test;

    while( test-- ){
        cin >> s;

        if( s.size() == 5 ){
            cout << 3 << endl;
        }

        else if( (s[0] == 'o' && s[1] == 'n') || (s[0] == 'o' && s[2] == 'e') || (s[1] == 'n' && s[2] == 'e')){
            cout << 1 << endl;
        }
        else if( (s[0] == 't' && s[1] == 'w' ) || (s[0] == 't' && s[2] == 'o') || ( s[2] == 'o' && s[1] == 'w') ){
            cout << 2 << endl;
        }
    }

    return 0;
}

