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
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)


int n;
vi v, par;
map <int,int> cur, where;

// find-set function
int fs(int x)
{
    return (par[x] == x) ? x:(par[x] = fs(par[x])); // path compression
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n;
    v.resize(n);
    par.resize(n);

    for (int t1 = 0; t1 < n; ++t1)
    {
        par[t1] = t1;
        cin >> v[t1];
        cur[v[t1]] = t1; // where v[t1] is currently (its index)
    }

    for (const auto &it: cur)
        where[it.first] = where.size()-1; // where this element should be

    for (int t1 = 0; t1 < n; ++t1)
    {
        if (where[v[t1]] != t1)
        {
            int x = fs(t1);
            int y = fs(where[v[t1]]);
            par[y] = x; // union sets
        }
    }

    vector <vi> V(n);

    for (int t1 = 0; t1 < n; ++t1)
        V[fs(t1)].push_back(t1+1); // divide subsequences

    int cnt = 0;

    for (int t1 = 0; t1 < V.size(); ++t1)
        if (!V[t1].empty()) ++cnt;

    cout << cnt << '\n';

    for (int t1 = 0; t1 < V.size(); ++t1)
    {
        if (V[t1].empty()) continue;
        cout << V[t1].size() << ' ';

        // print all possible subsequences
        for (ci &t2: V[t1])
            cout << t2 << ' ';

        cout << '\n';
    }


    return 0;
}
