#include <bits/stdc++.h>

using namespace std;

#define WRITE  freopen("output.txt", "w", stdout);

const int maxn = 1e5 + 5;
int Rank[maxn], p[maxn];
int numSets;
vector <int> setSize;
map <string, int> m;

struct DisjointSet
{
    void make_set( int x )
    {
        numSets = x;
        setSize.assign( x + 1 , 1 );       /// 1 Based.
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
    //WRITE;
    int V, E, nodes, test;
    string s, s1;

    scanf("%d", &test);

    while( test-- )
    {
        scanf("%d", &V );

        UF.make_set( V );
        nodes = 0;
        m.clear();

        for( int i = 1; i <= V; i++ )
        {
            cin >> s >> s1;

            if( !m.count(s) )
            {
                m[s] = ++nodes;
            }
            if( !m.count(s1) )
            {
                m[s1] = ++nodes;
            }

            int a = m[s];
            int b = m[s1];

            UF.unionSet(a, b);

            cout << UF.sizeOfSet(a) << endl;
        }
    }
    return 0;
}
