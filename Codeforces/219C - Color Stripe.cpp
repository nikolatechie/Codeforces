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
    string s;
    cin >> n >> k >> s;

    // if only 2 characters are allowed, then it has to be an alternating sequence:
    // chose the cheaper one between "ABABA.." and "BABAB.."
    if (k == 2)
    {
        string a = "A", b = "B";
        int changes1 = (s[0] == 'B'), changes2 = (s[0] == 'A');

        for (int t1 = 1; t1 < s.size(); ++t1)
        {
            if (a[t1-1] == 'A') a += 'B'; else a += 'A';
            if (b[t1-1] == 'A') b += 'B'; else b += 'A';

            if (s[t1] != a[t1]) ++changes1;
            if (s[t1] != b[t1]) ++changes2;
        }

        if (changes1 <= changes2)
            cout << changes1 << '\n' << a << '\n';
        else
            cout << changes2 << '\n' << b << '\n';

        return 0;
    }

    int ans = 0;

    // if there are more allowed colors, you can only transform
    // to characters 'A', 'B' and 'C' when needed to make it easier
    for (int t1 = 1; t1 < n; ++t1)
    {
        if (s[t1] == s[t1-1]) // current character should be changed
        {
            for (char ch = 'A'; ch <= 'C'; ++ch)
            {                
                if (ch != s[t1]) // found character different than current and previous one
                {
                    if (t1 == n-1) // simply change it
                    {
                        ++ans;
                        s[t1] = ch;
                        break;
                    }
                    else // current character is not on the edge
                    {
                        if (s[t1] == s[t1+1]) // changing the middle of three same consecutive letters is cheapest
                        {
                            ++ans;
                            s[t1] = ch;
                            break;
                        }
                        else if (ch != s[t1+1]) // replacement is different from three letters
                        {
                            ++ans;
                            s[t1] = ch;
                            break;
                        }
                    }
                }
            }

            ++t1; // after replacing, go 2 steps to the right (one is done by the for loop)
        }
    }

    cout << ans << '\n' << s << '\n'; // number of changes, and the resulting sequence


    return 0;
}
