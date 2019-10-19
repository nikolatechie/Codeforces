// Codeforces problem 86D; Mo's algorithm, SQRT Decomposition
#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

using ld = long double;
using llint = long long;
using ullint = unsigned long long;
using pii = pair <int,int>;
using pcc = pair <char,char>;
using pss = pair <string,string>;
using vi = vector<int>;
using vii = vi::iterator;

#define INF (1<<30)
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define all(c) c.begin(),c.end()
#define ms(name,val) memset(name, val, sizeof name)
#define np nullptr


struct Query
{
    int l, r, i;
};

int n, q, sz;
const int N = 1000001;
int cnt[N];
vector <int> a;
vector <llint> qans;
vector <Query> Q;
llint curPower;

bool cmp(const Query &a, const Query &b)
{
    int a_block = a.l/sz;
    int b_block = b.l/sz;

    if (a_block != b_block) return (a_block < b_block);
    return (a.r < b.r);
}

void Insert(int i)
{
    curPower += (llint(a[i])*(2*cnt[a[i]]+1));
    ++cnt[a[i]];
}

void Remove(int i)
{
    curPower -= (llint(a[i])*(2*cnt[a[i]]-1));
    --cnt[a[i]];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    a.resize(n);
    Q.resize(q);
    qans.resize(q);
    sz = ceil(sqrt(n));

    for (int t1 = 0; t1 < n; ++t1)
        cin >> a[t1];

    for (int t1 = 0; t1 < q; ++t1)
    {
        cin >> Q[t1].l >> Q[t1].r;
        --Q[t1].l, --Q[t1].r;
        Q[t1].i = t1;
    }

    sort(all(Q),cmp);
    int lcur = 0, rcur = 0;

    for (int t1 = 0; t1 < q; ++t1)
    {
        int L = Q[t1].l, R = Q[t1].r;

        while (lcur < L) Remove(lcur), ++lcur;
        while (lcur > L) Insert(lcur-1), --lcur;
        while (rcur <= R) Insert(rcur), ++rcur;
        while (rcur > R+1) Remove(rcur-1), --rcur;

        qans[Q[t1].i] = curPower;
    }

    for (int t1 = 0; t1 < q; ++t1)
        cout << qans[t1] << '\n';



    return 0;
}
