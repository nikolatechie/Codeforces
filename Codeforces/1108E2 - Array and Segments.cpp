// 1108E1/11081E - Works for both easy and hard version

#include <bits/stdc++.h>
using namespace std;

using ci = const int;
using ld = long double;
using llint = long long;
using ullint = unsigned long long;
using pii = pair <int,int>;
using vi = vector <int>;
using vb = vector <bool>;
using vii = vi::iterator;

#define INF (1<<30)
#define MOD 1000000007
#define mt make_tuple
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)


struct Node
{
    int mn, mx, lazy;
};

ci N = (1e5) + 5;
int n, m;
int a[N];
Node st[N<<2]; // segment tree
pii s[N];

// combining two nodes
void combine(int node, int sl, int sr)
{
    st[node].mn = min(st[node<<1].mn, st[(node<<1)|1].mn);
    st[node].mx = max(st[node<<1].mx, st[(node<<1)|1].mx);
}

// building the segment tree
void build(int node, int sl, int sr)
{
    if (sl == sr)
    {
        st[node].mn = st[node].mx = a[sl];
        return;
    }

    int mid = (sl+sr)>>1;
    build(node<<1, sl, mid);
    build((node<<1)|1, mid+1, sr);
    combine(node, sl, sr);
}

// push-down function for lazy propagation
void pd(int node, int sl, int sr)
{
    if (!st[node].lazy) return;

    if (sl != sr)
        st[node<<1].lazy += st[node].lazy,
        st[(node<<1)|1].lazy += st[node].lazy;

    st[node].mn += st[node].lazy;
    st[node].mx += st[node].lazy;
    st[node].lazy = 0;
}

// updating in segment tree
void update(int node, int sl, int sr, int l, int r, int v)
{
    pd(node, sl, sr);
    if (sl > r || sr < l) return;

    if (sl >= l && sr <= r)
    {
        st[node].lazy += v;
        pd(node, sl, sr);
        return;
    }

    int mid = (sl+sr)>>1;
    update(node<<1, sl, mid, l, r, v);
    update((node<<1)|1, mid+1, sr, l, r, v);
    combine(node, sl, sr);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m;
    int MN = INF, MX = -INF;

    for (int t1 = 1; t1 <= n; ++t1)
    {
        cin >> a[t1];
        MN = min(MN, a[t1]);
        MX = max(MX, a[t1]);
    }

    int ans = MX-MN;

    for (int t1 = 1; t1 <= m; ++t1)
        cin >> s[t1].first >> s[t1].second;

    vi ccur;
    build(1, 1, n);
    vb applied(m+1, 0);

    // treat t1 as the max value and apply all
    // segment operations that don't include t1
    for (int t1 = 1; t1 <= n; ++t1)
    {
        vi cur;

        for (int t2 = 1; t2 <= m; ++t2)
        {
            if (!(s[t2].first <= t1 && s[t2].second >= t1))
            {
                cur.push_back(t2);

                if (!applied[t2])
                {
                    update(1, 1, n, s[t2].first, s[t2].second, -1);
                    applied[t2] = 1;
                }
            }
            else
            {
                if (applied[t2])
                {
                    applied[t2] = 0;
                    update(1, 1, n, s[t2].first, s[t2].second, 1);
                }
            }
        }

        int mn = st[1].mn;
        int mx = st[1].mx;

        // update the answer correspondingly
        if (mx-mn > ans)
        {
            ans = mx-mn;
            ccur = cur;
        }
    }

    cout << ans << '\n';
    cout << ccur.size() << '\n';

    for (int t1 = 0; t1 < ccur.size(); ++t1)
        cout << ccur[t1] << ' ';

    cout << '\n';


    return 0;
}
