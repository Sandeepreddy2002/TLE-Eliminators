#include <bits/stdc++.h>
using namespace std;
#define int long long
#define for0(i, n) for (int i = 0; i < n; i++)
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define per(i,j,k) for(int i=j;i>=k;--i)
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
const int MOD = 1e9 + 7;
#define pb push_back
#define vi vector<int>
#define nw cout<<endl;
/*------------------------------------------------------------*/

void solve()
{
	int n, k; cin >> n >> k;

	vector<vector<int>> dp(k , vector<int>(n + 2, 0));

	for (int i = 1; i <= n; i++)dp[k - 1][i] = 1;

	for (int i = k - 2; i >= 0; i--)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int m = j; m <= n; m += j)
			{
				dp[i][j] = (dp[i][j] + dp[i + 1][m]) % MOD;
			}
		}
	}

	int ans = 0;
	for0(i, n + 1)
	{
		ans = (ans + dp[0][i]) % MOD;
	}
	cout << ans << endl;
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