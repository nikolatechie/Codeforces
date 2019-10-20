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


const int N = 100005;
int A[N];

int GCD(int a, int b)
{
    while (b) swap(a,b), b %= a;
    return a;
}

struct Node
{
    int gcd, cnt;

    Node()
    {
        gcd = cnt = 0;
    }

    Node(int v)
    {
        gcd = v;
        cnt = 1;
    }

    void Merge(Node l, Node r)
    {
        cnt = 0;
        gcd = GCD(l.gcd, r.gcd);
        if (gcd == l.gcd) cnt += l.cnt;
        if (gcd == r.gcd) cnt += r.cnt;
    }
} st[N<<2];

void Build(int node, int sl, int sr)
{
    if (sl > sr) return;

    if (sl == sr)
    {
        st[node] = Node(A[sl]);
        return;
    }

    int mid = (sl+sr)>>1;
    Build(node<<1, sl, mid);
    Build((node<<1)|1, mid+1, sr);
    st[node].Merge(st[node<<1], st[(node<<1)|1]);
}

Node Query(int node, int sl, int sr, int l, int r)
{
    if (sl > sr || sl > r || sr < l) return Node();
    if (sl >= l && sr <= r) return st[node];

    int mid = (sl+sr)>>1;
    Node tmp = Node();
    tmp.Merge(Query(node<<1, sl, mid, l, r),
              Query((node<<1)|1, mid+1, sr, l, r));

    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int t1 = 0; t1 < n; ++t1)
        cin >> A[t1];

    Build(1, 0, n-1);
    int tc;
    cin >> tc;

    while (tc)
    {
        --tc;
        int l, r;
        cin >> l >> r;
        cout << (r-l+1) - Query(1, 0, n-1, l-1, r-1).cnt << '\n';
    }


    return 0;
}
