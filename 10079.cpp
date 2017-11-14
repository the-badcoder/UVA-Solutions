#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,sum;

    while(scanf("%lld",&n)==1){
        if(n<0){
            break;
        }
        else {
            sum = (n*(n+1)/2)+1;
            printf("%lld\n",sum);
        }
    }
    return 0;
}
