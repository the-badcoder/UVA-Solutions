/// Bismillah Hir Rahmanir Rahim

#include <bits/stdc++.h>

using namespace std;


#define space                 " "
#define all(x)                (x).begin(), (x).end()
#define clr(ar)               memset(ar, 0, sizeof(ar))

typedef  long long int           ll;
typedef  map<string,int>         msi;
typedef  map<int,int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<char,int>           mci;
typedef  map<int,string>	     mis;
typedef  pair<int,int> 	         ii;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef  vector<int> 	         vi;
typedef  vector<string> 	     vs;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  vector< ii >            vii;


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

#define sf1ll(a)              scanf("%I64d", &a)
#define sf2ll(a,b)            scanf("%I64d %I64d", &a, &b)
#define sf3ll(a,b,c)          scanf("%I64d %I64d %I64d", &a, &b, &c)

#define READ                  freopen("input.txt", "r", stdin);
#define WRITE                 freopen("output.txt", "w", stdout);
/// The End.


const int maxn = 2e5 + 5;
int Rank[maxn], p[maxn];
int numSets, sum;
vector <int> setSize;

struct DisjointSet
{
    void make_set( int x )
    {
        numSets = x;
        setSize.assign( x, 1 );

        for( int i = 0; i < x; i++ )
        {
            Rank[i] = 0;
            p[i] = i;
        }
    }

    int findSet( int i )
    {
        return ( p[i] == i ) ? i : ( p[i] = findSet( p[i] ) );
    }

    bool isSameSet( int i, int j )
    {
        return findSet(i) == findSet(j);
    }

    void unionSet( int i, int j )
    {
        if( !isSameSet( i, j ) )
        {
            numSets--;
            int x = findSet(i), y = findSet(j);

            if( Rank[x] > Rank[y] )
            {
                p[y] = x;
                setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                setSize[y] += setSize[x];

                if( Rank[x] == Rank[y] )
                {
                    Rank[y]++;
                }
            }
        }
    }

    int numofdisjointset()
    {
        return numSets;
    }
    int sizeOfSet(int i)
    {
        return setSize[findSet(i)];
    }

} UF;

int main()
{
    int V, E, u, v, w, mst_cost = 0, total;

    while( scanf("%d %d", &V, &E ) && V || E ){

    vector < pair < int, ii > > Edgelist;

    for( int i = 0; i < E; i++ )
    {
        sf3( u, v, w );
        sum += w;              /// Input of Edges and Weights.

        Edgelist.push_back( make_pair( w, ii ( u, v ) ) );

        /// W == First Value. U == Second.Second. V == Second.first
    }

    sort( Edgelist.begin(), Edgelist.end() );

    UF.make_set( V );

    for( int i = 0; i < E; i++ )
    {
        if( !UF.isSameSet( Edgelist[i].second.first, Edgelist[i].second.second ) )
        {
            mst_cost += Edgelist[i].first;

            UF.unionSet( Edgelist[i].second.first, Edgelist[i].second.second );
        }

    }

    //printf("%d\n", mst_cost);

    total = sum - mst_cost;
    deb( total );
    sum = 0;
    total = 0;
    mst_cost = 0;
    Edgelist.clear();
    UF.make_set(0);

    }
    return 0;
}
