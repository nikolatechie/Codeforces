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

    string s;
    cin >> s;
    int n = s.size();
    char lexSmallest = s[0];
    bool passed[26] = {0};

    for (int t1 = 1; t1 < n; ++t1)
        lexSmallest = min(lexSmallest, s[t1]);

    for (int t1 = 0; t1 < n; ++t1)
    {
        if (lexSmallest == s[t1])
        {
            cout << "Mike\n";
            passed[s[t1]-'a'] = 1;
            continue;
        }

        bool done = 0;

        for (int t2 = 0; t2 < s[t1]-'a'; ++t2)
        {
            if (passed[t2])
            {
                cout << "Ann\n";
                done = 1;
                break;
            }
        }

        passed[s[t1]-'a'] = 1;
        if (!done) cout << "Mike\n";
    }



    return 0;
}
