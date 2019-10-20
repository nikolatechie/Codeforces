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


const int N = 100005;
int A[N], st[N<<2][20];
bool lazy[N<<2][20];
#define ln node<<1
#define rn ln|1
#define mid ((sl+sr)>>1)

void Build(int node, int sl, int sr, int &b)
{
    if (sl == sr)
    {
        if (A[sl]&(1<<b)) st[node][b] = 1;
        return;
    }

    Build(ln, sl, mid, b);
    Build(rn, mid+1, sr, b);
    st[node][b] = st[ln][b] + st[rn][b];
}

void pd(int &node, int &sl, int &sr, int &b)
{
    if (lazy[node][b])
    {
        if (sl != sr)
            lazy[ln][b] ^= 1,
            lazy[rn][b] ^= 1;

        st[node][b] = (sr-sl+1)-st[node][b]; // flip b-th bit
        lazy[node][b] = 0;
    }
}

void Update(int node, int sl, int sr, int &l, int &r, int &b)
{
    pd(node,sl,sr,b);
    if (sl > r || sr < l) return;

    if (sl >= l && sr <= r)
    {
        lazy[node][b] = 1;
        pd(node,sl,sr,b);
        return;
    }

    Update(ln, sl, mid, l, r, b);
    Update(rn, mid+1, sr, l, r, b);
    st[node][b] = st[ln][b] + st[rn][b];
}

int Query(int node, int sl, int sr, int &l, int &r, int &b)
{
    pd(node,sl,sr,b);
    if (sl > r || sr < l) return 0;
    if (sl >= l && sr <= r) return st[node][b];

    return Query(ln, sl, mid, l, r, b) +
        Query(rn, mid+1, sr, l, r, b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int t1 = 1; t1 <= n; ++t1)
        cin >> A[t1];

    for (int t1 = 0; t1 < 20; ++t1)
        Build(1, 1, n, t1);

    int q;
    cin >> q;

    while (q)
    {
        --q;
        int op, l, r;
        cin >> op >> l >> r;

        if (op == 1)
        {
            llint sum = 0;

            for (int t1 = 0; t1 < 20; ++t1)
                sum += (Query(1, 1, n, l, r, t1) * llint(1<<t1));

            cout << sum << '\n';
        }
        else
        {
            int x;
            cin >> x;

            for (int t1 = 0; t1 < 20; ++t1)
            {
                if (x&(1<<t1))
                    Update(1, 1, n, l, r, t1);
            }
        }
    }

    return 0;
}
