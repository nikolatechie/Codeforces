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

    int n, ans = 0;
    cin >> n;
    vi loc(n, 1);
    vector <pii> v(n);

    for (int t1 = 0; t1 < n; ++t1)
        cin >> v[t1].first >> v[t1].second; // (coordinate, height)

    if (n < 3)
    {
        cout << n << '\n';
        return 0;
    }

    sort(all(v));
    
    // loc[i] is:
    // equal to 0 if the tree falls to the left,
    // equal to 1 if it stays in the same place,
    // equal to 2 if it falls right.
    
    loc[0] = 0;
    loc[n-1] = 2;
    ans = 2;

    // greedily find the best answer
    for (int t1 = 1; t1 < n-1; ++t1)
    {
        int prevMax = v[t1-1].first;
        int nxtMax = v[t1+1].first;
        if (loc[t1-1] == 2) prevMax += v[t1-1].second;
        if (loc[t1+1] == 0) nxtMax -= v[t1+1].second;

        if (v[t1].first-v[t1].second > prevMax)
        {
            loc[t1] = 0;
            ++ans;
        }
        else if (v[t1].first+v[t1].second < nxtMax)
        {
            loc[t1] = 2;
            ++ans;
        }
    }

    cout << ans << '\n';


    return 0;
}
