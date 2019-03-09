#include <bits/stdc++.h>
using namespace std;

using ci = const int;
using ld = long double;
using llint = long long;
using ullint = unsigned long long;
using pii = pair <int,int>;
using pcc = pair <char,char>;
using pss = pair <string,string>;
using vi = vector <int>;
using vb = vector <bool>;
using vii = vi::iterator;

#define INF (1<<30)
#define MOD 1000000007
#define mt make_tuple
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)


int n, a, b;
vi p, par, can, where;
map <int,int> m;

// find-set function
int fs(int x)
{
    return (par[x] == x) ? x:(par[x] = fs(par[x])); // path compression
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> a >> b;
    p.resize(n);
    par.resize(n);
    can.resize(n);
    where.assign(n, 3); // bitmask

    for (int t1 = 0; t1 < n; ++t1)
    {
        cin >> p[t1];
        m[p[t1]] = t1;
        par[t1] = t1;
    }

    for (int t1 = 0; t1 < n; ++t1)
    {
        if (m.count(a-p[t1])) par[fs(m[a-p[t1]])] = fs(t1), can[t1] |= 1;
        if (m.count(b-p[t1])) par[fs(m[b-p[t1]])] = fs(t1), can[t1] |= 2;
    }

    for (int t1 = 0; t1 < n; ++t1)
        where[fs(t1)] &= can[t1];

    for (int t1 = 0; t1 < n; ++t1)
    {
        if (where[t1] == 0) // it can't be in either set
        {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    for (int t1 = 0; t1 < n; ++t1)
    {
        int x = where[fs(t1)];
        cout << !(x&1) << ' ';
    }


    return 0;
}
