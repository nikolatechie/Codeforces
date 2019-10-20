#include <bits/stdc++.h>
using namespace std;

using ci = const int;
using llint = long long;
using vi = vector <int>;

ci MX = (100002<<2);
int n, color[MX], in[MX], out[MX], ew[MX];
vector <vi> g;
vector <llint> st, lazy;

void DFS(int node, int p)
{
    static int time = 0;
    in[node] = ++time;
    ew[time] = node;

    for (int &x: g[node])
        if (x != node && x != p) DFS(x, node);

    out[node] = time;
}

void Build(int node, int sl, int sr)
{
    if (sl == sr)
    {
        st[node] = (1LL << color[ew[sl]]);
        return;
    }

    int mid = (sl+sr)>>1, ln = node<<1, rn = ln|1;
    Build(ln, sl, mid);
    Build(rn, mid+1, sr);
    st[node] = st[ln] | st[rn];
}

void pd(int node, int sl, int sr)
{
    if (lazy[node] != -1)
    {
        if (sl != sr)
            lazy[node<<1] = lazy[(node<<1)|1] = lazy[node];

        st[node] = lazy[node];
        lazy[node] = -1;
    }
}

void Paint(int node, int sl, int sr, int l, int r, int col)
{
    pd(node, sl, sr);
    if (sl > r || sr < l) return;

    if (sl >= l && sr <= r)
    {
        lazy[node] = (1LL << col);
        pd(node, sl, sr);
        return;
    }

    int mid = (sl+sr)>>1, ln = node<<1, rn = ln|1;
    Paint(ln, sl, mid, l, r, col);
    Paint(rn, mid+1, sr, l, r, col);
    st[node] = st[ln] | st[rn];
}

llint Query(int node, int sl, int sr, int l, int r)
{
    pd(node, sl, sr);
    if (sl > r || sr < l) return 0;
    if (sl >= l && sr <= r) return st[node];

    int mid = (sl+sr)>>1;
    return (Query(node<<1, sl, mid, l, r) |
            Query((node<<1)|1, mid+1, sr, l, r));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int q;
    cin >> n >> q;
    g.resize(n+1);
    st.resize(MX<<2);
    lazy.assign(MX<<2, -1);

    for (int t1 = 1; t1 <= n; ++t1)
        cin >> color[t1];

    for (int t1 = 0; t1 < n-1; ++t1)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    DFS(1, -1);
    Build(1, 1, n);

    while (q)
    {
        --q;
        int op, v;
        cin >> op >> v;

        if (op == 1)
        {
            int c;
            cin >> c;
            Paint(1, 1, n, in[v], out[v], c);
        }
        else
        {
            llint mask = Query(1, 1, n, in[v], out[v]);
            int cnt = 0;

            for (int t1 = 0; t1 < 61; ++t1)
                cnt += (1&(mask>>t1));

            cout << cnt << '\n';
        }
    }

    return 0;
}
