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


struct Candy
{
    int type, cnt, fsum;

    bool operator()(const Candy &A, const Candy &B) const
    {
        if (A.cnt != B.cnt) return (A.cnt > B.cnt);
        if (A.fsum != B.fsum) return (A.fsum > B.fsum);
        return 0;
    }
};

map <int,int> cnt, fsum;
multiset <Candy, Candy> S;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    while (q)
    {
        --q;
        int n, ans1 = 0, ans2 = 0;
        cin >> n;
        cnt.clear();
        fsum.clear();
        S.clear();

        for (int t1 = 0; t1 < n; ++t1)
        {
            int type, keep;
            cin >> type >> keep;
            ++cnt[type];
            if (keep) ++fsum[type];
        }

        for (auto it: cnt)
            S.insert(Candy{it.first, it.second, fsum[it.first]});

        int prevUsed = n+1;

        for (int t1 = 0; t1 < n+n+2; ++t1)
        {
            if (S.empty()) break;
            Candy tmp = *S.begin();
            S.erase(S.begin());

            if (tmp.cnt < prevUsed)
            {
                ans1 += tmp.cnt;
                ans2 += min(tmp.cnt, tmp.fsum);
                prevUsed = tmp.cnt;
            }
            else
            {
                if (prevUsed == 1) break;
                tmp.cnt = prevUsed-1;
                S.insert(tmp);
            }
        }

        cout << ans1 << ' ' << ans2 << '\n';
    }

    return 0;
}
