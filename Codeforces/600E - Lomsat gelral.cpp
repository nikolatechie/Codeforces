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
int n, col[N], sz[N], cnt[N], sc[N], mx, skip;
ll ans[N], sum; // sum of dominating colors
vector <vi> g;

void DFS(int x, int p)
{
    sz[x] = 1;

    for (ci &y: g[x])
        if (y != p)
    {
        DFS(y, x);
        sz[x] += sz[y];

        if (sz[y] > sz[sc[x]])
            sc[x] = y;
    }
}

void Add(int x, int p, int val)
{
    cnt[col[x]] += val;

    if (cnt[col[x]] >= mx)
    {
        if (cnt[col[x]] == mx)
            sum += col[x];
        else
            sum = col[x], mx = cnt[col[x]];
    }

    for (ci &y: g[x])
        if (y != p && y != skip) Add(y, x, val);
}

void DFS(int x, int p, bool keep)
{
    for (ci &y: g[x])
    {
        if (y != p && y != sc[x])
            DFS(y, x, 0);
    }

    if (sc[x])
        DFS(sc[x], x, 1), skip = sc[x];

    Add(x, p, 1);
    // now answer queries
    ans[x] = sum;
    skip = 0;

    if (!keep)
        Add(x, p, -1), sum = mx = 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n;
    g.resize(n+1);

    for (int t1 = 1; t1 <= n; ++t1)
        cin >> col[t1];

    for (int t1 = 1; t1 < n; ++t1)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    DFS(1, -1);
    DFS(1, -1, 0);

    for (int t1 = 1; t1 <= n; ++t1)
        cout << ans[t1] << ' ';

    cout << '\n';


    return 0;
}
