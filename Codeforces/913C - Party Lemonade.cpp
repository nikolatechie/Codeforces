#include <bits/stdc++.h>
using namespace std;

using ci = const int;
using llint = long long;
using ullint = unsigned long long;
using pii = pair <int,int>;
using vi = vector <int>;
using vb = vector <bool>;

#define INF (1<<30)
#define MOD 1000000007
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)


int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n, L;
    cin >> n >> L;
    vi c(n);

    for (int t1 = 0; t1 < n; ++t1)
        cin >> c[t1];

    // every bottle can be replaced by 2 bottles
    // of double smaller size if it is cheaper
    for (int t1 = 0; t1 < n-1; ++t1)
        c[t1+1] = min(c[t1+1], 2*c[t1]);

    llint ans = (4e18); // infinite
    llint sum = 0;

    // buy greedily
    for (int t1 = n-1; t1 >= 0; --t1)
    {
        llint need = L/(1<<t1);
        sum += (need*c[t1]);
        L -= (need<<t1);
        ans = min(ans, sum + (L>0)*c[t1]);
    }

    cout << ans << '\n';


    return 0;
}
