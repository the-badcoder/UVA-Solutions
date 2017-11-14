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
        //setSize.assign( x +1, 1 );       /// 1 Based.
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
    int test;

    scanf("%d", &test );
    getchar();
    getchar();

    int  V, E, WA, AC, x, y, a, b;
    string s, s1;
    char ch;

    while( test-- )
    {
        WA = AC = 0;

        scanf("%d", &V);
        getchar();

        UF.make_set( V );

        while( true )
        {
            ch = getchar();

            if( ch == 'c' )
            {
                getchar();
                scanf("%d", &x);
                getchar();
                scanf("%d", &y);
                getchar();

                if( !UF.isSameSet(x, y) )
                {
                    UF.unionSet( x, y );
                }
            }

            else if( ch == 'q' )
            {
                getchar();
                scanf("%d", &a);
                getchar();
                scanf("%d", &b);
                getchar();

                if( UF.isSameSet( a, b ) )
                {
                    //cout << "YES\n";
                    AC++;
                }
                else
                {
                    //cout << "NO\n";
                    WA++;
                }
            }

            else
            {
                printf("%d,%d\n", AC, WA );
                break;
            }
        }

        if( test )
        {
            printf("\n");
        }
    }
    return 0;
}
