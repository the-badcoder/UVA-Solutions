/*
    Bismillah Hir Rahmanir Rahim
*/
#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

int main()
{
    int test, digit, digit1;
    string s, s1, s2, s3;

    cin >> test;

    while( test-- ){
        cin >> s >> s1;

        digit = digit1 = 0;
        s2 = "";
        s3 = "";
        for( int i = 0; i < s.size(); i++ ){
            if( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ){
                continue;
            }
            else {
                s2 += s[i];
            }
        }
        for( int i = 0; i < s1.size(); i++ ){
            if( s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u' ){
                continue;
            }
            else {
                s3 += s1[i];
            }
        }

        if( ( s2.size() == s3.size()) && s2 == s3 ){
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}
