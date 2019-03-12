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

    int n;
    cin >> n;
    vector <pii> v(n);
    llint w = 0;
    multiset <llint> h; // for storing all heights

    for (int t1 = 0; t1 < n; ++t1)
    {
        cin >> v[t1].first >> v[t1].second;
        w += v[t1].first; // sum all widths together
        h.insert(v[t1].second); // insert all heights into multiset
    }

    for (int t1 = 0; t1 < n; ++t1)
    {
        w -= v[t1].first; // exclude current width
        h.erase(h.find(v[t1].second)); // and height
        cout << w*(*h.rbegin()) << ' '; // answer is totalWidth*largestHeight
        w += v[t1].first; // include current width
        h.insert(v[t1].second); // and height again
    }

    return 0;
}
