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
using vi = vector<int>;
using vii = vi::iterator;

#define INF (1<<30)
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define all(c) c.begin(),c.end()
#define ms(name,val) memset(name, val, sizeof name)
#define np nullptr


const int N = 1000002;
int st[2][N<<2], A[N], rq[N];

void Update(bool t, int node, int sl, int sr, int i, int v)
{
    if (sl == sr)
    {
        st[t][node] += v;
        return;
    }

    int mid = (sl+sr)>>1, ln = node<<1, rn = ln|1;

    if (i <= mid)
        Update(t, ln, sl, mid, i, v);
    else
        Update(t, rn, mid+1, sr, i, v);

    st[t][node] = st[t][ln] + st[t][rn];
}

llint Query(bool t, int node, int sl, int sr, int l, int r)
{
    if (sl > r || sr < l) return 0;
    if (sl >= l && sr <= r) return st[t][node];

    int mid = (sl+sr)>>1;
    return Query(t,node<<1,sl,mid,l,r) +
        Query(t,(node<<1)|1, mid+1,sr,l,r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n;
    cin >> n;
    vector <pii> val(n);

    for (int t1 = 0; t1 < n; ++t1)
    {
        cin >> A[t1];
        val[t1].first = A[t1];
        val[t1].second = t1;
    }

    sort(all(val));

    for (int t1 = 0; t1 < n; ++t1)
        A[val[t1].second] = t1;

    for (int t1 = n-1; t1 >= 0; --t1)
    {
        rq[t1] = Query(1, 1, 0, n-1, 0, A[t1]);
        Update(1, 1, 0, n-1, A[t1], 1);
    }

    llint ans = 0;

    for (int t1 = 0; t1 < n-1; ++t1)
    {
        ans += (Query(0, 1, 0, n-1, A[t1]+1, n) * llint(rq[t1]));
        Update(0, 1, 0, n-1, A[t1], 1);
    }

    cout << ans << '\n';

    return 0;
}
