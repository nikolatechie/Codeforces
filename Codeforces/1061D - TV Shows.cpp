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


ci N = (1e5)+5;
ci mod = (1e9)+7;
llint n, x, y, ans = 0, cost[N];
pll a[N];
multiset <pair <pll,llint>> s;
#define xx first
#define yy second

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> x >> y;

    for (int t1 = 1; t1 <= n; ++t1)
    {
        cin >> a[t1].xx >> a[t1].yy;
        s.insert({{a[t1].yy, a[t1].xx}, t1});
    }

    sort(a+1, a+n+1);

    for (int t1 = 1; t1 <= n; ++t1)
    {
        cost[t1] = (x + y*(a[t1].yy-a[t1].xx));

        if (s.empty() || s.begin()->xx.xx >= a[t1].xx)
            continue;

        auto it = s.lower_bound({{a[t1].xx, 0}, 0});
        llint pR = (--it)->xx.xx;

        if (y*(a[t1].yy-pR) >= cost[t1])
            continue;

        cost[t1] = y*(a[t1].yy-pR);
        cost[t1] %= mod;
        s.erase(it);
    }

    for (int t1 = 1; t1 <= n; ++t1)
        ans = (ans + cost[t1]) % mod;

    cout << ans << '\n';


    return 0;
}
