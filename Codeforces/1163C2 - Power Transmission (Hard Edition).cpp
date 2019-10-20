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
using pll = pair <llint,llint>;
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


int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n;
    cin >> n;
    vll x(n), y(n);

    for (int t1 = 0; t1 < n; ++t1)
        cin >> x[t1] >> y[t1];

    map <pair <double,double>,llint> used;
    map <llint,llint> usedx, usedy;
    map <double,llint> cntCoeff;
    llint ans = 0, cnt = 0, cntx = 0, cnty = 0;

    for (int t1 = 0; t1 < n; ++t1)
    {
        for (int t2 = t1+1; t2 < n; ++t2)
        {
            if (x[t1] == x[t2])
            {
                if (usedx[x[t1]]) continue;
                usedx[x[t1]] = 1;
                ans += (cnt - cntx);
                ++cntx;
            }
            else if (y[t1] == y[t2])
            {
                if (usedy[y[t1]]) continue;
                usedy[y[t1]] = 1;
                ans += (cnt - cnty);
                ++cnty;
            }
            else
            {
                long double k = (y[t2]-y[t1])/(double)(x[t2]-x[t1]);
                long double n = y[t1]-k*x[t1];
                if (used[{n,k}]) continue;
                used[{n,k}] = 1;
                ans += (cnt-cntCoeff[k]);
                ++cntCoeff[k];
            }

            ++cnt;
        }
    }

    cout << ans << '\n';


    return 0;
}
