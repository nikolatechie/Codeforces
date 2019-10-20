#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

using ld = long double;
using llint = long long;
using ullint = unsigned long long;
using pii = pair <int,int>;
using pcc = pair <char,char>;
using pss = pair <string,string>;
using vi = vector<int>;
using vii = vi::iterator;

#define INF (1<<30)
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define all(c) c.begin(),c.end()
#define ms(name,val) memset(name, val, sizeof name)
#define np nullptr


struct Node
{
    int cnt = 0, lazy = -1;
};

#define ln node<<1
#define rn ln|1
const int N = 500005;
Node st[N<<2];
int start[N], finish[N], parent[N];
vector <vector <int>> graf;

void DFS(int u, int par)
{
    static int timer = 0;
    parent[u] = par;
    start[u] = ++timer;

    for (int t1 = 0; t1 < graf[u].size(); ++t1)
    {
        int v = graf[u][t1];
        if (v != u && v != par) DFS(v, u);
    }

    finish[u] = timer;
}

void pd(int &node, int &sl, int &sr)
{
    if (st[node].lazy != -1)
    {
        if (sl != sr)
            st[ln].lazy = st[rn].lazy = st[node].lazy;

        st[node].cnt = st[node].lazy*(sr-sl+1);
        st[node].lazy = -1;
    }
}

void Update(int node, int sl, int sr, int &l, int &r, int v)
{
    pd(node, sl, sr);
    if (sl > r || sr < l) return;

    if (sl >= l && sr <= r)
    {
        st[node].lazy = v;
        pd(node, sl, sr);
        return;
    }

    int mid = (sl+sr)>>1;
    Update(ln, sl, mid, l ,r ,v);
    Update(rn, mid+1, sr, l, r, v);
    st[node].cnt = st[ln].cnt + st[rn].cnt;
}

int Query(int node, int sl, int sr, int &l, int &r)
{
    pd(node, sl, sr);
    if (sl > r || sr < l) return 0;
    if (sl >= l && sr <= r) return st[node].cnt;

    int mid = (sl+sr)>>1;
    return Query(ln, sl, mid, l, r) +
        Query(rn, mid+1, sr, l, r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    graf.resize(n+1);

    for (int t1 = 0; t1 < n-1; ++t1)
    {
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    DFS(1, -1);

    int q;
    cin >> q;

    while (q)
    {
        --q;
        int op, v;
        cin >> op >> v;

        if (op == 1)
        {
            if (Query(1, 1, n, start[v], finish[v]) < (finish[v]-start[v]+1))
                Update(1, 1, n, start[parent[v]], start[parent[v]], 0);

            Update(1, 1, n, start[v], finish[v], 1);
        }
        else if (op == 2)
            Update(1, 1, n, start[v], start[v], 0);
        else
            cout << !(Query(1,1,n,start[v],finish[v]) < (finish[v]-start[v]+1)) << '\n';
    }

    return 0;
}
