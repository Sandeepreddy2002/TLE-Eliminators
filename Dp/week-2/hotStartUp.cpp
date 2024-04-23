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


// int dp[100][100][100] {};



//O(n*k*k)
// void solve()
// {
// 	int  n, m; cin >> n >> m;
// 	vi a(n);
// 	for (auto &i : a)cin >> i;
// 	vi cold(m);
// 	for (auto &i : cold)cin >> i;
// 	vi hot(m);
// 	for (auto &i : hot)cin >> i;
// 	int INF = 1e8;

// 	vector<vector<int>> pre(n + 3, vector<int> (n + 3, 0));
// 	vector<vector<int>> curr(n + 3, vector<int> (n + 3, 0));

// 	// for(int j = 1; j <= n; j++)
// 	// {
// 	// 	for(int i = 1; j <= n; j++)
// 	// 	{
// 	//         dp[n+1][i][j] = INF;
// 	// 	}
// 	// }

// 	for (int i = n; i >= 1; i--)
// 	{
// 		for (int j = 0; j <= m ; j++)
// 		{
// 			for (int k = 0; k <= m; k++)
// 			{
// 				int A = INF, B = INF, C = INF, D = INF;
// 				if (a[i - 1] == j)
// 					A = pre[a[i - 1]][k] + hot[a[i - 1] - 1];
// 				else
// 					A = pre[a[i - 1]][k] + cold[a[i - 1] - 1];
// 				if (a[i - 1] == k)
// 					B = pre[j][a[i - 1]] + hot[a[i - 1] - 1];
// 				else
// 					B = pre[j][a[i - 1]] + cold[a[i - 1] - 1];
// 				curr[j][k] = min(A, B);
// 			}
// 		}
// 		pre = curr;
// 	}

// 	cout << pre[0][0] << endl;


// }

int dp[5005][5005] {};

void solve2()
{

	int  n, m; cin >> n >> m;
	vi a(n);
	for (auto &i : a)cin >> i;
	vi cold(m);
	for (auto &i : cold)cin >> i;
	vi hot(m);
	for (auto &i : hot)cin >> i;
	int INF = 1e8;
	for (int i = 0; i <= n + 2; i++)
		for (int j = 0; j <= m; j++)dp[i][j] = 0;
	// vector<vector<int>> dp(n + 3, vector<int> (n + 3, 0));

	for (int i = n; i >= 1; i--)
	{
		for (int j = 0; j <= m ; j++)
		{
			int A = INF, B = INF;

			int p = (i - 2 >= 0 ? a[i - 2] : 0);
			if (a[i - 1] == p)A = dp[i + 1][j] + hot[a[i - 1] - 1];
			else
				A = dp[i + 1][j] + cold[a[i - 1] - 1];

			if (a[i - 1] == j)B = dp[i + 1][p] + hot[a[i - 1] - 1];
			else
				B = dp[i + 1][p] + cold[a[i - 1] - 1];

			dp[i][j] = min(A, B);
		}
	}
	cout << dp[1][0] << endl;
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
		solve2();
	}

	return 0;

}