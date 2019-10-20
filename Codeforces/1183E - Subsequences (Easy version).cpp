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


ci N = 105;
string s;
ll dp[N][N], n;
ll ans, k;
map <char,int> lst;

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> k >> s;
    s = ' ' + s;
    dp[0][0] = 1;

    for (int t1 = 1; t1 <= n; ++t1)
    {
        for (int t2 = 0; t2 <= n; ++t2)
        {
            dp[t1][t2] = dp[t1-1][t2];
            if (!t2) continue;

            dp[t1][t2] += dp[t1-1][t2-1];

            if (lst[s[t1]])
                dp[t1][t2] -= dp[lst[s[t1]]-1][t2-1];
        }

        lst[s[t1]] = t1;
    }

    for (int t1 = n; t1 >= 0; --t1)
    {
        if (k >= dp[n][t1])
        {
            k -= dp[n][t1];
            ans += (dp[n][t1]*(n-t1));
        }
        else
        {
            ans += (k*(n-t1));
            k = 0;
            break;
        }
    }

    if (k)
        ans = -1;

    cout << ans << '\n';


    return 0;
}
