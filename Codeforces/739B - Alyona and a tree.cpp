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


struct Node
{
    int contain, ans, counter;
    vpii children;
};

ci N = (2e5)+5;
Node node[N];
vi path;
vll s;

void solution(int now)
{
    ++node[path.back()].ans;
    path.push_back(now);

    for (pii i: node[now].children)
    {
        s.push_back(s.back()+i.second);
        solution(i.first);
        node[now].ans += node[i.first].ans;
        s.pop_back();
    }

    ++node[path[lower_bound(all(s), s.back()-node[now].contain)-s.begin()]].counter;
    node[now].ans -= node[now].counter;
    path.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n;
    cin >> n;

    for (int t1 = 1; t1 <= n; ++t1)
        cin >> node[t1].contain;

    for (int t1 = 2; t1 <= n; ++t1)
    {
        int p, w;
        cin >> p >> w;
        node[p].children.push_back({t1,w});
    }

    path.push_back(0);
    s.push_back(0);
    solution(1);

    for (int t1 = 1; t1 <= n; ++t1)
        cout << node[t1].ans << ' ';

    cout << '\n';


    return 0;
}
