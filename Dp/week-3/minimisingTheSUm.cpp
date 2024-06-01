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
#define vi vector<int>
#define sz(x) (int)x.size()
#define all(s) s.begin(),s.end()
#define nw cout<<endl;
int gcd(int a, int b)
{
	return (b == 0 ? a : gcd(b, a % b));
}
#ifndef ONLINE_JUDGE
#include "../../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

/*------------------------------------------------------------*/

int n;
vi a;
int dp[300005][11];
// int c = 0;



void solve()
{
	int k;
	cin >> n >> k;
	a.resize(n);
	for (auto &i : a)cin >> i;

	vector<vector<int>> dp(n + 1, vector<int> (11, 1e18));


	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= min(k, i); j++)
		{
			for (int x = 0; x <= j; x++)
			{
				int mini = 1e15;
				if (i - x - 1 < 0)continue;
				for (int k = 0; k <= x; k++)mini = min(a[i - k - 1], mini);
				dp[i][j] = min(dp[i][j], dp[i - x - 1][j - x] + mini * (x + 1) );
			}
		}
	}
	int ans = 1e18;
	for (int i = 0; i <= k; i++)ans = min(dp[n][i], ans);
	cout << ans << endl;
	debug(dp);
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