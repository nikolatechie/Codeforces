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


int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n, m;
    cin >> n >> m;

    // pigeonhole principle
    if (n > m)
    {
        cout << "YES\n";
        return 0;
    }

    vi DP(m+1, 0), check(m+1, 0);
    DP[0] = 1;

    for (int t1 = 0; t1 < n; ++t1)
    {
        int x;
        cin >> x;
        check.assign(m+1, 0);
        ++DP[x%m];
        ++check[x%m];

        // subsequence consisting of a single element
        if (x == m)
        {
            cout << "YES\n";
            return 0;
        }

        for (int t2 = m; t2 >= 0; --t2)
        {
            // can't use only one number to represent multiple sums
            if (!DP[t2] || (DP[t2] && DP[t2] <= check[t2]))
                continue;

            int i = (t2+x)%m;
            ++DP[i]; // update possible
            ++check[i]; // sequences
        }

        // this is still pigeonhole principle,
        // but combined with DP solution
        if (DP[0] > 1 || DP[m]) break;
    }

    if (DP[0] > 1 || DP[m])
        cout << "YES\n";
    else
        cout << "NO\n";


    return 0;
}
