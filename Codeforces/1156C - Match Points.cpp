#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

using ci = const int;
using ld = long double;
using llint = long long;
using ullint = unsigned long long;
using pii = pair <int,int>;
using pcc = pair <char,char>;
using pss = pair <string,string>;
using vi = vector <int>;
using vb = vector <bool>;
using vll = vector <llint>;
using vii = vi::iterator;

#define INF (1<<30)
#define MOD 1000000007
#define mt make_tuple
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)
#define np nullptr


int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n, z;
    cin >> n >> z;
    vi v(n);

    for (int t1 = 0; t1 < n; ++t1)
        cin >> v[t1];

    sort(all(v));
    int ans = 0, l = 0, r = (n>>1);

    while (l <= r)
    {
        int m = (l+r)>>1;
        bool ok = 1;

        for (int t1 = 0; t1 < m; ++t1)
            ok &= (v[n-m+t1] - v[t1] >= z);

        if (ok)
        {
            ans = max(ans, m);
            l = m+1;
        }
        else r = m-1;
    }

    cout << ans << '\n';


    return 0;
}
