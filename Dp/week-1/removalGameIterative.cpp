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

int dp[5001][5001];
const int INF = -1e10;

void solve()
{
	int n; cin >> n;
	vi a(n);
	for (auto &i : a)cin >> i;
	for0(i, 5001)
	for0(j, 5001)dp[i][j] = INF;
	for (int l = n - 1; l >= 0; l--)
	{
		for (int r = l; r < n; r++)
		{
			if (l == r)
			{
				dp[l][r] = a[l];
				continue;
			}
			if (r - l == 1)
			{
				dp[l][r] = max(a[l], a[r]);
				continue;
			}

			int ans1 = a[l] +  min(dp[l + 2][r],  dp[l + 1][r - 1]);
			int ans2 = a[r] + min(dp[l + 1][r - 1],  dp[l][r - 2]);
			dp[l][r] = max(ans1, ans2);
		}
	}
	cout << dp[0][n - 1] << endl;
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