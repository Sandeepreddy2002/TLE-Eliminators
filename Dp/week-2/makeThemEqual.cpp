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

int k[100005] {};
int dp[100000] {};

void solve()
{
	int n, m; cin >> n >> m;
	if (m > 100000)m = 100000;
	vi a(n);
	vi c(n);
	reset(dp);
	for (auto &i : a)
	{
		cin >> i;
		i = k[i];
	}
	for (auto &i : c)cin >> i;

	for (int i = 0; i <= m; i++)
	{
		if (a[n - 1] <= i)dp[i] = c[n - 1];
	}

	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = m; j >= 0; j--)
		{
			int A = dp[j], B = 0;;
			if (j - a[i - 1] >= 0)B = dp[j - a[i - 1]] + c[i - 1];
			dp[j] = max(A, B);
		}
	}

	cout << dp[m] << "\n";
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

	k[2] = 1;
	for (int i = 2; i <= 10002; i++)
	{
		int j = 1;
		while ((i / j) > 0)
		{
			if ((i + i / j) > 100002)break;
			if (k[i + i / j] == 0)
			{
				k[i + i / j] = 1 + k[i];
			} else
			{
				k[i + i / j] = min( 1 + k[i], k[i + i / j]);
			}
			j++;
		}
	}


	for (int i = 1; i <= t; i++)
	{
		solve();
	}

	return 0;

}