#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int MOD = 1e9 + 7;
#define vi vector<int>
#define nw cout<<endl;
/*------------------------------------------------------------*/





void solve()
{
	int n, k; cin >> n >> k;
	vi a(n);
	for (auto &i : a)cin >> i;

	int dp[100005] {};
	int sum[100005] {};

	for (int i = k; i >= 0; i--)
	{
		if (k - i <= a[n - 1])dp[k - i] = 1;
		if (k - i >= 1)
			sum[k - i] = (dp[k - i] + sum[k - i - 1]) % MOD;
		else sum[k - i] = dp[k - i];
	}

	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = k; j >= 0; j--)
		{
			int l = 0;
			if (j - a[i - 1] > 0)l = sum[j - a[i - 1] - 1];
			dp[j] = (sum[j] - l + MOD) % MOD;
		}
		sum[0] = dp[0];
		for (int j = 1; j <= k; j++)sum[j] = (dp[j] + sum[j - 1]) % MOD;
	}
	cout << dp[k] % MOD << endl;
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