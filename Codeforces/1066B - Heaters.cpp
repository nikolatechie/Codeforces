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

    int n, r;
    cin >> n >> r;
    vi h(n);
    vb used(n, 0);

    for (int t1 = 0; t1 < n; ++t1)
        cin >> h[t1];

    // for every position, find the
    // furthest heater that can warm it
    for (int t1 = 0; t1 < n; ++t1)
    {
        int heater = -1;

        for (int t2 = min(n-1, t1+r-1); t2 >= max(0, t1-r+1); --t2)
        {
            if (h[t2])
            {
                used[t2] = 1;
                heater = t2;
                break;
            }
        }

        // if there is no available heater, answer is -1
        if (heater == -1)
        {
            cout << "-1\n";
            return 0;
        }

        t1 = heater+r-1;
    }

    h.assign(n, 0);
    int ans = 0;

    for (int t1 = 0; t1 < n; ++t1)
    {
        if (used[t1]) // used heater
        {
            ++ans;

            for (int t2 = min(n-1, t1+r-1); t2 >= max(0, t1-r+1); --t2)
                h[t2] = 1; // mark positions warmed by current heater
        }
    }

    for (int t1 = 0; t1 < n; ++t1)
    {
        if (!h[t1]) // if there is a positions which is not warmed, answer is -1
        {
            cout << "-1\n";
            return 0;
        }
    }

    cout << ans << '\n';


    return 0;
}
