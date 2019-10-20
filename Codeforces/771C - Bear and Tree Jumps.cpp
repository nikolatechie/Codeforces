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
int n, k, dp[N][5], totalSubtree[N];
vector <vi> g;
llint ans;

inline int subtract(int a, int b)
{
    return ((a - b) % k + k) % k;
}

void DFS(int x, int p, int lvl)
{
    dp[x][lvl%k] = totalSubtree[x] = 1;

    for (ci &y: g[x])
    {
        if (y != p)
        {
            DFS(y, x, lvl+1);

            for (int t1 = 0; t1 < k; ++t1)
            {
                for (int t2 = 0; t2 < k; ++t2)
                {
                    int remainder = subtract(t1+t2, lvl<<1);
                    int needs = subtract(k, remainder);

                    ans += (llint)needs*dp[x][t1]*dp[y][t2];
                }
            }

            for (int t1 = 0; t1 < k; ++t1)
                dp[x][t1] += dp[y][t1];

            totalSubtree[x] += totalSubtree[y];
        }
    }

    ans += (llint)totalSubtree[x]*(n-totalSubtree[x]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> k;
    g.resize(n+1);

    for (int t1 = 1; t1 < n; ++t1)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    DFS(1, -1, 0);
    cout << ans/k << '\n';


    return 0;
}
