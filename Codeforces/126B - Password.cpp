#include <bits/stdc++.h>
using namespace std;

using ci = const int;
using ld = long double;
using llint = long long;
using ullint = unsigned long long;
using pii = pair <int,int>;
using pcc = pair <char,char>;
using pss = pair <string,string>;
using vi = vector <int>;
using vb = vector <bool>;
using vii = vi::iterator;

#define INF (1<<30)
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)


int n;
string s;
vi tmp, cnt;

void buildArray()
{
    tmp.resize(n);
    cnt.resize(n+1);
    int i = 0, j = 1;

    while (j < n)
    {
        while (i > 0 && s[i] != s[j])
            i = tmp[i-1];

        if (s[i] == s[j])
        {
            tmp[j] = i+1;
            ++i, ++j;
        }
        else ++j;
    }

    for (int t1 = 0; t1 < n; ++t1)
        ++cnt[tmp[t1]];
}

// modified KMP search
pii Query(int m)
{
    string p = s.substr(0, m);
    int i = 0, j = 0;
    int numOfMatches = 0, indexOfLast = (INF>>1);

    while (i < n)
    {
        while (j > 0 && p[j] != s[i])
            j = tmp[j-1];

        if (s[i] == p[j])
        {
            ++i, ++j;

            if (j == m)
            {
                ++numOfMatches;
                indexOfLast = i-m;
                j = tmp[j-1];
            }
        }
        else ++i;
    }

    return {numOfMatches, indexOfLast};
}

bool allSame()
{
    for (int t1 = 1; t1 < n; ++t1)
        if (s[t1] != s[t1-1]) return 0;

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> s;
    n = s.size();

    if (n < 3)
    {
        cout << "Just a legend\n";
        return 0;
    }

    if (n == 3)
    {
        if (s[0] == s[1] && s[1] == s[2])
            cout << s[0] << '\n';
        else
            cout << "Just a legend\n";

        return 0;
    }

    if (allSame())
    {
        cout << s.substr(2) << '\n';
        return 0;
    }

    buildArray();

    int L = 1, R = n-2, ans = -1;

    // binary searching the longest possible string
    while (L <= R)
    {
        int M = (L+R)>>1;
        pii cur = Query(M);

        if (cur.first < 3)
            R = M-1;
        else
        {
            if (cur.second+M == n)
                ans = max(ans, M), L = M+1;
            else
            {
                pii cur1 = Query(n-cur.second);

                if (cur1.first > 2 && cur1.second+n-cur.second==n)
                {
                    ans = max(ans, n-cur.second);
                    L = n-cur.second+1;
                }
                else
                    R = M-1;
            }
        }
    }

    if (ans == -1)
        cout << "Just a legend\n";
    else
        cout << s.substr(0, ans) << '\n';


    return 0;
}
