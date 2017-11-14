#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[1000];
    int len, i;

    while(scanf("%s", &s)==1){

    len = strlen(s);

    for( i = 0; i < len; i++){
        printf("%c", s[i] - 7 );
    }
    printf("\n");
    }
    return 0;
}
