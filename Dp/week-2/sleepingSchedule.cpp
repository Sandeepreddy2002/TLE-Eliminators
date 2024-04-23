#include <bits/stdc++.h>
using namespace std;
#define int long long
#define reset(a) memset(a,-1,sizeof(a))
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int MOD = 1e9 + 7;
#define vi vector<int>
#define nw cout<<endl;
//------------------------------------------------------------/


// int dp[2005][2005];
int n, h, l, r;
vi a;

// int f(int i, int s)
// {
//     int k = 0;
//     if (s <= r and s >= l and i!=0)k = 1;
//     if (i == n)return k;
//     if (dp[i][s] != -1)return dp[i][s];

//     return dp[i][s] = (k + max(f(i + 1, (s + a[i]) % h) , f(i + 1, (s + a[i] - 1) % h)));
// }
int dp[2005][2005];


void solve()
{
	cin >> n >> h >> l >> r;
	a.resize(n);
	for (auto &i : a)cin >> i;
	// reset(dp);
	// cout << f(0, 0) << endl;

	reset(dp);
	dp[0][0] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < h; j++)
		{
			int A = dp[i - 1][(j - a[i - 1] + h) % h];
			int B = dp[i - 1][(j - a[i - 1] + h + 1) % h];
			if (A == -1 and B == -1)continue;
			dp[i][j] = max(A, B) + (j >= l and j <= r);
		}
	}

	int ans = 0;
	for (int j = 0; j < h; j++)if (dp[n][j] > 0)ans = max(ans, dp[n][j]);
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