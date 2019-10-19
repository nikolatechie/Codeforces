#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

using ci = const int;
using ld = long double;
using ll = long long;
using ull = unsigned long long;
using pii = pair <int,int>;
using pcc = pair <char,char>;
using pll = pair <ll,ll>;
using pss = pair <string,string>;
using vi = vector <int>;
using vb = vector <bool>;
using vpii = vector <pii>;
using vll = vector <ll>;
using vii = vi::iterator;

#define INF (0x3f3f3f3f)
#define MOD 1000000007
#define mt make_tuple
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof (name))
#define np nullptr


int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int q;
    cin >> q;

    while (q)
    {
        --q;
        int n;
        cin >> n;
        vi v(n);

        for (int t1 = 0; t1 < n; ++t1)
            cin >> v[t1];

        sort(all(v));
        n = unique(all(v)) - v.begin();
        int ans = v[n-1];

        for (int t1 = n-1; t1 >= 0; --t1)
        {
            for (int t2 = t1-1; t2 >= 0; --t2)
            {
                if (v[t1] % v[t2] == 0) continue;
                ans = max(ans, v[t1] + v[t2]);
                if (t2 && v[t1]+v[t2]+v[t2-1] <= ans) break;

                for (int t3 = t2-1; t3 >= 0; --t3)
                {
                    if (v[t1]+v[t2]+v[t3] <= ans) break;

                    if (v[t1]%v[t3] && v[t2]%v[t3])
                        ans = max(ans, v[t1]+v[t2]+v[t3]);
                }
            }
        }

        cout << ans << '\n';
    }


    return 0;
}
