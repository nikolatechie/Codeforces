#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

using ci = const int;
using ld = long double;
using ll = long long;
using ull = unsigned long long;
using pii = pair <int,int>;
using pcc = pair <char,char>;
using pll = pair <ll,ll>;
using pss = pair <string,string>;
using vi = vector <int>;
using vb = vector <bool>;
using vpii = vector <pii>;
using vll = vector <ll>;
using vii = vi::iterator;

#define INF (0x3f3f3f3f)
#define MOD 1000000007
#define mt make_tuple
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof (name))
#define np nullptr


ci N = (1e5)+5;
vector <vi> g, ft;
int inTree[N], depth[N];

void DFS(int x, int p, int d, int chain)
{
    inTree[x] = chain;
    depth[x] = d;
    ft[chain].push_back(0);

    for (ci &y: g[x])
        if (y != p) DFS(y, x, d+1, chain);
}

void Update(int i, int v, int chain)
{
    for (; i < ft[chain].size(); i += i&(-i))
        ft[chain][i] += v;
}

int Query(int i, int chain)
{
    int ans = 0;

    for (; i > 0; i -= i&(-i))
        ans += ft[chain][i];

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n, q;
    cin >> n >> q;
    g.resize(n);

    for (int t1 = 0; t1 < n-1; ++t1)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int inRoot = 0;
    ft.resize(g[0].size()+1);

    for (int t1 = 0; t1 < g[0].size(); ++t1)
    {
        ft[t1].push_back(0);
        DFS(g[0][t1], 0, 1, t1);
    }

    ft[ft.size()-1].resize(n+10);

    for (int t1 = 0; t1 < q; ++t1)
    {
        int op;
        cin >> op;

        if (!op)
        {
            int v, val, dist;
            cin >> v >> val >> dist;
            --v;

            if (!v)
            {
                inRoot += val;
                Update(1, val, ft.size()-1);
                Update(dist+1, -val, ft.size()-1);
            }
            else
            {
                if (dist >= depth[v])
                {
                    int lft = dist-depth[v];
                    inRoot += val;
                    Update(1, val, ft.size()-1);
                    Update(lft+1, -val, ft.size()-1);
                    Update(lft+1, val, inTree[v]);
                    Update(depth[v]+dist+1, -val, inTree[v]);
                }
                else
                {
                    Update(depth[v]-dist, val, inTree[v]);
                    Update(depth[v]+dist+1, -val, inTree[v]);
                }
            }
        }
        else
        {
            int v;
            cin >> v;
            --v;

            if (!v)
                cout << inRoot << '\n';
            else
            {
                int ans = Query(depth[v], inTree[v])
                    + Query(depth[v], ft.size()-1);

                cout << ans << '\n';
            }
        }
    }


    return 0;
}
