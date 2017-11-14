//Bismillah Hir Rahmanir Rahim
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <string.h>
#define MAX 1000000

using namespace std;

int main()
{
   char s[101], dummy;
   int i, len, test, sum, c = 0;

    scanf( "%d", &test );
    scanf("%c", &dummy);

   while( test-- ){

     gets(s);
     len = strlen(s);
     sum = 0;

    for( i = 0; i < len; i++ ){
        if( s[i] == 'a' || s[i] == 'd' || s[i] == 'g' || s[i] == 'j' || s[i] == 'm' || s[i] == 'p' || s[i] == 't' || s[i] == 'w'){
            sum += 1;
        }
        else if( s[i] == 'b' || s[i] == 'e' || s[i] == 'h' || s[i] == 'k' || s[i] == 'n' || s[i] == 'q' || s[i] == 'u' || s[i] == 'x'){
            sum += 2;
        }
        else if( s[i] == 'c' || s[i] == 'f' || s[i] == 'i' || s[i] == 'l' || s[i] == 'o' || s[i] == 'r' || s[i] == 'v' || s[i] == 'y'){
            sum += 3;
        }
        else if( s[i] == 's' || s[i] == 'z'){
            sum += 4;
        }
        else if( s[i] == ' ') {
            sum += 1;
        }
    }
    printf("Case #%d: %d\n", ++c, sum);

   }
    return 0;
}
