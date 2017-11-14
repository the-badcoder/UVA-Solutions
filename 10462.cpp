#include <bits/stdc++.h>

using namespace std;

using ll = long long;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

#define WRITE  freopen("output.txt", "w", stdout);

const int maxn = 1e5 + 5;
int Rank[maxn], p[maxn];
int numSets;
bool flag[maxn];

vector <int> setSize;
map <string, int> m;
vector <int> store;
vector < pair < int, ii > > Edgelist;

int V, E, u, v, w, mst_cost, test, taka, sum, loop = 0, total, cost, best, y;
string s, s1;


void second_mst( int skip );

struct DisjointSet
{
    void make_set( int x )
    {
        numSets = x;
        //setSize.assign( x + 1 , 1 );       /// 1 Based.
        for( int i = 1; i <= x; i++ )
        {
            Rank[i] = 0;
            p[i] = i;
        }
    }

    int findSet( int x )
    {
        return ( p[x] == x ) ? x : ( p[x] = findSet( p[x] ) );
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
                //setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                //setSize[y] += setSize[x];

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
    /*int sizeOfSet(int i)
    {
        return setSize[findSet(i)];
    }
    */


} UF;

int main()
{
    //WRITE;
    scanf("%d", &test );

    while( test-- )
    {
        scanf("%d %d", &V, &E );

        Edgelist.clear();
        sum = 0;
        mst_cost = best = 0;

        for( int i = 0; i < E; i++ )
        {
            scanf("%d %d %d", &u, &v, &w);
            Edgelist.push_back( make_pair( w, ii ( u, v ) ) );
            flag[i] = false;
        }

        sort( Edgelist.begin(), Edgelist.end() );
        UF.make_set( V );

        for( int i = 0; i < E; i++ )
        {
            if( !UF.isSameSet( Edgelist[i].second.first, Edgelist[i].second.second ) )
            {
                sum++;
                mst_cost += Edgelist[i].first;
                flag[i] = true;
                UF.unionSet( Edgelist[i].second.first, Edgelist[i].second.second );

            }
        }
        //printf("%d\n", mst_cost );

        printf("Case #%d :", ++loop );

        if( sum != V - 1 )
        {
            printf(" No way\n");
        }
        else if( E < V )
        {
            printf(" No second way\n");
        }
        else
        {

            store.clear();
            for( int j = 0; j < E; j++ )
            {
                {
                    if( flag[j] == true )
                    {
                        //second_mst( i );
                        int lol = 0, ans = 0;
                        UF.make_set( V );

                        for( int i = 0; i < E; i++ )
                        {
                            if( !UF.isSameSet( Edgelist[i].second.first, Edgelist[i].second.second ) && i != j )
                            {
                                ans += Edgelist[i].first;
                                lol++;
                                UF.unionSet( Edgelist[i].second.first, Edgelist[i].second.second );
                            }
                        }

                        if( lol == V - 1 )
                        {
                            store.push_back( ans );
                        }
                    }
                }
            }
            sort( store.begin(), store.end() );
            printf(" %d\n", store[0] );

        }
    }

    return 0;
}
