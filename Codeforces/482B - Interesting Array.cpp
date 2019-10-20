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


const int N = 100005, MX = (1<<30)-1; // all 1s
int l[N], r[N], q[N], a[N], sum[N], st[N<<2];
#define ln node<<1
#define rn ln|1
#define mid ((sl+sr)>>1)

void Build(int node, int sl, int sr)
{
    if (sl == sr)
    {
        st[node] = a[sl];
        return;
    }

    Build(ln, sl, mid);
    Build(rn, mid+1, sr);
    st[node] = st[ln] & st[rn];
}

int Query(int node, int sl, int sr, int &l, int r)
{
    if (sl > r || sr < l) return MX;
    if (sl >= l && sr <= r) return st[node];

    if (r <= mid)
        return Query(ln, sl, mid, l, r);
    else if (l > mid)
        return Query(rn, mid+1, sr, l, r);
    else
        return Query(ln, sl, mid, l, r) &
            Query(rn, mid+1, sr, l, r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int t1 = 0; t1 < m; ++t1)
        cin >> l[t1] >> r[t1] >> q[t1], --l[t1];

    for (int b = 0; b <= 30; ++b)
    {
        ms(sum,0);

        for (int t1 = 0; t1 < m; ++t1)
        {
            if (q[t1]&(1<<b))
            {
                ++sum[l[t1]];
                --sum[r[t1]];
            }
        }

        for (int t1 = 0; t1 < n; ++t1)
        {
            if (t1) sum[t1] += sum[t1-1];
            if (sum[t1]) a[t1] |= (1<<b);
        }
    }

    Build(1, 0, n);

    for (int t1 = 0; t1 < m; ++t1)
    {
        if (Query(1, 0, n, l[t1], r[t1]-1) != q[t1])
        {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    for (int t1 = 0; t1 < n; ++t1)
        cout << a[t1] << ' ';

    cout << '\n';


    return 0;
}
