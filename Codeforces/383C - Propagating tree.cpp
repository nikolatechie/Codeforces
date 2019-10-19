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
    int val = 0, lazy = 0;
};

const int N = 200005;
Node st[2][N<<2];
int A[N], start[N], finish[N], discover[N], lvl[N];
vector <vector <int>> graf;

void DFS(int cvor, int parent, int _lvl)
{
    static int timer = 0;
    start[cvor] = ++timer;
    discover[timer] = cvor;
    lvl[cvor] = _lvl;

    for (int t1 = 0; t1 < graf[cvor].size(); ++t1)
    {
        int susjed = graf[cvor][t1];
        if (susjed != cvor && susjed != parent) DFS(susjed,cvor,_lvl+1);
    }

    finish[cvor] = timer;
}

void Build(int node, int sl, int sr)
{
    if (sl == sr)
    {
        // po discoveru
        st[0][node].val = st[1][node].val = A[discover[sl]];
        return;
    }

    int mid = (sl+sr)>>1;
    Build(node<<1, sl, mid);
    Build((node<<1)|1, mid+1, sr);
}

void pd(int &node, int &sl, int &sr)
{
    if (st[0][node].lazy)
    {
        if (sl != sr)
            st[0][node<<1].lazy += st[0][node].lazy,
            st[0][(node<<1)|1].lazy += st[0][node].lazy;

        st[0][node].val += st[0][node].lazy;
        st[0][node].lazy = 0;
    }

    if (st[1][node].lazy)
    {
        if (sl != sr)
            st[1][node<<1].lazy += st[1][node].lazy,
            st[1][(node<<1)|1].lazy += st[1][node].lazy;

        st[1][node].val += st[1][node].lazy;
        st[1][node].lazy = 0;
    }
}

void Add(bool &parity, int node, int sl, int sr, int &l, int &r, int &v)
{
    pd(node,sl,sr);
    if (sl > r || sr < l) return;

    if (sl >= l && sr <= r)
    {
        st[parity][node].lazy = v;
        st[parity^1][node].lazy = -v;
        pd(node,sl,sr);
        return;
    }

    int mid = (sl+sr)>>1;
    Add(parity, node<<1, sl, mid, l, r, v);
    Add(parity, (node<<1)|1, mid+1, sr, l, r, v);
}

void Print(bool &parity, int node, int sl, int sr, int &i)
{
    pd(node,sl,sr);

    if (sl == sr)
    {
        cout << st[parity][node].val << '\n';
        return;
    }

    int mid = (sl+sr)>>1;

    if (i <= mid)
        Print(parity, node<<1, sl, mid, i);
    else
        Print(parity, (node<<1)|1, mid+1, sr, i);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    graf.resize(n+1);

    for (int t1 = 1; t1 <= n; ++t1)
        cin >> A[t1];

    for (int t1 = 0; t1 < n-1; ++t1)
    {
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    DFS(1, -1, 1);
    Build(1, 1, n);

    while (q)
    {
        --q;
        int opt, cvor;
        cin >> opt >> cvor;
        bool parity = lvl[cvor]%2;

        if (opt == 1)
        {
            int x;
            cin >> x;
            Add(parity, 1, 1, n, start[cvor], finish[cvor], x);
        }
        else Print(parity, 1, 1, n, start[cvor]);
    }


    return 0;
}
