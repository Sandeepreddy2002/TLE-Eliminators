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


int dp[505][505][23] {};


void solve()
{
	int n, m, k; cin >> n >> m >> k;

	vector<vector<int>> horizontalEdges(n + 1, vector<int> (m + 1 , 0));
	vector<vector<int>> verticalEdges(n + 1, vector<int> (m + 1, 0));

	for0(i, n)
	{
		for0(j, m - 1)cin >> horizontalEdges[i][j];
	}
	for0(i, n - 1)
	{
		for0(j, m)cin >> verticalEdges[i][j];
	}
	int dx[4] = { -1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	for (int k = 0; k <= 10; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (k == 0)dp[i][j][k] = 0;
				else if (k & 1)dp[i][j][k] = -1;
				else
				{
					if (k - 2 < 0)continue;
					dp[i][j][k] = 1e18;
					for (int d = 0; d < 4; d++)
					{
						int newi =  i + dx[d];
						int newj =  j + dy[d];
						int edgeWeight = 0;
						if (newi < 1 || newi > n || newj < 1 || newj > m)continue;
						if (newi != i)
						{
							edgeWeight = verticalEdges[min(newi - 1, i - 1)][min(newj - 1, j - 1)];
						} else
						{
							edgeWeight = horizontalEdges[min(newi - 1, i - 1)][min(newj - 1, j - 1)];

						}
						dp[i][j][k] = min(dp[i][j][k], dp[newi][newj][k - 2] + 2 * edgeWeight);
					}

				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)cout << dp[i][j][k] << " ";
		nw;
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