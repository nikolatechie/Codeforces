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
#define mp make_pair
#define mt make_tuple
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)


int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n;
    cin >> n;
    vi v(n);
    map <llint,int> M;

    for (int t1 = 0; t1 < n; ++t1)
    {
        cin >> v[t1];
        ++M[llint(v[t1])]; // add array elements to map
    }

    if (n == 1)
    {
        cout << 1 << '\n';
        return 0;
    }

    int ans = 0;

    for (int t1 = 0; t1 < n; ++t1)
    {
        bool exists = 0;
        llint a = v[t1];
        llint b = 1; // b is power of 2
        int cnt = 0;
        --M[a];

        while (cnt < 35)
        {
            ++cnt;

            // check if there exists a number b-a because
            // that number and a sum up to power of 2
            if (b >= a && M[abs(b-a)])
            {
                exists = 1;
                break;
            }

            b <<= 1; // multiply b by 2
        }

        ++M[a];
        if (!exists) ++ans;
    }

    cout << ans << '\n';

    return 0;
}
