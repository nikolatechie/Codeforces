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


ci N = (1e5)+5;
int n, ans, a[N];

struct ST
{
    int n, st[20][N];

    void init(int n)
    {
        this->n = n;

        for (int t1 = 1; t1 <= n; ++t1)
            st[0][t1] = a[t1];

        for (int t2 = 1; t2 < 20; ++t2)
        {
            for (int t1 = 1; t1 <= n && t1+(1<<t2)-1 <= n; ++t1)
            {
                st[t2][t1] = __gcd(st[t2-1][t1],
                            st[t2-1][t1+(1<<(t2-1))]);
            }
        }
    }

    int query(int l, int r)
    {
        int k = log2(r-l+1);
        return __gcd(st[k][l], st[k][r-(1<<k)+1]);
    }
} st;

int b_search(int t1, int l, int x)
{
    int r = n, ans = -1;

    while (l <= r)
    {
        int m = (l+r)>>1;

        if (st.query(t1, m) >= x)
        {
            ans = m;
            l = m+1;
        }
        else r = m-1;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n;

    for (int t1 = 1; t1 <= n; ++t1)
        cin >> a[t1];

    st.init(n);
    map <int,ll> M;

    for (int t1 = 1; t1 <= n; ++t1)
    {
        int x = a[t1], l = t1;

        while (1)
        {
            int r = b_search(t1, l, x);
            M[x] += (r-l+1);
            x = st.query(t1, r+1);
            l = r+1;
            if (r >= n) break;
        }
    }

    int q;
    cin >> q;

    while (q)
    {
        --q;
        int x;
        cin >> x;
        cout << M[x] << '\n';
    }

    return 0;
}
