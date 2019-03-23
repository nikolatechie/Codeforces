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
#define mt make_tuple
#define all(c) c.begin(), c.end()
#define ms(name,val) memset(name, val, sizeof name)


int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int n, m;
    cin >> n >> m;
    vi r(n), c(m);
    int xr = 0, xc = 0;

    for (int t1 = 0; t1 < n; ++t1)
    {
        cin >> r[t1];
        xr ^= r[t1];
    }

    for (int t1 = 0; t1 < m; ++t1)
    {
        cin >> c[t1];
        xc ^= c[t1];
    }

    if (xr != xc)
    {
        cout << "NO\n"; // no solution because XOR of all columns
        return 0; // should be equal to XOR of all rows
    }

    cout << "YES\n";

    for (int t1 = 0; t1 < n; ++t1)
    {
        for (int t2 = 0; t2 < m; ++t2)
        {
            if (!t1 && !t2)
                cout << (r[t1]^xc^c[t2]) << ' '; // first element in first row
            else if (!t1)
                cout << c[t2] << ' '; // other elements in first row
            else if (t1 && !t2)
                cout << r[t1] << ' '; // first element in other rows
            else
                cout << 0 << ' '; // all other elements
        }

        cout << '\n';
    }
    
    /*
        PROOF and EXPLANATION: Let's use an example of 2 rows and 3 columns. XOR of rows is r = {2, 9},
        and XOR of columns is c = {5, 3, 13}.
        First element in first row would be 2^3^13 -> (r[0]^c[1]*c[2]).
        Second element in first row would have value 3 (c[1]), and third 13 (c[2]). XOR of values
        from that row would be (2^3^13)^(3)^(13), which is equal to 2 (r[0]). So that's correct.
        First element in second column would be 9 (r[1]), and other elements in second column
        would be 0. That means XOR of first column is (2^3^13)^(9), which is equal to 5 (c[0]).
        So that's also correct and that was the hardest part. Now, for all other values
        of column's XOR and row's XOR, there is only at most one non-zero element. That
        means that XOR of those values is equal to exactly that element. So for second
        column, (3)^(0) would be 3, and for third (13)^(0) is 13, so that's the complete solution.
    */


    return 0;
}
