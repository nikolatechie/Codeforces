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
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)
#define np nullptr


const int N = 100002;
bool used[N];
int n, a[N], p[N], sz[N];
multiset <int> ms;
map <int,int> pos;

int fs(int x)
{
    return (x == p[x]) ? x:(p[x] = fs(p[x]));
}

void us(int a, int b)
{
    int x = fs(a), y = fs(b);
    p[x] = y;
    ms.erase(ms.find(sz[x]));
    ms.erase(ms.find(sz[y]));
    sz[y] += sz[x];
    ms.insert(sz[y]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n, best = 0, ans = 0;
    cin >> n;

    for (int t1 = 1; t1 <= n; ++t1)
        p[t1] = t1, sz[t1] = 1;

    for (int t1 = 1; t1 <= n; ++t1)
    {
        cin >> a[t1];
        pos[a[t1]] = t1;
    }

    sort(a+1, a+n+1);

    for (int t1 = 1; t1 <= n; ++t1)
    {
        int x = a[t1];
        sz[pos[x]] = 1;
        used[pos[x]] = 1;
        ms.insert(1);

        if (pos[x] > 1 && used[pos[x]-1])
            us(pos[x]-1, pos[x]);

        if (pos[x] < n && used[pos[x]+1])
            us(pos[x], pos[x]+1);

        if (*ms.begin() == *ms.rbegin())
        {
            if (ms.size() > best)
            {
                best = ms.size();
                ans = x+1;
            }
        }
    }

    cout << ans << '\n';


    return 0;
}
