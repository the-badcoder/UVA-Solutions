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
    string s1, s2, s3;

    while( getline(cin, s1) ){
        int digit = 0;
        for( int i = 0; i < s1.size(); i++ ){
            if( isalpha(s1[i]) && !isalpha(s1[i+1])){
                digit++;
            }
        }
        cout << digit << endl;
    }
    return 0;
}
