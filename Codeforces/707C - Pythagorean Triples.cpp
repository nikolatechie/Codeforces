#include <bits/stdc++.h>
using namespace std;

using llint = long long;


int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

    llint n;
    cin >> n;

    if (n < 3)
        cout << -1 << '\n'; // no integer triplet exists
    else if (n % 2 == 0)
        cout << (n*n/4-1) << ' ' << (n*n/4+1) << '\n';
    else
        cout << (n*n)/2 << ' ' << (n*n/2)+1 << '\n';


    return 0;
}
