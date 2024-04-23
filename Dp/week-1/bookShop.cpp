#include <bits/stdc++.h>
using namespace std;
#define int long long
#define for0(i, n) for (int i = 0; i < n; i++)
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define per(i,j,k) for(int i=j;i>=k;--i)
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
const int MOD = 1e9 + 7;
#define pb push_back
#define vi vector<int>
#define nw cout<<endl;
/*------------------------------------------------------------*/

vi a;
vi b;
int n;

int dp[1001][100001];
int f(int i, int k)
{
	if (k <= 0 || i >= n)return 0;
	if (dp[i][k] != -1)return dp[i][k];
	if (a[i] > k)return f(i + 1, k);
	return dp[i][k] = max(f(i + 1, k), f(i + 1, k - a[i]) + b[i]);
}

void solve()
{
	cin >> n;
	int k; cin >> k;
	a.resize(n);
	b.resize(n);
	memset(dp, -1, sizeof dp);
	for (auto &i : a)cin >> i;
	for (auto &i : b)cin >> i;
	cout << f(0, k) << endl;
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