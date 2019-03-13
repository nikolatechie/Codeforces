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


ci N = (2e5) + 5;
int n, a[N];
map <int,int> DP;

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n;

    for (int t1 = 1; t1 <= n; ++t1)
        cin >> a[t1];

    int len = 1, endIdx = 1, endVal = a[1];

    for (int t1 = 1; t1 <= n; ++t1)
    {
        DP[a[t1]] = DP[a[t1]-1] + 1;

        // updating values for the longest increasing subsequence
        if (DP[a[t1]] > len)
        {
            len = DP[a[t1]];
            endIdx = t1;
            endVal = a[t1];
        }
    }

    cout << len << '\n';
    vi ans = {endIdx};
    --endVal;

    for (int t1 = endIdx-1; t1; --t1)
    {
        // finding indices of sequence elements
        if (a[t1] == endVal)
        {
            ans.push_back(t1);
            --endVal;
        }
    }

    // printing them in increasing order
    for (int t1 = len-1; t1 >= 0; --t1)
        cout << ans[t1] << ' ';

    cout << '\n';


    return 0;
}
