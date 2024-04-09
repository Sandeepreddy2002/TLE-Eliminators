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


int dp[1001][1001];


void solve()
{
	int n; cin >> n;
	char a[n][n];
	for (auto &i : a)cin >> i;

	// if (a[0][0] == '*')
	// {
	// 	cout << 0 << endl;
	// 	return;
	// }
	dp[1][1] = 1;


	rep(i, 1, n)
	{
		rep(j, 1, n)
		{
			if (i == 1 and j == 1)continue;
			if (a[i - 1][j - 1] == '*')
			{
				dp[i][j] = 0;
				continue;
			}

			(dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD) %= MOD;
			dp[i][j] %= MOD;
		}
	}
	cout << dp[n][n] << endl;


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