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
using pss = pair <string,string>;
using vi = vector <int>;
using vb = vector <bool>;
using vii = vi::iterator;

#define INF (1<<30)
#define MOD 1000000007
#define mt make_tuple
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)
#define np nullptr


ci N = (2e5)+5;
int n, a[N], ans;
vi g[N];
vector <pii> dp[N];

void solve(int x, int p = -1)
{
    vector <pii> chd;

    for (ci &y: g[x])
    {
        if (y != p)
        {
            solve(y, x);

            for (auto &it: dp[y])
                chd.push_back(it);
        }
    }

    sort(all(chd));

    for (int t1 = 0; t1 < chd.size(); ++t1)
    {
        int t2 = t1-1;
        int mx1 = 0, mx2 = 0;

        while (t2+1 < chd.size() && chd[t2+1].first == chd[t1].first)
        {
            ++t2;

            if (chd[t2].second >= mx1)
                mx2 = mx1, mx1 = chd[t2].second;
            else if (chd[t2].second > mx2)
                mx2 = chd[t2].second;
        }

        if (a[x] % chd[t1].first == 0)
        {
            ans = max(ans, mx1+mx2+1);
            dp[x].push_back({chd[t1].first, mx1+1});

            while (a[x] % chd[t1].first == 0)
                a[x] /= chd[t1].first;
        }
        else ans = max(ans, mx1);

        t1 = t2;
    }

    for (int t1 = 2; t1*t1 <= a[x]; ++t1)
    {
        if (a[x] % t1 == 0)
        {
            dp[x].push_back({t1, 1});
            ans = max(ans, 1);

            while (a[x] % t1 == 0)
                a[x] /= t1;
        }
    }

    if (a[x] > 1)
    {
        dp[x].push_back({a[x], 1});
        ans = max(ans, 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n;

    for (int t1 = 0; t1 < n; ++t1)
        cin >> a[t1];

    for (int t1 = 1; t1 < n; ++t1)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    solve(0);
    cout << ans << '\n';


    return 0;
}
