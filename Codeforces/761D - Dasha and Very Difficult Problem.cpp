#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

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


int n, l, r;
vi a, p, b, c;
vector <pii> v; // (value, index in p)

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> l >> r;
    a.resize(n);
    p.resize(n);
    b.resize(n);
    c.resize(n);
    v.resize(n);

    for (int t1 = 0; t1 < n; ++t1)
        cin >> a[t1];

    for (int t1 = 0; t1 < n; ++t1)
    {
        cin >> p[t1];
        v[t1].first = p[t1];
        v[t1].second = t1;
    }

    sort(all(v)); // sorting vector of pairs by value
    bool exist = 1;
    int prev = -INF;

    // going through sorted vector
    for (int t1 = 0; t1 < n; ++t1)
    {
        int L = l, R = r, ans = r+1;
        int i = v[t1].second;

        // binary searching the appropriate value
        while (L <= R)
        {
            int M = (L+R)>>1;

            if (M-a[i] > prev)
            {
                ans = min(ans, M);
                R = M-1;
            }
            else L = M+1;
        }

        if (ans == r+1)
        {
            exist = 0;
            break;
        }

        b[i] = ans;
        prev = ans-a[i];
    }

    if (!exist)
    {
        cout << -1 << '\n'; // no solution
        return 0;
    }

    cout << '\n';
    
    for (int t1 = 0; t1 < n; ++t1)
        cout << b[t1] << ' ';


    return 0;
}
