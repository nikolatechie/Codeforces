#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

using ci = const int;
using ld = long double;
using llint = long long;
using ullint = unsigned long long;
using pii = pair <int,int>;
using pcc = pair <char,char>;
using pss = pair <string,string>;
using vi = vector <int>;
using vb = vector <bool>;
using vii = vi::iterator;

#define INF (1<<30)
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)
#define np nullptr


struct CentroidDecomposition
{
    vector <set <int>> g;
    vi parent, sz, ans;

    CentroidDecomposition(vector <set <int>> &_g): g(_g)
    {
        int n = g.size();
        parent.resize(n);
        sz.resize(n);
        ans.assign(n, INF);
        ans[0] = 0;
        Build(0, -1);
    }

    void Build(int x, int p)
    {
        int n = findSz(x, p);
        int centroid = findCentroid(x, p, n);
        if (p == -1) p = centroid;
        parent[centroid] = p;
        set <int>::iterator it = g[centroid].begin();

        for (; !g[centroid].empty();)
        {
            int y = *it;
            g[centroid].erase(it);
            g[y].erase(centroid);
            Build(y, centroid);
            it = g[centroid].begin();
        }
    }

    int findSz(int x, int p)
    {
        sz[x] = 1;

        for (auto y: g[x])
            if (y != p) sz[x] += findSz(y, x);

        return sz[x];
    }

    int findCentroid(int x, int p, int n)
    {
        for (auto y: g[x])
            if (y != p && sz[y] > n/2) return findCentroid(y, x, n);

        return x;
    }
};

ci N = 100005, LN = 17;
int link[N][LN], depth[N];
int n;
vector <set <int>> g;

struct BinaryLifting
{
    BinaryLifting()
    {
        ms(link, -1);
        DFS(0, -1);
        solve();
    }

    void DFS(int x, int p)
    {
        link[x][0] = p;
        if (p != -1) depth[x] = 1 + depth[p];

        for (ci &y: g[x])
            if (y != p) DFS(y, x);
    }

    void solve()
    {
        for (int lvl = 0; lvl < LN-1; ++lvl)
        {
            for (int x = 0; x < n; ++x)
            {
                if (link[x][lvl] != -1)
                    link[x][lvl+1] = link[link[x][lvl]][lvl];
            }
        }
    }

    int LCA(int a, int b)
    {
        if (depth[b] > depth[a]) return LCA(b,a);

        for (int lvl = LN-1; lvl >= 0; --lvl)
            if (depth[a]-(1<<lvl) >= depth[b]) a = link[a][lvl];

        if (a != b)
        {
            for (int lvl = LN-1; lvl >= 0; --lvl)
            {
                if (link[a][lvl] != link[b][lvl])
                {
                    a = link[a][lvl];
                    b = link[b][lvl];
                }
            }

            a = link[a][0];
        }

        return a;
    }

    int dist(int a, int b)
    {
        int lca = LCA(a, b);

        if (lca == a) return (depth[b]-depth[a]);
        if (lca == b) return (depth[a]-depth[b]);
        return (depth[a]+depth[b] - (depth[lca]<<1));
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int q;
    cin >> n >> q;
    g.resize(n);

    for (int t1 = 0; t1 < n-1; ++t1)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].insert(b);
        g[b].insert(a);
    }

    BinaryLifting bl;
    CentroidDecomposition cd(g);

    int Y = 0;

    while (cd.parent[Y] != Y)
    {
        Y = cd.parent[Y];
        cd.ans[Y] = min(cd.ans[Y], bl.dist(0, Y));
    }

    while (q)
    {
        --q;
        int op, x;
        cin >> op >> x;
        --x;

        // paint
        if (op == 1)
        {
            cd.ans[x] = 0;
            int y = x;

            while (cd.parent[y] != y)
            {
                y = cd.parent[y];
                cd.ans[y] = min(cd.ans[y], bl.dist(x, y));
            }
        }
        else // query
        {
            if (cd.ans[x] == 0)
            {
                cout << 0 << '\n';
                continue;
            }

            int len = cd.ans[x];
            int y = x;

            while (cd.parent[y] != y)
            {
                y = cd.parent[y];
                int tmp = cd.ans[y] + bl.dist(x, y);
                len = min(len, tmp);
            }

            cout << len << '\n';
        }
    }


    return 0;
}
