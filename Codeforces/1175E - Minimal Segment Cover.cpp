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
using vll = vector <ll>;
using vii = vi::iterator;

#define INF (0x3f3f3f3f)
#define MOD 1000000007
#define mt make_tuple
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof (name))
#define np nullptr


ci N = (5e5)+5, LN = 18;
int n, m, nxt[N], st[LN][N];
pii a[N], q[N];
#define xx first
#define yy second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int t1 = 0; t1 < n; ++t1)
        cin >> a[t1].xx >> a[t1].yy;

    for (int t1 = 0; t1 < m; ++t1)
        cin >> q[t1].xx >> q[t1].yy;

    sort(a, a+n);
    int lst = 0;
    pii mx(0, -1);

    for (int t1 = 0; t1 < N; ++t1)
    {
        while (lst < n && a[lst].xx == t1)
        {
            mx = max(mx, {a[lst].yy, lst});
            ++lst;
        }

        nxt[t1] = (mx.xx <= t1 ? -1:mx.yy);
    }

    for (int t1 = 0; t1 < n; ++t1)
        st[0][t1] = nxt[a[t1].yy];

    for (int t2 = 1; t2 < LN; ++t2)
    {
        for (int t1 = 0; t1 < n; ++t1)
        {
            if (st[t2-1][t1] == -1)
                st[t2][t1] = -1;
            else
                st[t2][t1] = st[t2-1][st[t2-1][t1]];
        }
    }

    for (int t1 = 0; t1 < m; ++t1)
    {
        int x = nxt[q[t1].xx];

        if (x == -1)
        {
            cout << -1 << '\n';
            continue;
        }

        int res = 1;

        for (int t2 = LN-1; t2 >= 0; --t2)
        {
            int y = st[t2][x];

            if (y == -1)
                continue;

            if (a[y].yy < q[t1].yy)
            {
                res += (1<<t2);
                x = y;
            }
        }

        if (a[x].yy >= q[t1].yy)
            cout << res << '\n';
        else if (st[0][x] == -1)
            cout << -1 << '\n';
        else
            cout << res+1 << '\n';
    }


    return 0;
}
