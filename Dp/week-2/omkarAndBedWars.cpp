#include <bits/stdc++.h>
using namespace std;
#define int long long
#define reset(a) memset(a,0,sizeof(a))
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
/*------------------------------------------------------------*/


string s;
int dp[200005][2][2];
int n;

int f(int i, int j)
{
	for (int p = 0; p <= n + 2; p++) {
		for (int q = 0; q < 2; q++) {
			for (int r = 0; r < 2; r++) {
				dp[p][q][r] = 0;
			}
		}
	}
	for (int i = n; i >= 2; i--)
	{
		if (s[i - 1] == 'L')
		{
			dp[i][0][0] = 1 + dp[i + 1][1][0];
			dp[i][0][1] = min(dp[i + 1][0][0], 1 + dp[i + 1][1][0]);
			dp[i][1][0] = min(dp[i + 1][0][1], 1 + dp[i + 1][1][1]);
			dp[i][1][1] = dp[i + 1][0][1];
		}
		else
		{
			dp[i][0][0] = dp[i + 1][1][0];
			dp[i][0][1] = min(dp[i + 1][1][0], 1 + dp[i + 1][0][0]);
			dp[i][1][0] = min(dp[i + 1][1][1], 1 + dp[i + 1][0][1]);
			dp[i][1][1] = 1 + dp[i + 1][0][1];
		}
	}


	return dp[3][i][j];

}


void solve()
{
	cin >> n;
	cin >> s;
	n += 2;

	int p = s[1] == 'L' ? 0 : 1;
	int lp = s[0] == 'L' ? 0 : 1;
	int ans = 1e10;

	int i = 0, j = 0;
	int a = (i != p ? 1 : 0);
	a = a +  (j != lp ? 1 : 0);


	s = s + "LL";
	ans = min(ans, a + f(i, j));

	s.pop_back();
	s.pop_back();

	s = s + "RL";
	i = 0, j = 1;
	a = (i != p ? 1 : 0);
	a = a +  (j != lp ? 1 : 0);
	ans = min(ans, a + f(i, j));
	s.pop_back();
	s.pop_back();

	s = s + "LR";
	i = 1, j = 0;
	a = (i != p ? 1 : 0);
	a = a +  (j != lp ? 1 : 0);

	ans = min(ans, a + f(i, j));

	s.pop_back();
	s.pop_back();

	s = s + "RR";
	i = 1, j = 1;
	a = (i != p ? 1 : 0);
	a = a +  (j != lp ? 1 : 0);
	ans = min(ans, a + f(i, j));

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
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve();
	}

	return 0;

}