#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int sz = 1e5 + 10;
const int mod = 1000007;

int valid( int n, int x ) {
        return __gcd( n, x ) == 1;
}

vector < int > prime;
bool is_composite[sz + 10];
int phi[sz + 10];

void sieve( int n ) {
	fill(is_composite, is_composite + n, false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) {
			prime.push_back (i);
			phi[i] = i - 1;
		}
		for (int j = 0; j < prime.size () && i * prime[j] < sz; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			} else {
				phi[i * prime[j]] = phi[i] * phi[prime[j]];
			}
		}
	}
}

int main() {
        #ifdef CLown1331
                freopen("in.txt", "r", stdin);
        #endif /// CLown1331

        sieve( sz );

        int t, n;

        cin >> t;

        while( t-- && cin >> n ) cout << phi[n] << "\n";

        return 0;
}
