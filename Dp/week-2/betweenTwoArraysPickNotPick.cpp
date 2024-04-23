#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;


signed main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//dp[i][j] -> number of ways till ith index such that ci = j
	// dp[i][j] = dp[i-1][0] + dp[i-1][1] + .... + dp[i-1][j]
	// if j is not in range then dp[i][j] = 0;

	int dp[3001] {};
	int sum[3001] {};
	int n; cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (auto &i : a)cin >> i;
	for (auto &i : b)cin >> i;

	for (int i = a[0]; i <= b[0]; i++)dp[i] = 1;
	for (int i = 0; i <= 3000; i++)sum[i] = (dp[i] + sum[i - 1]) % MOD;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 3000; j++)
		{
			if (j < a[i - 1] || j > b[i - 1])
			{
				dp[j] = 0;
				sum[j] = sum[j - 1];
				continue;
			}

			dp[j] = sum[j];
			sum[j] = (dp[j] + sum[j - 1]) % MOD;
		}
	}

	cout << sum[3000] << endl;
	return 0;

}