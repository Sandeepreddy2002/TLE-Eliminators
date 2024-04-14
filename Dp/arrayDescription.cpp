#include <bits/stdc++.h>
using namespace std;
#define int long long
#define s(x) scanf("%intd",&x)
#define s2(x,y) s(x)+s(y)
#define s3(x,y,z) s(x)+s(y)+s(z)
#define for0(i, n) for (int i = 0; i < n; i++)
#define reset(a) memset(a,-1,sizeof(a))
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

vi a;
int n;
int m;

int dp[100005][101];

int f(int i, int last)
{
	if (last > m || last <= 0)return 0;
	if (i == n and last <= m)return 1;
	if (dp[i][last] != -1)return dp[i][last];
	if (a[i] != 0 and abs(a[i] - last) > 1)return 0;
	if (a[i] != 0 and abs(a[i] - last) <= 1)
	{
		return f(i + 1, a[i]);
	}

	return dp[i][last] = (f(i + 1, last) + f(i + 1, last - 1) + f(i + 1, last + 1)) % MOD;
}

void solve()
{
	cin >> n >> m;
	a.resize(n);
	for (auto &i : a)cin >> i;
	reset(dp);
	int ans = 0;
	if (a[0] == 0)
	{
		for0(i, m)
		{
			ans = (ans + f(1, i + 1)) % MOD;
		}
	} else
	{
		cout << f(1, a[0]) << endl;
		return;
	}
	cout << ans << endl;
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