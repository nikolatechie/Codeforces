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


ci N = 2005;
int n, k, a[N], dp[N];

int check(ll m)
{
    for (int t1 = 0; t1 < n; ++t1)
    {
        dp[t1] = t1;

        for (int t2 = 0; t2 < t1; ++t2)
        {
            if (abs(a[t1]-a[t2]) <= m*(t1-t2))
                dp[t1] = min(dp[t1], dp[t2] + t1-t2-1);
        }
    }

    int ans = n;

    for (int t1 = 0; t1 < n; ++t1)
        ans = min(ans, dp[t1]+n-t1-1);

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> k;

    for (int t1 = 0; t1 < n; ++t1)
        cin >> a[t1];

    ll l = 0, r = 0;

    for (int t1 = 1; t1 < n; ++t1)
        r = max(r, 1LL*abs(a[t1]-a[t1-1]));

    ll res = r;

    while (l <= r)
    {
        ll m = (l+r)>>1LL;

        if (check(m) <= k)
        {
            res = m;
            r = m-1;
        }
        else l = m+1;
    }

    cout << res << '\n';


    return 0;
}
