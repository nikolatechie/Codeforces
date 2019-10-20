#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

using ld = long double;
using llint = long long;
using ullint = unsigned long long;
using pii = pair <int,int>;
using pcc = pair <char,char>;
using pss = pair <string,string>;
using vi = vector <int>;
using vii = vi::iterator;

#define INF (1<<30)
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define all(c) c.begin(),c.end()
#define ms(name,val) memset(name, val, sizeof name)
#define np nullptr


const int N = 200002;
int parent[N], nxt[N];

int findSet(int x)
{
    return (x == parent[x]) ? x:(parent[x] = findSet(parent[x]));
}

void unionSet(int a, int b)
{
    int x = findSet(a), y = findSet(b);
    parent[x] = parent[y] = min(x,y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int t1 = 1; t1 <= n; ++t1)
        parent[t1] = t1, nxt[t1] = t1+1;

    while (q)
    {
        --q;
        int op, a, b;
        cin >> op >> a >> b;

        if (op == 1)
            unionSet(a, b);
        else if (op == 2)
        {
            for (int t1 = a+1; t1 <= b;)
            {
                unionSet(t1-1, t1);
                int k = nxt[t1];
                nxt[t1] = max(nxt[t1], b+1);
                t1 = k;
            }
        }
        else
        {
            int x = findSet(a), y = findSet(b);
            cout << ((x == y) ? "YES\n":"NO\n");
        }
    }


    return 0;
}
