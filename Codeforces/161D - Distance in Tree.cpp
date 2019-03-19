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


vector <vector <int>> DP, g;
int n, k, ans;

void DFS(int node, int p)
{
    // DP[i][d] - how many nodes are
    // at distance d from node i
    DP[node][0] = 1; // only node

    for (int t1 = 0; t1 < g[node].size(); ++t1)
    {
        int ngb = g[node][t1];
        if (ngb == p) continue;
        // check its unvisited neighbours
        DFS(ngb, node);

        // add new pairs to answer
        for (int d = 1; d <= k; ++d)
            ans += (DP[node][d-1]*DP[ngb][k-d]);

        // add nodes at distance d from ngb
        for (int d = 1; d <= k; ++d)
            DP[node][d] += DP[ngb][d-1];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> k;
    g.resize(n+1);
    DP.resize(n+1, vector <int>(k+1, 0));

    for (int t1 = 0; t1 < n-1; ++t1)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b),
        g[b].push_back(a);
    }

    DFS(1, -1);
    cout << ans << '\n';


    return 0;
}
