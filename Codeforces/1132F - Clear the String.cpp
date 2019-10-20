#include <bits/stdc++.h>
#include <ext/rope>
#define state -123456789LL
#define lft (ln+rn)/2
#define rgt (ln+rn)/2+1
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


ci N = 505;
string s;
int n, dp[N][N];

int solve(int l, int r)
{
    int &res = dp[l][r];
    if (res != -1) return res;

    if (l > r) return (res = 0);
    if (l == r) return (res = 1);

    res = 1 + solve(l+1, r);

    for (int i = l+1; i <= r; ++i)
    {
        if (s[l] == s[i])
            res = min(res, solve(l+1, i-1) + solve(i, r));
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> s;
    ms(dp, -1);
    cout << solve(0, n-1) << '\n';


    return 0;
}
