#include <bits/stdc++.h>
using namespace std;
#define int long long
#define s(x) scanf("%intd",&x)
#define s2(x,y) s(x)+s(y)
#define s3(x,y,z) s(x)+s(y)+s(z)
#define for0(i, n) for (int i = 0; i < n; i++)
#define reset(a) memset(a,0,sizeof(a))
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define per(i,j,k) for(int i=j;i>=k;--i)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
const int MOD = 1e9 + 7;
#define pb push_back
#define vi vector<int>
#define sz(x) (int)x.size()
#define all(s) s.begin(),s.end()
#define nw cout<<endl;
int gcd(int a, int b)
{
	return (b == 0 ? a : gcd(b, a % b));
}
/*------------------------------------------------------------*/





void solve()
{
	int n, m; cin >> n >> m;
	vi a(n);
	for (auto &i : a)cin >> i;

	vector<vector<int>> dp(n + 1, vector<int> (m + 1));

	for (int i = 1; i < m + 1; i++)dp[n][i] = 1;

	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i] != 0)
			{
				if (abs(a[i] - j) > 1)
				{
					dp[i][j] = 0;
				}
				else
				{
					dp[i][j] = dp[i + 1][a[i]];
				}
				continue;
			}
			int A = 0, B = 0, C = 0;
			A = dp[i + 1][j];
			if (j >= 2)B = dp[i + 1][j - 1];
			if (j + 1 <= m)C = dp[i + 1][j + 1];
			dp[i][j] = (A  + B  + C) % MOD;
		}
	}

	if (a[0] != 0)
		cout << dp[1][a[0]] << endl;
	else
	{
		int ans = 0;
		for0(i, m)ans = (ans + dp[1][i + 1]) % MOD;
		cout << ans << endl;
	}
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