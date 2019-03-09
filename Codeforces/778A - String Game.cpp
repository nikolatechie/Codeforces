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

#define INF (1<<30)
#define MOD 1000000007
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)



ci N = 200005;
int n, m;
string a, b;
int p[N];

bool can(int M)
{
    vb del(n+1, 0);
    int t2 = 1;

    for (int t1 = 1; t1 <= M; ++t1)
        del[p[t1]] = 1; // mark deleted characters

    for (int t1 = 1; t1 <= n; ++t1)
    {
        if (t2 > m) break;
        if (!del[t1] && a[t1] == b[t2]) ++t2;
    }

    if (t2 > m) return 1; // the word can be obtained
    return 0; // the word can't be obtained
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> a >> b;
    n = a.size(), m = b.size();
    a = '$' + a, b = '$' + b; // make them 1-indexed

    for (int t1 = 1; t1 <= n; ++t1)
        cin >> p[t1];

    int L = 0, R = n, ans = 0;

    // binary search the answer
    while (L <= R)
    {
        int M = (L+R)>>1;

        if (can(M))
        {
            ans = max(ans, M);
            L = M+1;
        }
        else R = M-1;
    }

    cout << ans << '\n';


    return 0;
}
