// My Treap solution for Bubble Cup 2018's problem Rocks
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


struct Node
{
    string key;
    llint pr, mass, sum, sz;
    Node *c[2];

    Node(string k = "")
    {
        key = k;
        sz = 1;
        mass = 0;

        for (llint t1 = 0; t1 < k.size(); ++t1)
            mass += llint(k[t1]-'a')+1;

        sum = mass;
        pr = rand();
        c[0] = c[1] = np;
    }
};

inline llint sz(Node *x)
{
    return (x == np) ? 0:x->sz;
}

inline llint sum(Node *x)
{
    return (x == np) ? 0:x->sum;
}

inline llint mass(Node *x)
{
    return (x == np) ? 0:x->mass;
}

void upd(Node *x)
{
    x->sum = sum(x->c[0]) + sum(x->c[1]) + mass(x);
    x->sz = 1 + sz(x->c[0]) + sz(x->c[1]);
}

void Split(Node *x, Node *&L, Node *&R, llint i)
{
    if (x == np) return void(L = R = np);

    if (i <= sz(x->c[0]))
        Split(x->c[0], L, x->c[0], i), R = x;
    else
        Split(x->c[1], x->c[1], R, i-sz(x->c[0])-1), L = x;

    upd(x);
}

void Merge(Node *&x, Node *L, Node *R)
{
    if (L == np || R == np)
        x = (L != np) ? L:R;
    else if (L->pr > R->pr)
        Merge(L->c[1], L->c[1], R), x = L;
    else
        Merge(R->c[0], L, R->c[0]), x = R;

    upd(x);
}

Node* Kth(Node *x, llint k)
{
    while (sz(x->c[0]) != k)
    {
        if (k <= sz(x->c[0]))
            x = x->c[0];
        else
            k -= (sz(x->c[0])+1), x = x->c[1];
    }

    return x;
}

llint QueryMass(Node *x, llint L, llint R)
{
    Node *t1, *t2;
    Split(x, x, t2, R+1);
    Split(x, x, t1, L);
    llint ans = sum(t1);
    Merge(t1, t1, t2);
    Merge(x, x, t1);
    return ans;
}

void Swap(Node *root, int i, string &s)
{
    if (i == sz(root->c[0]))
    {
        root->key = s;
        Node *temp = new Node(s);
        root->mass = temp->mass;
        upd(root);
        delete temp;
        return;
    }

    if (i < sz(root->c[0]))
        Swap(root->c[0], i, s);
    else
        Swap(root->c[1], i-sz(root->c[0])-1, s);

    upd(root);
}

map <string,llint> M; // name, index
map <string,llint>::iterator it;

int main()
{
    ios_base::sync_with_stdio(0);


    llint q;
    cin >> q;
    char opt;
    string x, y;
    Node *root = np;

    while (q)
    {
        --q;
        cin >> opt;

        if (opt == 'A')
        {
            cin >> x;
            it = M.find(x);

            if (it == M.end())
            {
                M[x] = sz(root);
                Merge(root,root,new Node(x));
            }
            else cout << "Can't add " << x << '\n';
        }
        else if (opt == 'S')
        {
            cin >> x >> y;
            Swap(root,M[x],y);
            Swap(root,M[y],x);
            swap(M[x],M[y]);
        }
        else if (opt == 'M')
        {
            cin >> x >> y;
            llint L = M[x], R = M[y];
            if (L > R) swap(L,R);
            cout << QueryMass(root,L,R) << '\n';
        }
        else if (opt == 'R')
        {
            cin >> x >> y;
            Swap(root,M[x],y);
            M[y] = M[x];
            M.erase(x);
        }
        else if (opt == 'N') cout << sz(root) << '\n';
    }



    return 0;
}
