// Heavy-light decomposition solution
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


ci N = (2e5)+5, LN = 18; // or 19?
ll st[N<<2];
vpii edge;
int n, sz[N], par[LN][N], depth[N], posInBase[N], ptr, base[N];
int chainNo, chain[N], chainHead[N],chainSz[N], chainPos[N];
vector <vi> g;
#define xx first
#define yy second
#define ln (node<<1)
#define rn (node<<1)|1

void DFS(int x, int p, int d = 0)
{
    sz[x] = 1;
    par[0][x] = p;
    depth[x] = d;

    for (ci &y: g[x])
    {
        if (y != p)
        {
            DFS(y, x, d+1);
            sz[x] += sz[y];
        }
    }
}

void HLD(int x)
{
    if (chainHead[chainNo] == -1) chainHead[chainNo] = x;
    chain[x] = chainNo;
    chainPos[x] = chainSz[chainNo];
    ++chainSz[chainNo];
    base[ptr] = x;
    posInBase[x] = ptr++;
    int specialChild = -1;

    for (ci &y: g[x])
    {
        if (y != par[0][x])
        {
            if (specialChild == -1)
                specialChild = y;
            else if (sz[y] > sz[specialChild])
                specialChild = y;
        }
    }

    if (specialChild != -1)
        HLD(specialChild);

    for (ci &y: g[x])
    {
        if (y != par[0][x] && y != specialChild)
        {
            ++chainNo;
            HLD(y);
        }
    }
}

int LCA(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b); // or return?

    for (int lvl = LN-1; lvl >= 0; --lvl)
        if (depth[a]-(1<<lvl) >= depth[b]) a = par[lvl][a];

    if (a != b)
    {
        for (int lvl = LN-1; lvl >= 0; --lvl)
        {
            if (par[lvl][a] != par[lvl][b])
                a = par[lvl][a],
                b = par[lvl][b];
        }

        a = par[0][a];
    }

    return a;
}

int realDist(int a, int b, int lca)
{
    if (lca == a) return depth[b]-depth[a];
    if (lca == b) return depth[a]-depth[b];
    return (depth[a]+depth[b]-(depth[lca]<<1));
}

void Paint(int node, int sl, int sr, int i, int color)
{
    if (sl == sr)
    {
        st[node] = (color == 1) ? 0:1;
        return;
    }

    int sm = (sl+sr)>>1;

    if (i <= sm)
        Paint(ln, sl, sm, i, color);
    else
        Paint(rn, sm+1, sr, i, color);

    st[node] = st[ln] + st[rn];
}

int QuerySum(int node, int sl, int sr, int l, int r)
{
    if (sl > r || sr < l) return 0;
    if (sl >= l && sr <= r) return st[node];

    int sm = (sl+sr)>>1;

    return QuerySum(ln, sl, sm, l, r)
        + QuerySum(rn, sm+1, sr, l, r);
}

int ChainUP(int x, int lca)
{
    if (x == lca) return 0;
    int ans = 0, xchain, lchain = chain[lca];

    while (1)
    {
        xchain = chain[x];

        if (xchain == lchain)
        {
            if (x == lca) return ans;
            ans += QuerySum(1, 0, n-1, posInBase[lca]+1, posInBase[x]);
            return ans;
        }
        else
        {
            ans += QuerySum(1, 0, n-1, posInBase[chainHead[xchain]], posInBase[x]);
            x = chainHead[xchain];
            x = par[0][x];
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;
    g.resize(n);
    edge.resize(n-1);
    ms(par, -1);
    ms(chain, -1);
    ms(chainHead, -1);
    ms(chainPos, -1);

    for (int t1 = 0; t1 < n-1; ++t1)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        edge[t1] = {a,b};
        g[a].push_back(b);
        g[b].push_back(a);
    }

    DFS(0, -1);
    HLD(0);

    for (int lvl = 0; lvl < LN-1; ++lvl)
    {
        for (int x = 0; x < n; ++x)
        {
            if (par[lvl][x] != -1)
                par[lvl+1][x] = par[lvl][par[lvl][x]];
        }
    }

    int q;
    cin >> q;

    while (q)
    {
        --q;
        int type;
        cin >> type;

        if (type < 3)
        {
            int id;
            cin >> id;
            // paint edge 'id' to color white/black
            pii cur = edge[id-1];
            if (depth[cur.xx] < depth[cur.yy]) swap(cur.xx, cur.yy);
            Paint(1, 0, n-1, posInBase[cur.xx], type);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            --a, --b;
            int lca = LCA(a, b);
            // check if the path exists
            int suma = ChainUP(a, lca), sumb = ChainUP(b, lca);
            int dist = suma+sumb;
            /*cout << "Udaljenosti su: ";
            cout << suma << ' ' << sumb << '\n';*/

            if (dist != 0)
                cout << -1 << '\n';
            else
                cout << realDist(a,b,lca) << '\n';
        }
    }


    return 0;
}
