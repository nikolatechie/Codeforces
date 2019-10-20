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


ci N = 5005;
int n, a[N], dp[N][N][2];

int P(int pos, int goal)
{
    if (a[pos] <= goal) return 0;
    return a[pos]-goal;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n;
    cin >> n;
    ms(dp, INF);

    for (int t1 = 1; t1 <= n; ++t1)
        cin >> a[t1];

    dp[1][0][0] = 0;
    dp[1][1][1] = 0;
    int half = (n>>1) + (n&1);

    for (int t1 = 1; t1 <= n; ++t1)
    {
        for (int t2 = 0; t2 <= half; ++t2)
        {
            for (int t3 = 0; t3 < 2; ++t3)
            {
                int tmp = dp[t1][t2][t3];
                //if (tmp == -INF) continue;

                if (!t3)
                {
                    dp[t1+1][t2+1][1]
                    = min(dp[t1+1][t2+1][1], tmp + P(t1, a[t1+1]-1));

                    dp[t1+1][t2][0]
                    = min(dp[t1+1][t2][0], tmp);
                }
                else
                {
                    dp[t1+2][t2+1][1]
                    = min(dp[t1+2][t2+1][1], tmp + P(t1+1, min(a[t1],a[t1+2])-1));

                    dp[t1+1][t2][0]
                    = min(dp[t1+1][t2][0], tmp + P(t1+1, a[t1]-1));
                }
            }
        }
    }

    for (int t1 = 1; t1 <= half; ++t1)
        cout << min(dp[n][t1][0],dp[n][t1][1]) << ' ';

    cout << '\n';


    return 0;
}
