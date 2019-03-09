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


int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);


    string s;
    int k;
    cin >> s >> k;

    for (int t1 = 0; t1 < s.size(); ++t1)
    {
        int nxtGreater = t1;

        // find the next greater number
        for (int t2 = t1+1; t2 < s.size(); ++t2)
        {
            if (t2-t1 > k) break;
            if (s[t2] > s[nxtGreater]) nxtGreater = t2;
        }

        if (nxtGreater == t1) continue; // there is none
        k -= (nxtGreater-t1);

        // do series of swaps
        for (int t2 = nxtGreater-1; t2 >= t1; --t2)
            swap(s[t2], s[t2+1]);
    }

    cout << s << '\n';



    return 0;
}
