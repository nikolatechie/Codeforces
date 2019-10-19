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


ci N = (5e5)+5;
int n, sz[N], h[N], cntf[N];
vector <vpii> v;
string s;
vector <vi> g;
bool big[N], cnt[N][26], ans[N];

void DFS(int x)
{
    sz[x] = 1;

    for (ci &y: g[x])
        h[y] = h[x]+1,
        DFS(y),
        sz[x] += sz[y];
}

void Add(int x, int val)
{
    cntf[h[x]] -= cnt[h[x]][s[x]-'a'];
    cnt[h[x]][s[x]-'a'] ^= 1;
    cntf[h[x]] += cnt[h[x]][s[x]-'a'];

    for (ci &y: g[x])
    {
        if (!big[y])
            Add(y, x);
    }
}

void DFS(int x, bool keep)
{
    int sc = -1;

    for (ci &y: g[x])
        if (sc == -1 || sz[y] > sz[sc])
            sc = y;

    for (ci &y: g[x])
        if (y != sc) DFS(y, 0);

    if (sc != -1)
        DFS(sc, 1), big[sc] = 1;

    Add(x, 1);
    // answer queries
    for (auto q: v[x])
        ans[q.second] = (cntf[q.first] <= 1);

    if (sc != -1)
        big[sc] = 0;

    if (!keep)
        Add(x, -1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int m;
    cin >> n >> m;
    g.resize(n+1);
    v.resize(n+1);

    for (int t1 = 1; t1 < n; ++t1)
    {
        int p;
        cin >> p;
        g[p-1].push_back(t1);
    }

    DFS(0);
    cin >> s;

    for (int t1 = 0; t1 < m; ++t1)
    {
        int x, h;
        cin >> x >> h;
        v[x-1].push_back({h-1, t1});
    }

    DFS(0, 0);

    for (int t1 = 0; t1 < m; ++t1)
        cout << (ans[t1] ? "Yes":"No") << '\n';


    return 0;
}
