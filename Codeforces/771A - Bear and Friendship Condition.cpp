#include <bits/stdc++.h>
using namespace std;

using ci = const int;
using ld = long double;
using llint = long long;
using ullint = unsigned long long;
using pii = pair <int,int>;
using vi = vector <int>;
using vb = vector <bool>;

#define INF (1<<30)
#define MOD 1000000007
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)


int n, m;
llint sz, edges;
vb vis;
vector <vi> g;

void DFS(int node)
{
    vis[node] = 1;
    ++sz;
    edges += (g[node].size()-(sz-1));

    for (ci y: g[node])
        if (!vis[y]) DFS(y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> m;
    g.resize(n);
    vis.resize(n);
    bool ans = 1;

    for (int t1 = 0; t1 < m; ++t1)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int t1 = 0; t1 < n && ans; ++t1)
    {
        if (!vis[t1])
        {
            sz = edges = 0;
            DFS(t1);
            if (sz > 1) ans &= (edges == ((sz-1)*(sz)>>1));
        }
    }

    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";


    return 0;
}
