#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int MOD = 998244353;
#define vi vector<int>
#define nw cout<<endl;
/*------------------------------------------------------------*/
//Time complexity will be approx -> 3000^3;=> tle

vi a;
vi b;
int n;
int dp[3005][3005];
int f(int i, int last)
{
	if (i == n)
	{
		return 1;
	}
	int ans = 0;

	if (last != -1 and dp[i][last] != -1)return dp[i][last];
	for (int k = a[i]; k <= b[i]; k++)
	{
		if (last == -1 || k >= last)
		{
			ans  = (ans + f(i + 1, k)) % MOD;
		}
	}
	if (last != -1) dp[i][last] = ans;
	return ans;
}



void solve()
{
	cin >> n;
	a.resize(n);
	b.resize(n);
	memset(dp, -1 , sizeof dp);
	for (auto &i : a)cin >> i;
	for (auto &i : b)cin >> i;

	cout << f(0, -1) << endl;

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