#include<bits/stdc++.h>

using namespace std;

int alternate(int n)
{
    int x=1,i;

    for(i=n;i>1;i--){
        if(n%i==0){
            x+=i;
        }
    }
    return x;
}

int main()
{
    int i,s,n,t=0;

    while(scanf("%d",&s)==1){
         if(s==0){
            break;
         }
        for(i=s;i>=0;i--){
            if(alternate(i)==s){
                printf("Case %d: %d\n",++t,i);
                break;
            }
            else if(i==0){
                printf("Case %d: -1\n",++t);
            }
        }
    }
    return 0;
}
