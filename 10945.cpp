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
        if( s1 == "DONE" ){
            break;
        }

        s2 = "";

        for( int i = 0; i < s1.size(); i++ )
            if( isalpha(s1[i]))
                s2 += tolower(s1[i]);

        s3 = s2;

        reverse( s2.begin(), s2.end() );

        if( s3 == s2 )
             printf("You won't be eaten!\n");
        else
            printf("Uh oh..\n");
    }
    return 0;
}
