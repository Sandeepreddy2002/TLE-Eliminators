#include <bits/stdc++.h>
using namespace std;
#define int long long
#ifndef ONLINE_JUDGE
#include "../../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
const double INF = 1e10;
vector<pair<double, double>> points;
int n;
double dist(int i, int j) {
	double x1 = points[i].first, x2 = points[j].first;
	double y1 = points[i].second, y2 = points[j].second;
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
double f(int last, int bitmask, vector<vector<double>>& dp) {
	// base case
	if (bitmask == (1 << n) - 1) { // exhausted all the points
		return 0;
	}
	if (dp[last][bitmask] != -1.0) {
		return dp[last][bitmask];
	}
	double ans = 1e18;
	for (int i = 0; i < n; i++) {
		if (bitmask & (1 << i)) { // point has already been chosen
			continue;
		}
		ans = min(ans, dist(i, last) + f(i, bitmask | (1 << i), dp));
	}
	return dp[last][bitmask] = ans;
}
void solve() {
	cin >> n;
	points.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> points[i].first >> points[i].second;
	}
	// dp[i][bitmask] = min distance among the remaining
	// set of points if ith point was the last point
	// chosen and bitmask represents the set of points
	// chosen already
	vector<vector<double>> dp(n, vector<double>(1 << n, -1.0));
	double ans = 1e18;
	for (int i = 0; i < n; i++) {
		// I am choosing the ith point as my first point
		f(i, 1 << i, dp);
		double ansHere = dp[i][1 << i];
		ans = min(ans, ansHere);
	}
	cout << ans << endl;
	// if n = 5
	// ans = min(dp[0][00001], dp[1][00010], dp[2][00100], dp[3][01000], dp[4][10000])
}

signed main() {

	int t; t = 1;
	// cin>>t;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (t--)solve();
}




//TC => n*n*n*2^n
// void solve() {

// 	int n; cin >> n;
// 	for (int i = 0; i < n; i++) {
// 		int x; int y; cin >> x >> y;
// 		points.push_back({x, y});
// 	}

// 	vector<vector<vector<double>>> dp(n + 1, vector<vector<double>> (1 << n, vector<double> (n, INF)));
// 	// vector<vector<double>> dp(1 << n, vector<double> (n, INF));

// 	for (int i = 0; i < n; i++)
// 	{
// 		dp[1][1 << i][i] = 0;
// 	}

// 	for (int i = 1; i <= n; i++)
// 	{
// 		for (int mask = 1; mask < (1 << n); mask++)
// 		{
// 			int noOfSetBits = __builtin_popcount(mask);
// 			if (noOfSetBits != i - 1)continue;

// 			for (int j = 0; j < n; j++) //j -> last element
// 			{
// 				if ((mask & (mask >> j)))continue;
// 				for (int k = 0; k < n; k++)
// 				{
// 					dp[i][mask | (1 << j)][j] = min(dp[i][mask | (1 << j)][j], find_distance(j, k) + dp[i - 1][mask][k]);
// 				}
// 			}

// 		}
// 	}
// 	double ans = 1e10;

// 	for (int i = 0; i < n; i++)
// 	{
// 		ans = min(ans, dp[n][(1 << n) - 1][i]);
// 	}
// 	cout << ans << endl;

// }