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


ci N = (1e5)+5;
vi v;
vector <vi> g;
using pr = pair <llint,llint>;

pr solve(int x, int p)
{
    pr res = {0LL, 0LL};

    for (ci &y: g[x])
    {
        if (y != p)
        {
            pr tmp = solve(y, x);
            res.first = max(res.first, tmp.first);
            res.second = min(res.second, tmp.second);
        }
    }

    v[x] -= (res.first+res.second);

    if (v[x] > 0LL)
        res.first += v[x];
    else
        res.second += v[x];

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n;
    cin >> n;
    g.resize(n+1);
    v.resize(n+1);

    for (int t1 = 1; t1 < n; ++t1)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int t1 = 1; t1 <= n; ++t1)
        cin >> v[t1];

    pr ans = solve(1, 0);
    cout << ans.first-ans.second << '\n';


    return 0;
}
