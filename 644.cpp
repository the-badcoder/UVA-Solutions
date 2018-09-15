/// Bismillah Hir Rahmanir Rahim

/**
    Practice like Cristiano Ronaldo
        Play Like Leo Messi..
**/

#include <bits/stdc++.h>

using namespace std;

#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define ff                    first
#define ss                    second
#define pb                    push_back
#define space                 " "
#define cubert(x)             (exp(log(x)/3))
#define all(x)                (x).begin(), (x).end()
#define clr(ar)               memset(ar, 0, sizeof(ar))
#define eprintf(...)          fprintf(stderr, __VA_ARGS__)

/*
template <class T> T gcd(T a,T b){ if(b == 0) return a; return gcd( b,a % b ); }
template <class T> T lcm(T a, T b ){ return ( a * b ) / gcd( a,b ); }
template<class T> string ToString(const T &x){ stringstream s; s << x; return s.str(); }
template<class T> int ToInteger(const T &x){ stringstream s; s << x; int r; s >> r; return r; }
*/

typedef  long long int            ll;
typedef  map<string,int>          msi;
typedef  map<int,int>	          mii;
typedef  map<char,int>            mci;
typedef  map<int,string>	      mis;
typedef  pair<int,int> 	          ii;
typedef  pair<string, int>        psi;
typedef  vector<int> 	          vi;
typedef  vector<string> 	      vs;
typedef  vector< ii >             vii;

template<class T1> void deb(T1 e1)
{
    cout << e1 << endl;
}
template<class T1,class T2> void deb(T1 e1, T2 e2)
{
    cout << e1 << space << e2 << endl;
}
template<class T1,class T2,class T3> void deb(T1 e1, T2 e2, T3 e3)
{
    cout << e1 << space << e2 << space << e3 << endl;
}

#define sf                    scanf
#define pf                    printf

#define sf1(a)                scanf("%d", &a)
#define sf2(a,b)              scanf("%d %d",&a, &b)
#define sf3(a,b,c)            scanf("%d %d %d", &a, &b, &c)
#define sf4(a,b,c,d)          scanf("%d %d %d %d", &a, &b, &c, &d)

#define sf1ll(a)              scanf("%I64d", &a)
#define sf2ll(a,b)            scanf("%lld %lld", &a, &b)
#define sf3ll(a,b,c)          scanf("%lld %lld %lld", &a, &b, &c)
#define sf4ll(a,b,c,d)        scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &d)

#define READ                  freopen("in.txt", "r", stdin);
#define WRITE                 freopen("out.txt", "w", stdout);
/// The End.

void check_time()
{
#ifdef the_badcoder
    eprintf("%.5lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}

const int res = 1e4 + 10;
const ll mod = 1e9 + 7;


/**
        ACCEPT FAILURE.
**/


struct node
{
    bool mark;
    int digit = 0;
    node* next[ 10 + 1 ];
    node()
    {
        mark = false;
        for( int i = 0; i < 10; i++ )
        {
            next[i] = NULL;
        }
    }
} * root;

void add_trie( string s, int len )
{
    node* curr = root;
    for( int i = 0; i < len; i++ )
    {
        int id = (int) s[i] - 48;

        if( curr->next[id] == NULL )
        {
            curr->next[id] = new node();
            //curr = curr->next[id];
        }
        curr = curr->next[id];
        curr->digit++;
        //curr = curr->next[id];


    }
    curr->mark = true;
}

int search_trie( string s, int len )
{
    node* curr = root;
    for( int i = 0; i < len; i++ )
    {
        int id = (int) s[i] - 48;
        //if( curr->next[id] == NULL )
        //return false;
        curr = curr->next[id];
    }
    return curr->digit;
}

void del_trie( node* curr )
{
    for( int i = 0; i < 10; i++ )
        if( curr->next[i] )
            del_trie( curr->next[i] );
    delete( curr );
}


int main()
{
#ifdef LM10
    //freopen("in", "r", stdin );
    //freopen("out", "w", stdout );
#endif // LM10

    string x;
    int loop = 0;

    while( cin >> x )
    {
        root = new node();
        bool flag = false;
        string s;
        vector <string> v;
        v.push_back( x );
        add_trie( x, x.size() );

        while( cin >> s )
        {
            if( s == "9") break;
            v.push_back( s );
            add_trie( s, s.size() );
        }

        for( int i = 0; i < v.size(); i++ )
        {
            if( search_trie( v[ i ], v[ i ].size() ) > 1 )
            {
                flag = true;
                break;
            }
        }

        if( flag == true ) printf("Set %d is not immediately decodable\n", ++loop );
        else printf("Set %d is immediately decodable\n", ++loop );
    }
    return 0;
}

