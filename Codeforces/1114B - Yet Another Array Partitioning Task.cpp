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

    int n, m, k;
    cin >> n >> m >> k;
    vi v(n);
    vector <pii> vp(n); // val, id

    for (int t1 = 0; t1 < n; ++t1)
    {
        cin >> v[t1];
        vp[t1] = {v[t1], t1};
    }

    sort(all(vp));
    llint sum = 0;
    vi idx; // indices of largest elements

    for (int t1 = 1; t1 <= m*k; ++t1)
    {
        sum += vp[n-t1].first; // you can always use m*k largest numbers
        idx.push_back(vp[n-t1].second+1); // add indices of new segments
    }

    sort(all(idx));
    cout << sum << '\n';
    int groups = 0;

    for (int t1 = 0; t1 < idx.size(); ++t1)
    {
        if ((t1+1) % (m) == 0)
        {
            ++groups;
            cout << idx[t1] << ' ';
            if (groups == k-1) break;
        }
    }

    cout << '\n';


    return 0;
}
