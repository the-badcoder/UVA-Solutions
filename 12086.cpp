#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
#define WRITE freopen("output.txt", "w", stdout);

struct SegmentTree // the segment tree is stored like a heap array
{
    vi st, A; // recall that vi is: typedef vector<int> vi;
    int n;

    void make_tree(const vi &_A)
    {
        A = _A;
        n = (int)A.size(); // copy content for local usage
        st.assign(4 * n, 0); // create large enough vector of zeroes
        build(1, 0, n - 1); // recursive build
    }

    int left (int p)
    {
        return p << 1; // same as binary heap operations
    }
    int right(int p)
    {
        return (p << 1) + 1;
    }

    void build(int p, int L, int R) // O(n log n)
    {
        if (L == R) // as L == R, either one is fine
        {
            st[p] = A[L];
        } // store the index
        else // recursively compute the values
        {
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R );
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = p1 + p2;
        }
    }
    int rmq(int i, int j)
    {
        return rmq(1, 0, n - 1, i, j); // overloading
    }

    int update_point(int idx, int new_value)
    {
        return update_point(1, 0, n - 1, idx, new_value);
    }

    int rmq(int p, int L, int R, int i, int j) // O(log n)
    {
        if (i > R || j < L) return INT_MAX; // current segment outside query range
        if (L >= i && R <= j) return st[p]; // inside query range

// compute the min position in the left and right part of the interval
        int p1 = rmq(left(p), L, (L+R) / 2, i, j);
        int p2 = rmq(right(p), (L+R) / 2 + 1, R, i, j);

        if (p1 == INT_MAX ) return p2; // if we try to access segment outside query
        if (p2 == INT_MAX ) return p1; // same as above
        return p1 + p2;
    } // as as in build routine

    int update_point(int p, int L, int R, int idx, int new_value)
    {
// this update code is still preliminary, i == j
// must be able to update range in the future!
        int i = idx, j = idx;

// if the current interval does not intersect
// the update interval, return this st node value!
        if (i > R || j < L)
            return st[p];

// if the current interval is included in the update range,
// update that st[node]
        if (L == i && R == j)
        {
            A[i] = new_value; // update the underlying array
            return st[p] = A[L]; // this index
        }

// compute the minimum pition in the
// left and right part of the interval
        int p1, p2;
        p1 = update_point(left(p), L, (L + R) / 2, idx, new_value);
        p2 = update_point(right(p), (L + R) / 2 + 1, R, idx, new_value);

// return the pition where the overall minimum is
        return st[p] = p1 + p2;
    }

} ST;

int main()
{
//WRITE;
    int m, q, sum, total, digit, ar[200005], loop = 0;
    int x, y, a, b;
    string s;

    while( scanf("%d", &m ) && m != 0 )
    {

        for( int i = 0; i < m; i++ )
        {
            scanf("%d", &ar[i] );
        }

        vi A( ar, ar + m );
        ST.make_tree( A );

        if( loop )
        {
            printf("\n");
        }
        printf("Case %d:\n", ++loop );

        while( cin >> s && s != "END" )
        {
            if( s == "M" )
            {
                scanf("%d %d", &a, &b );
                a--, b--;
                int temp = ST.rmq( a, b );
                printf("%d\n", temp );
            }
            if( s == "S" )
            {
                scanf("%d %d", &x, &y );
                x--;
                ST.update_point( x, y );
            }
        }
    }

    return 0;
}
