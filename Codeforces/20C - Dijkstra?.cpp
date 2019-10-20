#include <bits/stdc++.h>
using namespace std;

typedef unsigned short usint;
typedef unsigned uint;
typedef long lint;
typedef short sint;
typedef unsigned long ulint;
typedef unsigned long long ullint;
typedef long long llint;

#define INF 100000000000000000
#define mp make_pair
#define pii pair <int,int>
#define pib pair <int,bool>
#define pll pair <long,long>
#define pcc pair <char,char>
#define pui pair <uint,uint>
#define pul pair <ulint,ulint>
#define pff pair <float,float>
#define pllll pair <llint,llint>
#define pss pair <string,string>
#define pull pair <ullint,ullint>


int main()
{
    ios_base::sync_with_stdio(0);


    int n, m;
    cin >> n >> m;

    vector <vector <pii>> graf(n);

    for (int t1 = 0; t1 < m; ++t1)
    {
        ullint a, b, c;
        cin >> a >> b >> c;
        graf[a-1].push_back(mp(b-1,c));
        graf[b-1].push_back(mp(a-1,c));
    }

    vector <ullint> dist(n, INF);
    dist[0] = 0;
    vector <bool> posjecen(n,0);
    set <pull> S;
    S.insert(mp(0,0));
    vector <llint> parent(n,-1);

    for (int t1 = 1; t1 < n; ++t1)
        S.insert(mp(INF,t1));

    for (int t1 = 0; t1 < n-1; ++t1)
    {
        ullint cvor = S.begin()->second;
        ullint udns = S.begin()->first;
        posjecen[cvor] = true;
        S.erase(S.begin());
        for (int t2 = 0; t2 < graf[cvor].size(); ++t2)
        {
            ullint susjed = graf[cvor][t2].first;
            ullint tezina = graf[cvor][t2].second;
            if (!posjecen[susjed])
            {
                if (dist[susjed] > udns+tezina)
                {
                    S.erase(mp(dist[susjed],susjed));
                    dist[susjed] = udns+tezina;
                    S.insert(mp(dist[susjed],susjed));
                    parent[susjed] = cvor;
                }
            }
        }
    }

    if (dist[n-1] >= INF)
        cout << -1 << '\n';
    else
    {
        vector <int> put;
        int cvor = parent[n-1];
        put.push_back(n-1);
        while (cvor != -1)
        {
            put.push_back(cvor);
            cvor = parent[cvor];
        }
        for (int t1 = put.size()-1; t1 >= 0; --t1)
            if (put[t1]+1 > 0) cout << put[t1]+1 << ' ';
        cout << '\n';
    }

    return 0;
}
