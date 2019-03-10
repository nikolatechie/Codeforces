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
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)


int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n;
    cin >> n;
    vi v(n), l(n, 0), r(n, 0);

    for (int t1 = 0; t1 < n; ++t1)
        cin >> v[t1];

    if (n < 3)
    {
        // whole array can be in increasing order
        cout << n << '\n';
        return 0;
    }

    int ans = 2;
    l[0] = r[n-1] = 1; // longest increasing sequences from both sides

    // calculating length from left to right
    for (int t1 = 1; t1 < n; ++t1)
    {
        if (v[t1] > v[t1-1])
            l[t1] = l[t1-1]+1;
        else
            l[t1] = 1;
    }

    // calculating length from right to left
    for (int t1 = n-2; t1 >= 0; --t1)
    {
        if (v[t1] < v[t1+1])
            r[t1] = r[t1+1]+1;
        else
            r[t1] = 1;
    }

    // finding the longest possible sequence
    for (int t1 = 0; t1 < n; ++t1)
    {
        if (!t1)
            ans = max(ans, 1+r[t1+1]);
        else if (t1 == n-1)
            ans = max(ans, 1+l[t1-1]);
        else if (v[t1-1]+1 < v[t1+1])
            ans = max(ans, l[t1-1]+1+r[t1+1]);
        else
            ans = max(ans, 1+max(l[t1-1],r[t1+1]));
    }

    cout << ans << '\n';

    return 0;
}
