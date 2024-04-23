#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

vector<double> v;
int n;
double dp[3009][3009];
int cnt = 0;
double f(int i, int x)
{
	cnt++;
	if (i == n and x < (n + 1) / 2)return 0.0;
	else if (i == n and x >= (n + 1) / 2)return 1.0;
	if (dp[i][x] != 0)return dp[i][x];

	return dp[i][x] = v[i] * (f(i + 1, x + 1)) + (1 - v[i]) * f(i + 1, x);
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	v.resize(n);
	for (auto &i : v)cin >> i;
	memset(dp, 0, sizeof dp);
	double ans = f(0, 0);
	cout << setprecision(10) << fixed;
	cout << ans << " " << cnt << endl;
	return 0;
}