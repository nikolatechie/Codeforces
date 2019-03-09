#include <bits/stdc++.h>
using namespace std;

using ci = const int;
using llint = long long;
using pii = pair <int,int>;
using vi = vector <int>;

#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)


int n;
vector <pii> v;
#define fi first
#define se second

// sort them by finish time in ascending order
bool cmp(pii &A, pii &B)
{
    return (A.second < B.second);
    if (A.se == B.se) return (A.fi < B.fi);
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n;
    v.resize(n);

    for (int t1 = 0; t1 < n; ++t1)
        cin >> v[t1].fi >> v[t1].se;

    sort(all(v), cmp);
    int prev = v[0].fi-1;
    int ans = 0;

    for (int t1 = 0; t1 < n; ++t1)
    {
        // accept new order only if its starting time
        // is after the finish time of previous order
        if (v[t1].fi > prev)
        {
            ++ans;
            prev = v[t1].se;
        }
    }

    cout << ans << '\n';


    return 0;
}
