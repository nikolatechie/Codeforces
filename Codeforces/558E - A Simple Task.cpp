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


string s;
const int N = 100005;
int st[N<<2][26], lazy[N<<2][26];
#define ln node<<1
#define rn ln|1
#define mid ((sl+sr)>>1)

void Build(int node, int sl, int sr)
{
    if (sl == sr)
    {
        st[node][s[sl]-'a'] = 1;
        return;
    }

    Build(ln, sl, mid);
    Build(rn, mid+1, sr);

    for (int ch = 0; ch < 26; ++ch)
        st[node][ch] = st[ln][ch] + st[rn][ch];
}

void pd(int &node, int &ch, int &sl, int &sr)
{
    if (lazy[node][ch] != -1)
    {
        if (sl != sr)
            lazy[ln][ch] = lazy[rn][ch] = lazy[node][ch];

        st[node][ch] = lazy[node][ch] * (sr-sl+1);
        lazy[node][ch] = -1;
    }
}

void Update(int node, int sl, int sr, int l, int r, int &ch, int v)
{
    pd(node, ch, sl, sr);
    if (sl > r || sr < l) return;

    if (sl >= l && sr <= r)
    {
        lazy[node][ch] = v;
        pd(node, ch, sl, sr);
        return;
    }

    Update(ln, sl, mid, l, r, ch, v);
    Update(rn, mid+1, sr, l, r, ch, v);
    st[node][ch] = st[ln][ch] + st[rn][ch];
}

int Query(int node, int sl, int sr, int &l, int &r, int &ch)
{
    pd(node, ch, sl, sr);
    if (sl > r || sr < l) return 0;
    if (sl >= l && sr <= r) return st[node][ch];

    return Query(ln, sl, mid, l, r, ch) +
        Query(rn, mid+1, sr, l, r, ch);
}

void Get(int node, int sl, int sr, int &ch)
{
    pd(node, ch, sl, sr);
    if (!st[node][ch]) return;

    if (sl == sr)
    {
        s[sl] = ch + 'a';
        return;
    }

    Get(ln, sl, mid, ch);
    Get(rn, mid+1, sr, ch);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q, cnt[26];
    cin >> n >> q >> s;
    s = " " + s; // 1-indexed
    ms(lazy, -1);
    Build(1, 1, n);

    while (q)
    {
        --q;
        bool k;
        int l, r;
        cin >> l >> r >> k;

        for (int ch = 0; ch < 26; ++ch)
            cnt[ch] = Query(1, 1, n, l, r, ch);

        int i = (k) ? l:r;

        for (int t1 = 0; t1 < 26; ++t1)
        {
            if (!cnt[t1]) continue;
            Update(1, 1, n, l, r, t1, 0);

            if (k) // non-decreasing
            {
                Update(1, 1, n, i, i+cnt[t1]-1, t1, 1);
                i += cnt[t1];
            }
            else // non-increasing
            {
                Update(1, 1, n, i-cnt[t1]+1, i, t1, 1);
                i -= cnt[t1];
            }
        }
    }

    for (int t1 = 0; t1 < 26; ++t1)
        Get(1, 1, n, t1);

    s.erase(s.begin());
    cout << s << '\n';


    return 0;
}
