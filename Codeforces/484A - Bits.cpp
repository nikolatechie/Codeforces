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


// finds highest power of two which is les than or equal to r
llint highestPower(llint r)
{
    llint p = 1;
    while ((p<<1) <= r) p <<= 1;
    return p;
}

llint f(llint l, llint r)
{
    if (l == r) return l; // only one possible number
    llint p = highestPower(r);

    if (p <= l) // put bit 1 as the most significant digit and try
        return p + f(l-p, r-p); // finding the answer for other digits

    if ((p<<1)-1 <= r) // every number which is one less than some
        return (p<<1)-1; // power of 2 has the most bits 1

    return p-1; // it belongs to numbers [l, r] and is one less than power of 2
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    int q;
    cin >> q;

    while (q)
    {
        --q;
        llint l, r;
        cin >> l >> r;
        cout << f(l, r) << '\n';
    }

    return 0;
}
