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
// inline functions


struct Node
{
    int c4, c7, li, ld;
    bool flip;

    Node()
    {
        c4 = c7 = li = ld = flip = 0;
    }
};

ci N = (1e6)+5;
int n ;
string s;
Node st[N<<2];
#define ln (node<<1)
#define rn (node<<1)|1

void pd(int node, int sl, int sr)
{
    if (!st[node].flip) return;
    st[node].flip = 0;

    if (sl != sr)
        st[ln].flip ^= 1, st[rn].flip ^= 1;

    swap(st[node].li, st[node].ld);
    swap(st[node].c4, st[node].c7);
}

void combine(int node, int sl, int sr)
{
    if (sl == sr) return;

    st[node].c4 = st[ln].c4 + st[rn].c4;
    st[node].c7 = st[ln].c7 + st[rn].c7;

    st[node].li = max({
                    //st[node].li,
                    st[ln].c4 + st[rn].c4,
                    st[ln].c7 + st[rn].c7,
                    st[ln].c4 + st[rn].li,
                    st[ln].c4 + st[rn].c7,
                    st[ln].li + st[rn].c7
                      });

    st[node].ld = max({
                    //st[node].ld,
                    st[ln].c4 + st[rn].c4,
                    st[ln].c7 + st[rn].c7,
                    st[ln].c7 + st[rn].ld,
                    st[ln].c7 + st[rn].c4,
                    st[ln].ld + st[rn].c4
                      });
}

void Build(int node, int sl, int sr)
{
    if (sl == sr)
    {
        if (s[sl] == '4')
            ++st[node].c4;
        else
            ++st[node].c7;

        st[node].li = st[node].ld = 1;
        return;
    }

    int sm  = (sl+sr)>>1;
    Build(ln, sl, sm);
    Build(rn, sm+1, sr);
    combine(node, sl, sr);
}

void Switch(int node, int sl, int sr, int l, int r)
{
    pd(node, sl, sr);
    if (sl > r || sr < l) return;

    if (sl >= l && sr <= r)
    {
        st[node].flip = 1;
        pd(node, sl, sr);
        return;
    }

    int sm = (sl+sr)>>1;
    Switch(ln, sl, sm, l, r);
    Switch(rn, sm+1, sr, l, r);
    combine(node, sl, sr);
}

void Print(int node, int sl, int sr)
{
    pd(node, sl, sr);
    int sm = (sl+sr)>>1;

    if (sl != sr)
    {
        Print(ln, sl, sm);
        Print(rn, sm+1, sr);
    }

    combine(node, sl, sr);

    cout << "Cvor " << node << '\n';
    cout << st[node].c4 << ' ' << st[node].li << '\n';
    cout << " " << st[node].flip << '\n';
    cout << st[node].c7 << ' ' << st[node].ld << '\n';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int q;
    cin >> n >> q;
    cin >> s;
    s = " " + s;
    Build(1, 1, n);

    while (q)
    {
        --q;
        string op;
        cin >> op;

        if (op[0] == 'c')
            cout << st[1].li << '\n';
        else
        {
            int l, r;
            cin >> l >> r;
            Switch(1, 1, n, l, r);
        }

        //Print(1, 1, n);
    }


    return 0;
}
