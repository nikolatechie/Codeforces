#include <bits/stdc++.h>
using namespace std;

using ci = const int;
using llint = long long;
using pii = pair <int,int>;
using vi = vector <int>;
using vb = vector <bool>;

#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)


int n, x, y;// x - Flowrisa, y - Beetopia
llint pairs;
vi sz, p;
vector <vi> g;

void DFS(int node)
{
    sz[node] = 1;

    for (ci &ngb: g[node])
    {
        if (ngb != p[node])
        {
            p[ngb] = node;
            DFS(ngb);
            sz[node] += sz[ngb]; // compute subtree size for each node
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> x >> y;
    pairs = n;
    pairs *= (pairs-1); // set its value to number of all pairs, and later subtract number of prohibited paths
    g.resize(n+1);
    sz.resize(n+1);
    p.resize(n+1);

    for (int t1 = 1; t1 < n; ++t1)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    DFS(y); // consider Beetopia (node y) as root
    llint flowrisaSize = sz[x];
    llint beetopiaSize = sz[y];
    while (p[x] != y) x = p[x]; // LCA of x and y will be y, so go up until it's parent of x
    beetopiaSize -= sz[x]; // don't consider paths which don't cross Beetopia

    cout << pairs-(flowrisaSize*beetopiaSize) << '\n';// this is the final answer


    return 0;
}
