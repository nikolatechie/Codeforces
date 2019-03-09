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


int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n, k;
    cin >> n >> k;
    vi p(k);
    vector <string> vs(n);
    int dif = INF;

    for (int t1 = 0; t1 < n; ++t1)
        cin >> vs[t1];

    for (int t1 = 0; t1 < k; ++t1)
        p[t1] = t1;

    do // try all permutations and find the answer
    {
        vi num(n);

        for (int t1 = 0; t1 < n; ++t1)
        {
            string tmp = vs[t1];

            for (int t2 = 0; t2 < k; ++t2)
                tmp[t2] = vs[t1][p[t2]];

            num[t1] = atoi(tmp.c_str());
        }

        sort(all(num));

        if (num[n-1]-num[0] < dif)
            dif = num[n-1]-num[0];
    }
    while (next_permutation(all(p)));

    cout << dif << '\n';


    return 0;
}
