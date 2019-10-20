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
using vll = vector <ll>;
using vii = vi::iterator;

#define INF (0x3f3f3f3f)
#define MOD 1000000007
#define mt make_tuple
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof (name))
#define np nullptr


ci N = (1e6)+5;
vector <vi> pos(N);
int n, x, a[N], prefMax[N];

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> x;

    for (int t1 = 0; t1 < n; ++t1)
    {
        cin >> a[t1];
        pos[a[t1]].push_back(t1);
        prefMax[t1] = max(a[t1], (t1 > 0 ? prefMax[t1-1]:a[t1]));
    }

    int p = 1, lst = n+5;

    for (int t1 = x; t1 >= 1; --t1)
    {
        if (pos[t1].empty())
        {
            p = t1;
            continue;
        }

        if (pos[t1].back() > lst)
            break;

        p = t1;
        lst = pos[t1][0];
    }

    ll res = 0;
    lst = -1;

    for (int l = 1; l <= x; ++l)
    {
        int r = max(l, p-1);
        if (lst != -1) r = max(r, prefMax[lst]);
        res += (x-r+1);

        if (!pos[l].empty())
        {
            if (pos[l][0] < lst) break;
            lst = pos[l].back();
        }
    }

    cout << res << '\n';


    return 0;
}
