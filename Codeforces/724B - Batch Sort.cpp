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


int n, m, a[25][25];

void swapColumns(int c1, int c2)
{
    for (int t1 = 1; t1 <= n; ++t1)
        swap(a[t1][c1], a[t1][c2]);
}

bool sorted()
{
    for (int t1 = 1; t1 <= n; ++t1)
    {
        int row = 0;

        for (int t2 = 1; t2 <= m; ++t2)
        {
            if (a[t1][t2] != t2) ++row;
            if (row > 2) return 0;
        }
    }

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> m;
    bool rowSwap = 1;

    for (int t1 = 1; t1 <= n; ++t1)
    {
        int row = 0;

        for (int t2 = 1; t2 <= m; ++t2)
        {
            cin >> a[t1][t2];
            if (a[t1][t2] != t2) ++row;
        }

        if (row > 2) rowSwap = 0;
    }

    if (rowSwap)
    {
        cout << "YES\n";
        return 0;
    }

    // try swapping every pair of columns
    // and see if the matrix will be sorted
    for (int t1 = 1; t1 < m; ++t1)
    {
        for (int t2 = t1+1; t2 <= m; ++t2)
        {
            swapColumns(t1,t2);

            if (sorted())
            {
                cout << "YES\n";
                return 0;
            }

            swapColumns(t1,t2);
        }
    }

    cout << "NO\n";


    return 0;
}
