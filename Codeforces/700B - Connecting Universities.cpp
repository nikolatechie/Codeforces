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
#define mt make_tuple
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)
#define np nullptr


int n, k;
llint ans;
vector <llint> s;
vector <vi> g;

void DFS(int x, int p)
{
    for (ci &y: g[x])
    {
        if (y != p)
        {
            DFS(y, x);
            s[x] += s[y];
        }
    }

    ans += min(s[x], (k<<1)-s[x]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> k;
    s.resize(n+1);
    g.resize(n+1);

    for (int t1 = 0; t1 < (k<<1); ++t1)
    {
        int x;
        cin >> x;
        ++s[x];
    }

    for (int t1 = 1; t1 < n; ++t1)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    DFS(1, 0);
    cout << ans << '\n';


    return 0;
}
