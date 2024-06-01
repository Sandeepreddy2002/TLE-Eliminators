#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int MOD = 1e9 + 7;
// #ifndef ONLINE_JUDGE
// #include "../../debug.cpp"
// #else
// #define debug(...)
// #define debugArr(...)
// #endif

/*------------------------------------------------------------*/


int a[22][22];
int n;
int c = 0;

//dp[i][mask] => number ways with current element as i and mask as the choosen elements
//recursive approach ->
//base case -> if(mask == (1<<n)-1)return 1;

int f(int i, int mask, vector<vector<int>> &dp)
{c++;
	if (i == n)return 1;

	cout << i << " " << __builtin_popcount(mask) << endl;
	if (dp[i][mask] != -1)return dp[i][mask];
	int ans = 0;
	for (int j = 0; j < n; j++)
	{
		if (mask & (1 << j)  || a[j][i] == 0)continue;
		ans = (ans + f(i + 1, mask | (1 << j), dp)) % MOD;
	}

	return dp[i][mask] = ans;
}



void solve()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	vector<vector<int>> dp(n + 1, vector<int>((1 << n) + 1, 0));
	dp[n][(1 << n) - 1] = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int mask = 0; mask < (1 << n); mask++)
		{
			for (int j = 0; j < n; j++)
			{
				if ((mask & (1 << j)) || a[j][i] == 0)continue;
				dp[i][mask] = (dp[i][mask] + dp[i + 1][mask | (1 << j)]) % MOD;
			}
		}
	}
	// debug(dp);

	cout << dp[0][0] << " " << c << endl;
}

signed main()
{

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	fast

	int t = 1;
	//cin>>t;

	for (int i = 1; i <= t; i++)
	{
		solve();
	}

	return 0;

}