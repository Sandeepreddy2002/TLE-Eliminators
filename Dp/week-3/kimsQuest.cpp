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
const int MOD = 998244353;
#define pb push_back
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
int c = 0;



int f(int i, int p, int sp, vector<vector<vector<int>>> &dp)
{
	c++;
	if (i == n)return 0;
	int ans = 0;
	if (dp[i][p][sp] != -1)return dp[i][p][sp];
	ans  = ans + f(i + 1, p, sp, dp);
	if (p == 2 || sp == 2)ans = (ans + f(i + 1, a[i] & 1, p, dp)) % MOD;
	else
	{
		if (((p & 1) + (sp & 1) + (a[i] & 1) & 1) == 0)ans = (1 + ans + f(i + 1, a[i] & 1, p, dp)) % MOD;
	}
	return dp[i][p][sp] = ans;
}


void solve()
{
	cin >> n;
	a.resize(n);
	for (auto &i : a)cin >> i;
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(4, vector<int>(4, -1)));
	cout << f(0, 2, 2, dp) << endl;
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
	//cin>>t;

	for (int i = 1; i <= t; i++)
	{
		solve();
	}

	return 0;

}