// Codeforces problem 219A
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


int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int k;
    string s;
    cin >> k >> s;
    int cnt[26] = {0};

    for (int t1 = 0; t1 < s.size(); ++t1)
        ++cnt[s[t1]-'a'];

    bool can = 1;

    for (int t1 = 0; t1 < 26; ++t1)
    {
        if (cnt[t1] && (cnt[t1] < k || cnt[t1]%k))
        {
            can = 0;
            break;
        }
    }

    if (!can)
    {
        cout << -1 << '\n';
        return 0;
    }

    vi v(26, 0);

    for (int t1 = 0; t1 < 26; ++t1)
        v[t1] = cnt[t1]/k;

    for (int t1 = 0; t1 < k; ++t1)
    {
        for (int t2 = 0; t2 < 26; ++t2)
        {
            for (int t3 = 0; t3 < v[t2]; ++t3)
                cout << char(t2+'a');
        }
    }

    cout << '\n';



    return 0;
}
