// Solution for 100 points using binary search and prefix sums - O(n log n)
// You can test the solution on PEG online judge - https://wcipeg.com/problem/ioi1113
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


ci N = (1e5)+5;
int n, ans = 1;
ll limit, budget, x[N], sum[N];

ll sum_query(int i)
{
    return (i < 0 || i > n) ? 0LL:sum[i];
}

ll sum_query(int L, int R)
{
    return sum_query(R)-sum_query(L-1);
}

ll query(ll L, ll R)
{
    ll M = (L+R)>>1LL;
    return (M-L)*x[M] - sum_query(L, M-1LL) - (R-M)*x[M] + sum_query(M+1LL, R);
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> limit >> budget;

    for (int t1 = 1; t1 <= n; ++t1)
    {
        cin >> x[t1];
        sum[t1] = sum[t1-1] + x[t1]; // calculate prefix sums
    }

    for (int L = 1; L <= n; ++L) // left-end point of every interval
    {
        int l = 1, r = n-L+1, len = -1;

        // find the length of longest subarray such that
        // the total cost is less than or equal to budget
        while (l <= r)
        {
            int m = (l+r)>>1;

            if (query(L, L+m-1) > budget)
                r = m-1;
            else
            {
                len = max(len, m);
                l = m+1;
            }
        }

        ans = max(ans, len);
    }

    cout << ans << '\n';



    return 0;
}
