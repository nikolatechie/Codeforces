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
#define np nullptr


ci N = 200005;
pii p[N];
int par[N], sz[N], ans[N];
bool mark[N];

int fs(int x)
{
    return (par[x] == x) ? x:(par[x] = fs(par[x]));
}

void Merge(int a, int b)
{
    a = fs(a), b = fs(b);
    par[a] = b;
    sz[b] += sz[a];
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);


    int n;
    cin >> n;

    for (int t1 = 0; t1 < n; ++t1)
    {
        par[t1] = t1;
        sz[t1] = 1;
        cin >> p[t1].first;
        p[t1].second = t1;
    }

    sort(p, p+n, greater <pii>());
    int cur = 1;

    for (int t1 = 0; t1 < n; ++t1)
    {
        int pos = p[t1].second;
        int val = p[t1].first;
        mark[pos] = true;

        if (pos && mark[pos-1])
            Merge(pos, pos-1);

        if (pos < n-1 && mark[pos+1])
            Merge(pos, pos+1);

        int curSz = sz[fs(pos)];

        while (cur <= curSz)
            ans[cur++] = val;
    }

    for (int t1 = 1; t1 <= n; ++t1)
        cout << ans[t1] << ' ';

    cout << '\n';


    return 0;
}
