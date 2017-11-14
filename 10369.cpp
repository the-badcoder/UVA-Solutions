#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> llp;
typedef pair<double, double> dd;
typedef pair<char, int> ci;

int t, s, p, i, j, numDisjointSet;
double x, y, ans;
vector<pair<double, ii> > edge;
vector<dd> outposts;
vi par, size;

double dist(dd a, dd b)
{
    return sqrt(((a.first-b.first)*(a.first-b.first))+((a.second-b.second)*(a.second-b.second)));
}
void initSet(int n)
{
    par.assign(n+1, 0);
    size.assign(n+1, 1);
    for(i=0; i<n; ++i)
        par[i]=i;
    numDisjointSet=n;
}
int findSet(int i)
{
    return par[i]==i?i:findSet(par[i]);
}
bool sameSet(int i, int j)
{
    return findSet(i)==findSet(j);
}
void unionSet(int i, int j)
{
    if(!sameSet(i, j))
    {
        size[findSet(j)]+=size[findSet(i)];
        par[findSet(i)]=par[findSet(j)];
        numDisjointSet--;
    }
}
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &s, &p);
        par.clear(), size.clear();
        initSet(p);
        outposts.clear();
        edge.clear();
        while(p--)
        {
            scanf("%lf %lf", &x, &y);
            outposts.push_back(dd(x, y));
        }
        for(i=0; i<(int)outposts.size(); ++i)
            for(j=i+1; j<(int)outposts.size(); ++j)
                edge.push_back(make_pair(dist(outposts[i], outposts[j]), ii(i, j)));
        sort(edge.begin(), edge.end());
        ans=0.0;
        for(i=0; i<(int)edge.size(); ++i)
        {
            if(numDisjointSet==s)
                break;
            pair<double, ii> temp=edge[i];
            if(!sameSet(temp.second.first, temp.second.second))
            {
                unionSet(temp.second.first, temp.second.second);
                ans=temp.first;
            }
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
