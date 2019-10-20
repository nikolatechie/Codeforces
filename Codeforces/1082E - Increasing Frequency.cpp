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


int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n, k, mx = 0, base = 0;
    cin >> n >> k;
    vi dp((5e5)+5, 0);

    for (int t1 = 0; t1 < n; ++t1)
    {
        int a;
        cin >> a;

        if (a == k)
            ++base;
        else
            dp[a] = max(dp[a], base) + 1;

        mx = max(mx, dp[a]-base);
    }

    cout << base+mx << '\n';


    return 0;
}
