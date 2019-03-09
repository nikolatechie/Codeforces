#include <bits/stdc++.h>
using namespace std;

using ci = const int;
using llint = long long;
using pii = pair <int,int>;
using vi = vector <int>;
using vb = vector <bool>;

#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)


ci MX = 200005;
int n, m, k;
vector <vi> v; // colors for each component
int color[MX], par[MX], rnk[MX], sz[MX];

// find-set function
int fs(int x)
{
    return (par[x] == x) ? x:(par[x] = fs(par[x])); // path compression
}

// union-set function (union by rank)
void us(int a, int b)
{
    int x = fs(a), y = fs(b);
    if (x == y) return;

    if (rnk[x] > rnk[y])
    {
        par[y] = x;
        sz[x] += sz[y];
        v[x].insert(v[x].end(), all(v[y]));
        v[y].clear();
    }
    else
    {
        par[x] = y;
        sz[y] += sz[x];
        v[y].insert(v[y].end(), all(v[x]));
        v[x].clear();
        if (rnk[x] == rnk[y]) ++rnk[y];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> m >> k;
    v.resize(n+1);

    for (int t1 = 1; t1 <= n; ++t1)
    {
        cin >> color[t1];
        v[t1].push_back(color[t1]);
        par[t1] = t1;
        sz[t1] = 1;
    }

    for (int t1 = 1; t1 <= m; ++t1)
    {
        int a, b;
        cin >> a >> b;
        us(a, b);
    }

    int ans = 0;
    vb fin(n+1, 0); // don't count for the same component again

    // for every component, find the color
    // with the highest frequency
    for (int t1 = 1; t1 <= n; ++t1)
    {
        int c = fs(t1); // current component
        if (fin[c]) continue; // already calculated
        fin[c] = 1;
        map <int,int> M;
        int col = 0;

        // mapping all the frequencies from the component
        for (int t2 = 0; t2 < v[c].size(); ++t2)
            ++M[v[c][t2]];

        // finding the highest frequency
        for (auto it: M)
            if (it.second > col) col = it.second;

        ans += (sz[c] - col);
    }

    cout << ans << '\n';


    return 0;
}
