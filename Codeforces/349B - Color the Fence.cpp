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
#define mt make_tuple
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)

// comparator function for sorting
bool cmp(const pii &A, const pii &B)
{
    if (A.first < B.first) return 1;
    if (A.first == B.first) return (A.second > B.second);
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int v;
    vi c(10, INF); // costs of colors
    vector <pii> a(10); // (paint, digit)
    a[0].first = INF, a[0].second = 0;
    cin >> v;

    for (int t1 = 1; t1 <= 9; ++t1)
    {
        cin >> a[t1].first;
        c[t1] = a[t1].first;
        a[t1].second = t1;
    }

    sort(all(a), cmp); // sorting colors by their cost

    if (v < a[0].first)
    {
        cout << -1 << '\n';
        return 0;
    }

    int n = v/a[0].first;
    int cost = n*a[0].first;
    string s(n, a[0].second+'0');

    for (int t1 = 0; t1 < n; ++t1)
    {
        for (int digit = 9; digit > 1; --digit) // trying all possible numbers
        {
            if (cost-a[0].first+c[digit] <= v)
            {
                s[t1] = digit+'0';
                cost = cost-a[0].first+c[digit];
                break;
            }
        }
    }

    cout << s << '\n';


    return 0;
}
