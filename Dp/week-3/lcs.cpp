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
	string s1, s2; cin >> s1 >> s2;

	int n = s1.size();
	int m = s2.size();

	int dp[n + 2][m + 2] {};

	for (int i = n; i >= 1; i--)
	{
		for (int j = m; j >= 1; j--)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = 1 + dp[i + 1][j + 1];
			} else
			{
				dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}



	int x = 1, y = 1;

	while (x <= n and y <= m)
	{
		if (s1[x - 1] == s2[y - 1])
		{
			cout << s1[x - 1];
			x++, y++;
		} else
		{
			if (dp[x + 1][y] >= dp[x][y + 1])x++;
			else y++;
		}
	}
	nw

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