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
     char team[25],judge[25],temp[25];
    int i,j,x,k,t=0,len1,len2,test;

    while(scanf("%d",&test)==1){

    getchar();

    for(i=1; i<=test; i++){

    gets(team);
    gets(judge);

    len1 = strlen(team);
    len2 = strlen(judge);

    if(strcmp(team,judge)==0)
        printf("Case %d: Yes\n",++t);

    else
    {
        x=0;
        k=0;
    for(j=0;j<len1;j++)
    {
        if(team[j]>='a'&&team[j]<='z' || team[j]>='A'&&team[j]<='Z'){

        temp[k]=team[j];
        k++;
    }
    }
    temp[k]='\0';

    for(j=0;j<len2;j++){

    if(judge[j]!=temp[j]){
    x++;
    break;
    }
 }
    if(len2==k && x==0)
        printf("Case %d: Output Format Error\n",++t) ;
    else
        printf("Case %d: Wrong Answer\n",++t);
    }

    }

    }
    return 0;
}
