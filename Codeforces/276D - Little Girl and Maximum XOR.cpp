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


    llint a, b;
    cin >> a >> b;

    if (a == b)
        cout << 0 << '\n';
    else if (a+1 == b)
        cout << (a^b) << '\n';
    else
    {
        llint ans = 0;

        for (llint p = 62; p >= 0; --p)
        {
            llint bit_a = (a>>p)&1LL;
            llint bit_b = (b>>p)&1LL;

            if (bit_a != bit_b)
                ans |= (1LL << p);
            else
            {
                if (bit_a && bit_b) // both bits are 1
                {
                    if ((b ^ (1LL<<p)) >= a)
                        ans |= (1LL << p);
                }
                else if (!bit_a && !bit_b) // both bits are 0
                {
                    if ((a | (1LL<<p)) <= b)
                        ans |= (1LL << p);
                }
            }
        }

        cout << ans << '\n';
    }


    return 0;
}
