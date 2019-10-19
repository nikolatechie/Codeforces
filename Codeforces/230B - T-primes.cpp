// Codeforces problem 230B
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
using vpii = vector <pii>;
using vll = vector <ll>;
using vii = vi::iterator;

#define INF (0x3f3f3f3f)
#define MOD 1000000007
#define mt make_tuple
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof (name))
#define np nullptr


int n;
ll m[1005][1005];
vll a;

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n;
    a.resize(n+1);

    for (int t1 = 1; t1 <= n; ++t1)
    {
        for (int t2 = 1; t2 <= n; ++t2)
            cin >> m[t1][t2];
    }

    ll a3 = sqrt((m[1][3]*m[2][3])/m[1][2]);
    ll a2 = m[2][3]/a3;
    ll a1 = m[1][2]/a2;
    a[1] = a1, a[2] = a2, a[3] = a3;

    for (int t1 = 4; t1 <= n; ++t1)
        a[t1] = m[1][t1]/a1;

    for (int t1 = 1; t1 <= n; ++t1)
        cout << a[t1] << ' ';

    cout << '\n';


    return 0;
}
