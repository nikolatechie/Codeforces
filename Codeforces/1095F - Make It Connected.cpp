#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

using ci = const int;
using ld = long double;
using llint = long long;
using ullint = unsigned long long;
using pii = pair <int,int>;
using pcc = pair <char,char>;
using pll = pair <llint,llint>;
using pss = pair <string,string>;
using vi = vector <int>;
using vb = vector <bool>;
using vll = vector <llint>;
using vii = vi::iterator;

#define INF (1<<30)
#define MOD 1000000007
#define mt make_tuple
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)
#define np nullptr


struct Offer
{
    int x, y;
    llint w;

    inline bool operator<(const Offer &o) const
    {
        return (w < o.w);
    }
};

ci N = (2e5)+5;
int n, m, r = 1, p[N], rnk[N];
llint a[N];
vector <Offer> v;

int fs(int x)
{
    return (x == p[x]) ? x:(p[x] = fs(p[x]));
}

inline bool ss(int x, int y)
{
    return (fs(x) == fs(y));
}

void us(int x, int y)
{
    int a = fs(x), b = fs(y);

    if (a != b)
    {
        if (rnk[a] > rnk[b])
            p[b] = a;
        else
        {
            p[a] = b;
            if (rnk[a] == rnk[b]) ++rnk[b];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> m;

    for (int t1 = 1; t1 <= n; ++t1)
        p[t1] = t1;

    for (int t1 = 1; t1 <= n; ++t1)
    {
        cin >> a[t1];
        if (a[t1] < a[r]) r = t1;
    }

    for (int t1 = 1; t1 <= n; ++t1)
        if (t1 != r) v.push_back({r, t1, a[r]+a[t1]});

    for (int t1 = 1; t1 <= m; ++t1)
    {
        int x, y;
        llint w;
        cin >> x >> y >> w;
        v.push_back({x, y, w});
    }

    sort(all(v));
    llint cost = 0;

    for (const auto it: v)
    {
        if (!ss(it.x, it.y))
        {
            us(it.x, it.y);
            cost += it.w;
        }
    }

    cout << cost << '\n';


    return 0;
}
