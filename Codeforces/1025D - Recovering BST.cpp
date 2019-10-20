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

#define INF (1<<30)
#define MOD 1000000007
#define mt make_tuple
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)
#define np nullptr


ci N = 705;
int n, a[N], check[N][N], dp[N][N][2];

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n;

    for (int t1 = 1; t1 <= n; ++t1)
        cin >> a[t1];

    for (int t1 = 0; t1 <= n+1; ++t1)
    {
        for (int t2 = 0; t2 <= n+1; ++t2)
        {
            check[t1][t2] = (__gcd(a[t1], a[t2]) > 1);
            if (t2 < t1) dp[t1][t2][0] = dp[t1][t2][1] = 1;
        }
    }

    for (int len = 1; len <= n; ++len)
    {
        for (int l = 1; l+len-1 <= n; ++l)
        {
            int r = l+len-1;

            for (int k = l; k <= r; ++k)
            {
                dp[l][r][0] |= (check[l-1][k] & dp[l][k-1][1] & dp[k+1][r][0]);
                dp[l][r][1] |= (check[k][r+1] & dp[k+1][r][0] & dp[l][k-1][1]);
            }
        }
    }

    if (dp[1][n][0]|dp[1][n][1])
        cout << "Yes\n";
    else
        cout << "No\n";


    return 0;
}
