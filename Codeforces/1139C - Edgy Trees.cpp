#include <bits/stdc++.h.>
using namespace std;

using vi = vector <int>;
const int N = (1e5)+10;
const int MOD = (1e9)+7;

int n, k, sz;
bool vis[N];
vi g[N];
vi cmp;

void DFS(int x) // calculating sizes of components
{
	sz++;
  	vis[x] = 1;
  	
	for (int y: g[x])
  	{
   		if (!vis[y])
      		DFS(y);
  	}
}

int f(int a, int b) // fast modular exponentiation
{
  	int ans = 1;

  	while (b > 0)
  	{
    	if (b & 1)
      		ans = (1LL * ans * a) % MOD;

    	b >>= 1;
    	a = (1LL * a * a) % MOD;
  	}

  	return ans;
}

int main()
{
  	ios_base::sync_with_stdio(0);

  	cin >> n >> k;

  	for (int i = 1; i < n; ++i)
  	{
    	int a, b, t;
    	cin >> a >> b >> t;

    	if (!t) // graph will be divided into components
  		{
      		g[a].push_back(b);
      		g[b].push_back(a);
    	}
  	}

  	for (int i = 1; i <= n; ++i)
  	{
    	if (vis[i]) continue;
    	sz = 0;
    	DFS(i);
    	cmp.push_back(sz);
  	}
  
  	// total number of sequences is pow(n, k)
  	long long ans = 1;

  	for (int i = 0; i < k; i++)
    	ans = (1LL * ans * n) % MOD; // total number of sequences of length k

  	for (int x : cmp)
    	ans = ((ans - f(x, k)) % MOD + MOD) % MOD; // remove the bad sequences from each component

  	cout << ans << endl;


  	return 0;
}
