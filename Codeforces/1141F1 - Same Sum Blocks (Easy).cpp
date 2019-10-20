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


ci N = 1505;
int a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n;
    cin >> n;
    map <int,vector <pii>> m;

    for (int t1 = 1; t1 <= n; ++t1)
        cin >> a[t1];

    for (int r = 1; r <= n; ++r)
    {
        int sum = 0;

        for (int l = r; l; --l)
        {
            sum += a[l];
            m[sum].push_back({l, r});
        }
    }

    vector <pii> vans;

    for (auto it: m)
    {
        int prev = -INF;
        vector <pii> tmp;

        for (auto jt: it.second)
        {
            if (jt.first > prev)
            {
                tmp.push_back(jt);
                prev = jt.second;
            }
        }

        if (tmp.size() > vans.size())
            vans = tmp;
    }

    cout << vans.size() << '\n';

    for (auto it: vans)
        cout << it.first << ' ' << it.second << '\n';


    return 0;
}
