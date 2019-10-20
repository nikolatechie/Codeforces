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


struct Edge
{
    int a, b;
    ll w;

    inline bool operator<(Edge &e) const
    {
        return (w < e.w);
    }
};

ci N = (2e5)+5;
int n, q, par[N], rnk[N];
ll ans[N], cnt, sz[N];
pii qv[N];
Edge edge[N];

int fs(int x)
{
    return (par[x] == x) ? x:(par[x] = fs(par[x]));
}

void merge(int a, int b)
{
    int x = fs(a), y = fs(b);
    cnt -= (sz[x]*(sz[x]-1LL)/2LL);
    cnt -= (sz[y]*(sz[y]-1LL)/2LL);

    if (rnk[x] > rnk[y])
    {
        par[y] = x;
        sz[x] += sz[y];
        cnt += (sz[x]*(sz[x]-1LL)/2LL);
    }
    else
    {
        par[x] = y;
        sz[y] += sz[x];
        cnt += (sz[y]*(sz[y]-1LL)/2LL);
        if (rnk[x] == rnk[y]) ++rnk[y];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> q;

    for (int t1 = 1; t1 <= n; ++t1)
        par[t1] = t1, sz[t1] = 1LL;

    for (int t1 = 1; t1 < n; ++t1)
        cin >> edge[t1].a >> edge[t1].b >> edge[t1].w;

    for (int t1 = 1; t1 <= q; ++t1)
    {
        cin >> qv[t1].first;
        qv[t1].second = t1;
    }

    sort(edge+1, edge+n);
    sort(qv+1, qv+q+1);
    int i = 1; // pointer for edges

    for (int t1 = 1; t1 <= q; ++t1)
    {
        while (i < n && edge[i].w <= (ll)qv[t1].first)
        {
            merge(edge[i].a, edge[i].b);
            ++i;
        }

        ans[qv[t1].second] = cnt;
    }

    for (int t1 = 1; t1 <= q; ++t1)
        cout << ans[t1] << ' ';

    cout << '\n';


    return 0;
}
