// Codeforces problem 13E
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


int n, m, sz;
vector <int> p;
vector <int> nxtHole, jumpCnt, endHole;

void Query(int i) // put the ball into this hole
{
    int cnt = 0;

    while (nxtHole[i] < n)
    {
        cnt += jumpCnt[i];
        i = nxtHole[i];
    }

    cnt += jumpCnt[i];

    cout << endHole[i]+1 << ' ' << cnt << '\n';
}

void Update(int i, int newp)
{
    p[i] = newp;
    int bucketNum = (i/sz)*sz; // starting index of this bucket

    for (int t1 = i; t1 >= bucketNum; --t1)
    {
        int nxt = p[t1] + t1;

        if (nxt < n)
        {
            if (t1/sz == nxt/sz) // in the same bucket
            {
                nxtHole[t1] = nxtHole[nxt];
                jumpCnt[t1] = 1 + jumpCnt[nxt];
                endHole[t1] = endHole[nxt];
            }
            else
            {
                nxtHole[t1] = nxt;
                jumpCnt[t1] = 1;
                endHole[t1] = endHole[nxt];
            }
        }
        else
        {
            nxtHole[t1] = nxt;
            jumpCnt[t1] = 1;
            endHole[t1] = t1;
        }
    }
}

void preprocess()
{
    sz = ceil(sqrt(n));
    nxtHole.resize(n+1);
    jumpCnt.resize(n+1);
    endHole.resize(n+1);

    for (int t1 = n-1; t1 >= 0; --t1)
        Update(t1, p[t1]); // update this
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    p.resize(n);

    for (int t1 = 0; t1 < n; ++t1)
        cin >> p[t1];

    preprocess();

    while (m)
    {
        --m;
        bool op;
        int a;
        cin >> op >> a;

        if (!op)
        {
            int b;
            cin >> b;
            Update(a-1,b);
        }
        else Query(a-1);
    }



    return 0;
}
