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


ci N = (5e5)+5;
int ft[N];

void upd(int i)
{
    for (; i < N; i |= i+1)
        ++ft[i];
}

int sum(int i)
{
    int ans = 0;

    for (; i >= 0; i = (i&(i+1))-1)
        ans += ft[i];

    return ans;
}

int getSum(int l, int r)
{
    if (l > r) return 0;
    return sum(r)-sum(l-1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n, k, d;
    cin >> n >> k >> d;
    vi a(n);

    for (int t1 = 0; t1 < n; ++t1)
        cin >> a[t1];

    sort(all(a));
    vi dp(n+1, 0);
    dp[0] = 1;
    upd(0);
    int l = 0;

    for (int t1 = 0; t1 < n; ++t1)
    {
        while (l < t1 && a[t1]-a[l] > d)
            ++l;

        dp[t1+1] = (getSum(l, t1-k+1) >= 1);
        if (dp[t1+1]) upd(t1+1);
    }

    cout << (dp[n] ? "YES\n":"NO\n");


    return 0;
}
