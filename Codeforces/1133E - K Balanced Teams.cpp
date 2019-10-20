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


ci N = 5005;
int n, k, a[N], dp[N][N], cnt[N];

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> k;

    for (int t1 = 0; t1 < n; ++t1)
        cin >> a[t1];

    sort(a, a+n);

    for (int t1 = 0; t1 < n; ++t1)
    {
        while (t1+cnt[t1] < n && a[t1+cnt[t1]]-a[t1] <= 5)
            ++cnt[t1];
    }

    for (int t1 = 0; t1 < n; ++t1)
    {
        for (int t2 = 0; t2 <= k; ++t2)
        {
            dp[t1+1][t2] = max(dp[t1+1][t2], dp[t1][t2]);

            if (t2+1 <= k)
                dp[t1+cnt[t1]][t2+1] = max(dp[t1+cnt[t1]][t2+1],
                                           dp[t1][t2] + cnt[t1]);
        }
    }

    cout << dp[n][k] << '\n';


    return 0;
}
