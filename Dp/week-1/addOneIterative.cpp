#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

int dp[200009];
signed main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int t;
	cin >> t;

	for (int i = 0; i <= 8; i++)dp[i] = 1;
	dp[9] = 2;

	for (int i = 10; i <= 200006; i++)
	{
		dp[i] = (dp[i - 9] + dp[i - 10]) % MOD;
	}

	while (t--)
	{
		int n, m; cin >> n >> m;
		int ans = 0;
		while (n)
		{
			int r = n % 10;
			if (m + r < 10)ans += 1;
			else if (m == 10 - r)ans += 2;
			else
			{
				ans = (ans + dp[m - (10 - r)] + dp[m - (10 - r) - 1]) % MOD;
			}
			n /= 10;
		}
		cout << ans << endl;

	}

	return 0;

}