/*
     BISMILLAH HIR RAHMANIR RAHIM
*/

/// Containers Start
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <iterator>
#include <algorithm>
/// C Header Files
#include <cstdio>
#include <cctype>
#include <cmath>
#include <math.h>
#include <ctime>
#include <cstring>
/// Containers End


using namespace std;

/// Math Start
#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define SQR(n)                ( n * n )
/// Math End


/// Pair Start
#define ff                    first
#define ss                    second
#define mp                    make_pair
/// Pair End


/// Array Start
#define SET(a)                memset( a, -1,    sizeof a )
#define CLR(a)                memset( a,  0,    sizeof a )
#define MEM(a,val)            memset( a,  val,  sizeof(a) )
/// Array End


/// Extra Start
#define nn                    '\n'
#define pb                    push_back
#define SS                    stringstream
#define mod                   1000000007
#define INF                   2147483647
#define SIZE                  2000001
#define _cin                  ios_base::sync_with_stdio(0);  cin.tie(0);
#define sz(a)                 int((a).size())
#define space                 " "
#define all(x)                (x).begin(), (x).end()
#define Ignore                cin.ignore()
#define StringToInt           if ( ! (istringstream(s) >> n) ) n = 0;
/// Extra End


/// Template Start
/*template < class T > T Multiply( T a, T b ){ return a * b ;}
template < class T > T larger( T a, T b ){ return ( a > b ? a : b );}
template < class T > T smaller( T a, T b ){ return ( a < b ? a : b );}
template < class T > string converter( T n ){ SS x; x << n; return x.str();}*/
/// Template End


/// TypeDef Start
typedef  long long int           ll;
typedef  map<string,int>         msi;
typedef  map<int,int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<char,int>           mci;
typedef  map<int,string>	     mis;
typedef  pair<int,int> 	         pii;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef  vector<int> 	         vi;
typedef  vector<string> 	     vs;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  vector< pii >           vii;
/// TypeDef End


/// I/O Start
#define sf                    scanf
#define pf                    printf

#define sf1(a)                scanf("%d", &a)
#define sf2(a,b)              scanf("%d %d",&a, &b)
#define sf3(a,b,c)            scanf("%d %d %d", &a, &b, &c)
#define sf4(a,b,c, d)         scanf("%d %d %d %d", &a, &b, &c, &d)

#define sf1ll(a)              scanf("%I64d", &a)
#define sf2ll(a,b)            scanf("%I64d %I64d", &a, &b)
#define sf3ll(a,b,c)          scanf("%I64d %I64d %I64d", &a, &b, &c)
#define sf4ll(a,b,c, d)       scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &d)

#define READ                  freopen("input.txt", "r", stdin);
#define WRITE                 freopen("output.txt", "w", stdout);
/// I/O End


int main()
{
    long long int T, n, x , sum = 0, k = 1, y, a, b;
    vector < pair< int, int > > v;
    v.clear();
    cin >> T;
    while( T-- )
    {
        cin >> n;
        v.resize(n);
        y = n;
        int i = 0;
        x = 0;
        while( n-- )
        {
            cin >> a >> b ;
            v[i].first = b;
            v[i].second = a;
            x += v[i].second;
            i++;
        }
        sort(v.begin(), v.end());
        i = 0;
        sum = 0;
        while(i < y)
        {
            int p = v[i].first;
            if( (p * x) >= sum )
            {
                sum = p* x;
            }
            x = x - v[i].second;
            i++;
        }
        cout << "Case " << k << ": " <<sum << endl;
        k++;
    }
    return 0;
}

