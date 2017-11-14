/*
    Bismillah Hir Rahmanir Rahim
*/
/// Author: Tareq Aziz Khan

#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
    char s;

    while(scanf("%c", &s)==1)
    {
        if(s =='p' || s=='P')
        {
            printf("i");
        }
        else if(s =='O' || s =='o')
        {
            printf("u");
        }
        else if(s =='I' || s =='i')
        {
            printf("y");
        }
        else if(s =='U' || s == 'u')
        {
            printf("t");
        }
        else if(s =='Y' || s =='y')
        {
            printf("r");
        }
        else if(s =='T' || s =='t')
        {
            printf("e");
        }
        else if(s =='R' || s =='r')
        {
            printf("w");
        }
        else if(s =='E' ||  s =='e')
        {
            printf("q");
        }
        else if(s =='L' ||  s =='l')
        {
            printf("j");
        }
        else if(s =='K' ||  s =='k')
        {
            printf("h");
        }
        else if(s =='J' || s =='j')
        {
            printf("g");
        }
        else if(s =='H' ||   s =='h')
        {
            printf("f");
        }
        else if(s =='G' ||  s =='g')
        {
            printf("d");
        }
        else if(s =='F' ||  s =='f')
        {
            printf("s");
        }
        else if(s =='D' || s =='d')
        {
            printf("a");
        }
        else if(s =='M' || s =='m')
        {
            printf("b");
        }
        else if(s =='N' || s =='n')
        {
            printf("v");
        }
        else if(s =='B' || s =='b')
        {
            printf("c");
        }
        else if(s =='V' || s =='v')
        {
            printf("x");
        }
        else if(s =='C' || s =='c')
        {
            printf("z");
        }
        else if(s =='.')
        {
            printf("m");
        }
        else if(s =='\\')
        {
            printf("[");
        }
        else if(s ==']')
        {
            printf("p");
        }
        else if(s =='[')
        {
            printf("o");
        }
        else if(s =='\'')
        {
            printf("l");
        }
        else if(s ==';')
        {
            printf("k");
        }
        else if(s =='/')
        {
            printf(",");
        }
        else if(s ==',')
        {
            printf("n");
        }
        else if(s ==' ')
        {
            printf(" ");
        }
        if( s =='\n')
        {
            printf("\n");
        }
    }
    return 0;
}
