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
    int op = 0, cl = 0, mx = 0;
};

const int N = 1000005;
string s;
Node st[N<<2];

void Combine(Node &n, Node &l, Node &r)
{
    int matched = min(l.op, r.cl);
    n.op = l.op + r.op - matched;
    n.cl = l.cl + r.cl - matched;
    n.mx = l.mx + r.mx + (matched<<1);
}

void Build(int node, int sl, int sr)
{
    if (sl == sr)
    {
        if (s[sl] == '(')
            st[node].op = 1;
        else
            st[node].cl = 1;

        return;
    }

    int mid = (sl+sr)>>1, ln = node<<1, rn = ln|1;
    Build(ln, sl, mid);
    Build(rn, mid+1, sr);
    Combine(st[node], st[ln], st[rn]);
}

Node Query(int node, int sl, int sr, int &l, int &r)
{
    if (r < sl || l > sr) return Node();
    if (sl >= l && sr <= r) return st[node];

    int mid = (sl+sr)>>1, ln = node<<1, rn = ln|1;

    if (r <= mid)
        return Query(ln, sl, mid, l, r);
    else if (l > mid)
        return Query(rn, mid+1, sr, l, r);
    else
    {
        Node A = Query(ln, sl, mid, l, r);
        Node B = Query(rn, mid+1, sr, l, r);
        Node ans;
        Combine(ans, A, B);
        return ans;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> s >> q;
    s = " " + s;
    n = s.size()-1;
    Build(1, 1, n);

    while (q)
    {
        --q;
        int l, r;
        cin >> l >> r;
        cout << Query(1, 1, n, l, r).mx << '\n';
    }

    return 0;
}
