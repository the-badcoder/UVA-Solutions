#include <bits/stdc++.h>
using namespace std;
const int sz = 1e6 + 10;
int f[sz];
using ll = long long;
ll _sieve_size;
bitset<sz> bs;   // 10^7 should be enough for most cases
vector < int > primes;   // compact list of primes in form of vector<int>
ll dp[sz];
ll nod[sz];
ll ans[sz];

void sieve()            // create list of primes in [0..upperbound]
{
    _sieve_size = 1005;                   // add 1 to include upperbound
    bs.set();                                                 // set all bits to 1
    bs[0] = bs[1] = 0;                                     // except index 0 and 1
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i])
        {
            // cross out multiples of i starting from i * i!
            for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back((int)i);  // also add this vector containing list of primes
        }
}

void siv() {
    for( int i=1; i<sz; i++ ) {
        for( int j=i; j<sz; j+=i ) {
            nod[j]++;
        }
    }
}

int main() {
//    sieve();
    siv();
    dp[0] = 1;
    nod[0] = 0;
    nod[1] = 1;
    nod[2] = 2;
    nod[3] = 2;
//    for( int i=4; i<sz; i++ ) {
//        for( int j=0; j<primes.size(); j++ ) {
//            nod[i] = 1;
//            if( i % primes[j] == 0 ) {
//                nod[i] += nod[ i / primes[j] ];
//                break;
//            }
//        }
//    }
    ans[ dp[0] ] = 1;
    for( int i=1; i<sz; i++ ) {
        dp[i] = dp[i-1] + nod[ dp[i-1] ];
        ans[ dp[i] ] = 1;
    }
    for( int i=1; i<=sz; i++ ) ans[i] += ans[i-1];
//    for( int i=0; i<=20; i++ ) cerr << dp[i] << ": " << nod[i] << "\n";
    int t;
    int a, b;
    scanf( "%d", &t );
    for( int cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &a, &b ) ;
        printf( "Case %d: %lld\n", cs, ans[b] - ans[a-1] ) ;
    }
    return 0;
}
