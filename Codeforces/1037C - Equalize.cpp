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
#define mt make_tuple
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)


int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n, ans = 0;
    string a, b;
    cin >> n >> a >> b;

    for (int t1 = 0; t1 < n; ++t1)
    {
        if (a[t1] == b[t1]) continue;

        if (t1 < n-1) // can perform both operations
        {
            if (a[t1] == b[t1+1] && a[t1+1] == b[t1])
                swap(a[t1], a[t1+1]);
            else
                a[t1] = b[t1];
        }
        else // only flip
            a[t1] = b[t1];

        ++ans;
    }

    cout << ans << '\n';


    return 0;
}
