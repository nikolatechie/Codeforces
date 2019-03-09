#include <bits/stdc++.h>
using namespace std;

using ci = const int;
using ld = long double;
using llint = long long;
using ullint = unsigned long long;
using pii = pair <int,int>;
using vi = vector <int>;
using vb = vector <bool>;
using vii = vi::iterator;

#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)
#define np nullptr


ci N = 100005;
string s[N];
llint DP[N][2], c[N];

string rev(string str)
{
    reverse(all(str));
    return str;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n;
    cin >> n;

    for (int t1 = 1; t1 <= n; ++t1)
        cin >> c[t1];

    for (int t1 = 1; t1 <= n; ++t1)
        cin >> s[t1];

    const llint inf = 1e16;
    // DP[i][j] - min amount of energy to sort first i strings
    // if j == 1, the string is reversed, else it stays as it was

    for (int t1 = 1; t1 <= n; ++t1)
    {
        DP[t1][1] = DP[t1][0] = inf;

        if (s[t1] >= s[t1-1])
            DP[t1][0] = DP[t1-1][0];

        if (s[t1] >= rev(s[t1-1]))
            DP[t1][0] = min(DP[t1][0], DP[t1-1][1]);

        if (rev(s[t1]) >= s[t1-1])
            DP[t1][1] = c[t1] + DP[t1-1][0];

        if (rev(s[t1]) >= rev(s[t1-1]))
            DP[t1][1] = min(DP[t1][1], c[t1]+DP[t1-1][1]);
    }

    llint ans = min(DP[n][0], DP[n][1]);

    if (ans >= inf)
        cout << "-1\n";
    else
        cout << ans << '\n';


    return 0;
}
