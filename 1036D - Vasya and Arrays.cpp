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

    int n, m;
    llint s = 0;
    cin >> n;
    vi a(n);

    for (int t1 = 0; t1 < n; ++t1)
    {
        cin >> a[t1];
        s += a[t1];
    }

    cin >> m;
    vi b(m);

    for (int t1 = 0; t1 < m; ++t1)
    {
        cin >> b[t1];
        s -= b[t1];
    }

    // no answer if sums are different
    if (s)
    {
        cout << "-1\n";
        return 0;
    }

    int t1 = 0, t2 = 0; // pointers for first and second array
    int ans = 0;

    while (t1 < n)
    {
        llint s1 = a[t1], s2 = b[t2];
        ++ans;

	// if sums are different, find the shortest segments
	// with equal sums and replace them by their sums
        while (s1 != s2)
        {
            if (s1 < s2)
                s1 += a[++t1];
            else
                s2 += b[++t2];
        }

        ++t1, ++t2;
    }

    cout << ans << '\n';


    return 0;
}
