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


llint n, a[100005], b[100005];
vector <llint> pf[100005];
bool p[100005]; // checking if current number is prime

// sieve of Eratosthenes
void sieve()
{
    ms(p, 1); // assume all numbers are prime
    ms(b, 1LL);
    p[0] = p[1] = 0; // 0 and 1 are not prime

    for (int t1 = 2; t1 <= 100000; ++t1)
    {
        b[t1] = 1;

        if (p[t1])
        {
            pf[t1].push_back(t1);

            for (int t2 = t1+t1; t2 <= 100000; t2 += t1)
            {
                pf[t2].push_back(t1); // t1 is a prime factor of t2
                p[t2] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    sieve(); // precomputing prime numbers and factors
    cin >> n;

    for (int t1 = 1; t1 <= n; ++t1)
        cin >> a[t1];

    llint ans = 1;

    for (int t1 = 1; t1 <= n; ++t1)
    {
        llint an = 1;

        for (int t2: pf[a[t1]])
            an = max(an, b[t2]); // finding the longest sequence

        ans = max(ans, an);

        for (int t2: pf[a[t1]]) // updating the length of
            b[t2] = max(an+1, b[t2]); // current sequence
    }

    cout << ans << '\n';


    return 0;
}
