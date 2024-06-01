#include <bits/stdc++.h>
using namespace std;
#define int long long
#define s(x) scanf("%intd",&x)
#define s2(x,y) s(x)+s(y)
#define s3(x,y,z) s(x)+s(y)+s(z)
#define for0(i, n) for (int i = 0; i < n; i++)
#define reset(a) memset(a,0,sizeof(a))
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define per(i,j,k) for(int i=j;i>=k;--i)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
const int MOD = 1e9 + 7;
#define pb push_back
#define vi vector<int>
#define sz(x) (int)x.size()
#define all(s) s.begin(),s.end()
#define nw cout<<endl;
int gcd(int a, int b)
{
	return (b == 0 ? a : gcd(b, a % b));
}
// #ifndef ONLINE_JUDGE
// #include "../../debug.cpp"
// #else
// #define debug(...)
// #define debugArr(...)
// #endif

/*------------------------------------------------------------*/

vi parents(7, -1);
void dfs(int node, vector<int> &vis, vector<vector<int>> adj, vector<int> &ans)
{
	vis[node] = 1;
	ans.pb(node);
	for (auto it : adj[node])
	{
		if (vis[it] != 1)
		{
			parents[it] = node;
			dfs(it, vis, adj, ans);
		}
	}
}

void bfs(int n, vector<vector<int>> adj)
{
	queue<int> q;
	vector<int> vis(n, 0);
	q.push(0);
	while (!q.empty())
	{
		int top = q.front();
		vis[top] = 1;
		cout << top + 1 << " ";
		q.pop();
		for (auto it : adj[top])
		{
			if (vis[it] != 1)
			{
				q.push(it);
			}
		}
	}
}

void solve()
{
	int n, e; cin >> n >> e;
	vector<vector<int>> adj(n);

	for (int i = 0; i < e; i++)
	{
		int a, b; cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	vector<int> ans;
	vector<int> vis(n, 0);
	dfs(4, vis, adj, ans);
	// for (auto it : parents)cout << it << " ";
	int a = 6;
	while (true)
	{
		cout << a + 1 << " ";
		if (parents[a] == -1)break;
		a = parents[a];
	}

	// int cnt = 0;

	//connected components
	// for (int i = 0; i < n; i++)
	// {
	// 	if (vis[i] == 0)
	// 	{
	// 		dfs(i, vis, adj, ans);
	// 		cnt++;
	// 	}
	// }
	// cout << cnt;

	// for (auto it : ans)cout << it + 1 << " ";
	// bfs(n, adj);
}

signed main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast

	int t = 1;
	//cin>>t;

	for (int i = 1; i <= t; i++)
	{
		solve();
	}

	return 0;

}