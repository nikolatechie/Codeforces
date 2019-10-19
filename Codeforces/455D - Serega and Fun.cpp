// Codeforces problem 455D; SQRT Decomposition
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


int n, sz, block;
vector <int> a;
vector <vector <int>> V, freq;

void Build()
{
    block = 0;

    for (int t1 = 0; t1 < n; t1 += sz)
    {
        freq[block].resize(n+1);
        int R = min(t1+sz-1, n-1);

        for (int t2 = t1; t2 <= R; ++t2)
        {
            V[block].push_back(a[t2]);
            ++freq[block][a[t2]];
        }

        ++block;
    }
}

void Rebuild()
{
    vector <int> temp;

    for (int t1 = 0; t1 < sz; ++t1)
    {
        for (int t2 = 0; t2 < V[t1].size(); ++t2)
            temp.push_back(V[t1][t2]);

        freq[t1].clear();
        V[t1].clear();
    }

    for (int t1 = 0; t1 < temp.size(); ++t1)
        a[t1] = temp[t1];

    Build();
}

void Insert(int &i, int &v)
{
    int cnt = 0;

    for (int t1 = 0; t1 < sz; ++t1)
    {
        if (cnt+V[t1].size() > i)
        {
            int pos = i-cnt;
            V[t1].insert(V[t1].begin()+pos,v);
            ++freq[t1][v];
            return;
        }

        cnt += V[t1].size();
    }
}

int Remove(int &i)
{
    int cnt = 0;

    for (int t1 = 0; t1 < sz; ++t1)
    {
        if (cnt+V[t1].size() > i)
        {
            int pos = i-cnt;
            int val = V[t1][pos];
            --freq[t1][val];
            V[t1].erase(V[t1].begin()+pos);
            return val;
        }

        cnt += V[t1].size();
    }

    return 0;
}

void cyclicShift(int &l, int &r)
{
    if (l == r) return;
    int x = Remove(r);
    Insert(l,x);
}

int Query(int i, int &k)
{
    int cnt = 0, ans = 0;

    for (int t1 = 0; t1 < sz; ++t1)
    {
        if (cnt+V[t1].size() > i)
        {
            for (int t2 = 0; t2 <= i-cnt; ++t2)
                if (V[t1][t2] == k) ++ans;

            break;
        }
        else ans += freq[t1][k];

        cnt += V[t1].size();
    }

    return ans;
}

inline int preQuery(int &l, int &r, int &k)
{
    if (!l) return Query(r,k);
    return Query(r,k)-Query(l-1,k);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    sz = ceil(sqrt(n));
    a.resize(n);
    V.resize(sz);
    freq.resize(sz);

    for (int t1 = 0; t1 < n; ++t1)
        cin >> a[t1];

    Build();
    int q, lastAns = 0, optimizeCnt = 0;
    cin >> q;

    while (q)
    {
        --q;
        int op, l, r;
        cin >> op >> l >> r;

        l = ((l + lastAns - 1) % n) + 1;
        r = ((r + lastAns - 1) % n) + 1;
        if (l > r) swap(l,r);
        --l, --r;

        if (op == 1)
            cyclicShift(l,r), ++optimizeCnt;
        else
        {
            int k;
            cin >> k;
            k = ((k + lastAns - 1) % n) + 1;
            lastAns = preQuery(l,r,k);
            cout << lastAns << '\n';
        }

        if (optimizeCnt == 1000) Rebuild(), optimizeCnt = 0;
    }


    return 0;
}
