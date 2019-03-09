#include <bits/stdc++.h>
using namespace std;

using ci = const int;
using ld = long double;
using llint = long long;
using ullint = unsigned long long;
using pii = pair <int,int>;
using vi = vector <int>;
using vb = vector <bool>;
using vii = vi::iterator;

#define INF (1<<30)
#define MOD 1000000007
#define mt make_tuple
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)


int n, ans;
vb vis;
vector <vi> g;

int DFS(int x)
{
    vis[x] = 1;
    int sz = 1;
    bool leaf = 1;

    for (ci &y: g[x])
    {
        if (!vis[y])
        {
            leaf = 0;
            sz += DFS(y);
        }
    }

    if (leaf)
        return 1;

    if (!(sz&1)) // cut this one
    {
        ++ans;
        return 0;
    }

    return sz;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n;
    g.resize(n);
    vis.resize(n);

    for (int t1 = 0; t1 < n-1; ++t1)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    if (n&1) // no possible solution
    {
        cout << -1 << '\n';
        return 0;
    }

    DFS(0);
    cout << ans-1 << '\n';


    return 0;
}
