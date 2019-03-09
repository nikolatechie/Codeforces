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
#define mt make_tuple
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)


int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n;
    cin >> n;
    map <llint,int> cnt;
    llint ans = 0;

    for (int t1 = 0; t1 < n; ++t1)
    {
        llint mask = 0; // bitmask for every string
        string s;
        cin >> s;

        for (char c: s)
            mask ^= (1LL<<(c-'a')); // put 1 if character's frequency is odd, else it's 0

        ans += cnt[mask];

        for (int t2 = 0; t2 < 63; ++t2)
        {
            llint tmp = mask^(1LL<<t2);
            ans += cnt[tmp];
        }

        ++cnt[mask];
    }

    cout << ans << '\n';


    return 0;
}
