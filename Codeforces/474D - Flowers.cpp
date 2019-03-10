#include <bits/stdc++.h>
using namespace std;

using ci = const int;
using ld = long double;
using llint = long long;
using pii = pair <int,int>;
using vi = vector <int>;
using vb = vector <bool>;
using vii = vi::iterator;

#define INF (1<<30)
#define MOD 1000000007
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)


ci MX = (1e5)+5;
llint DP[MX];

void precompute(ci &k)
{
    // he can only eat red flowers of length i
    for (int i = 0; i < k; ++i)
        DP[i] = 1;

    // combining both red and white flowers
    for (int i = k; i < MX; ++i)
        DP[i] = (DP[i-1] + DP[i-k]) % MOD;

    // calculating prefix sum to answer queries in O(1)
    for (int i = 1; i < MX; ++i)
        DP[i] = (DP[i] + DP[i-1]) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TC, k;
    cin >> TC >> k;
    precompute(k);

    while (TC)
    {
        --TC;
        int a, b;
        cin >> a >> b;
        cout << (DP[b] - DP[a-1] + MOD) % MOD << '\n';
    }

    return 0;
}
