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

    int n, m;
    cin >> n >> m;
    vb p(n, 0);

    for (int t1 = 0; t1 < m; ++t1)
    {
        int x, y;
        cin >> x >> y;
        p[x-1] = p[y-1] = 1;
    }

    cout << n-1 << '\n';
    int star = 0;

    for (int t1 = 0; t1 < n; ++t1)
    {
        if (!p[t1])
        {
            star = t1;
            break;
        }
    }

    // create a star-graph
    for (int t1 = 0; t1 < n; ++t1)
    {
        if (t1 != star) cout << t1+1 << ' ' << star+1 << '\n';
    }


    return 0;
}
