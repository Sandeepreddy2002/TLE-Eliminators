#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

int dp[11][200008];
int cnt = 0;
int f(int x, int n)
{
	cnt++;
	if (n + x < 10)return 1;
	if (dp[x][n] != -1)return dp[x][n];
	return dp[x][n] = (f(1, n - (10 - x)) + f(0, n - 10 + x)) % MOD;
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;

	memset(dp, -1, sizeof dp);
	while (t--)
	{
		int x, n; cin >> x >> n;
		int ans = 0;
		cnt  = 0;
		while (x)
		{
			ans = (ans + f(x % 10, n)) % MOD; x /= 10;
		}
		cout << ans % MOD << " "  << endl;
	}
	return 0;

}