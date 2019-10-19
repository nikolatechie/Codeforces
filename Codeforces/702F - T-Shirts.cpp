// Codeforces problem 702F
#pragma GCC optimize("O3")
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdio>
using namespace std;

#define np nullptr

struct Shirt
{
    int pr, q;

    bool operator()(const Shirt &a, const Shirt &b) const
    {
        if (a.q > b.q) return 1;
        if (a.q == b.q && a.pr < b.pr) return 1;
        return 0;
    }
};

int n, k;
vector <int> ans;
vector <Shirt> vs;

struct Node
{
    int key, pr, i, lv, lcnt, cnt;
    Node *c[2];

    Node(int &k, int &id)
    {
        key = k;
        pr = rand();
        i = id;
        lv = lcnt = cnt = 0;
        c[0] = c[1] = np;
    }
};

void pd(Node *&x)
{
    if (x == np) return;

    if (x->lv)
    {
        x->key -= x->lv;
        x->cnt += x->lcnt;
        if (x->c[0] != np) x->c[0]->lv += x->lv, x->c[0]->lcnt += x->lcnt;
        if (x->c[1] != np) x->c[1]->lv += x->lv, x->c[1]->lcnt += x->lcnt;
        x->lv = x->lcnt = 0;
    }
}

void inOrder(Node *x)
{
    if (x == np) return;
    pd(x);
    inOrder(x->c[0]);
    ans[x->i] = x->cnt;
    inOrder(x->c[1]);
}

Node* getMin(Node *x)
{
    if (x == np) return np;
    while (x->c[0] != np) pd(x), x = x->c[0];
    pd(x);
    return x;
}

Node* getMax(Node *x)
{
    if (x == np) return np;
    while (x->c[1] != np) pd(x), x = x->c[1];
    pd(x);
    return x;
}

void Split(Node *x, Node *&L, Node *&R, int c)
{
    if (x == np) return void(L = R = np);
    pd(x);

    if (c <= x->key)
        Split(x->c[0], L, x->c[0], c), R = x;
    else
        Split(x->c[1], x->c[1], R, c), L = x;
}

void Merge(Node *&x, Node *L, Node *R)
{
    pd(L), pd(R);

    if (L == np || R == np)
        x = (L != np) ? L:R;
    else if (L->pr > R->pr)
        Merge(L->c[1], L->c[1], R), x = L;
    else
        Merge(R->c[0], L, R->c[0]), x = R;
}

void Insert(Node *&x, Node *n)
{
    Node *t;
    Split(x, x, t, n->key);
    Merge(t, n, t);
    Merge(x, x, t);
}

int main()
{
    ios_base::sync_with_stdio(0);


    srand(time(0));
    Node *root = np;
    scanf("%d", &n);
    vs.resize(n);

    for (int t1 = 0; t1 < n; ++t1)
        scanf("%d %d", &vs[t1].pr, &vs[t1].q);

    sort(vs.begin(),vs.end(),Shirt());
    scanf("%d", &k);
    ans.resize(k);

    for (int t1 = 0; t1 < k; ++t1)
    {
        int x;
        scanf("%d", &x);
        Insert(root, new Node(x,t1));
    }

    for (int t1 = 0; t1 < n; ++t1)
    {
        Node *L, *R;
        Split(root, L, R, vs[t1].pr);

        if (R == np)
        {
            root = L;
            continue;
        }
        else R->lv += vs[t1].pr, ++R->lcnt;

        if (L == np)
        {
            root = R;
            continue;
        }

        Node *Lmax = getMax(L);
        Node *Rmin = getMin(R);

        while (Rmin->key < Lmax->key)
        {
            Node *a, *b;
            Split(R, a, b, Rmin->key+1);
            Insert(L, a);
            R = b;
            if (R == np) break;
            Lmax = getMax(L);
            Rmin = getMin(R);
        }

        Merge(root, L, R);
    }

    inOrder(root);
    for (int t1 = 0; t1 < k; ++t1) printf("%d ", ans[t1]);
    printf("\n");


    return 0;
}
