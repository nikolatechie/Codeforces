#include <bits/stdc++.h>
using namespace std;

using ci = const int;
using ld = long double;
using llint = long long;
using ullint = unsigned long long;
using pii = pair <int,int>;
using vi = vector <int>;
using vb = vector <bool>;
using vii = vi::iterator;

#define INF (1<<30)
#define MOD 1000000007
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)


int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n;
    cin >> n;
    vector <vi> DP(3, vi(n+1,0));
    // row 0 - do nothing
    // row 1 - do sports
    // row 2 - do programming

    for (int p = 1; p <= n; ++p)
    {
        int a;
        cin >> a;

        DP[0][p] = 1 + min(DP[0][p-1], min(DP[1][p-1], DP[2][p-1]));
        DP[1][p] = (a == 0 || a == 1) ? INF: min(DP[0][p-1], DP[2][p-1]);
        DP[2][p] = (a == 0 || a == 2) ? INF: min(DP[0][p-1], DP[1][p-1]);
    }

    cout << min({DP[0][n], DP[1][n], DP[2][n]}) << '\n';


    return 0;
}
