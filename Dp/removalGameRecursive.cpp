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

int dp[5001][5001];
vi a;
const int INF = -1e10;
int f(int l, int r)
{
	if (l > r)return 0;
	if (l == r)return a[l];
	if (dp[l][r] != INF)return dp[l][r];
	int ans1 = min(a[l] + f(l + 2, r), a[l] + f(l + 1, r - 1));
	int ans2 = min(a[r] + f(l + 1, r - 1), a[r] + f(l, r - 2));

	return dp[l][r] = max(ans1, ans2);
}




void solve()
{
	int n; cin >> n;
	a.resize(n);
	for (auto &i : a)cin >> i;
	for0(i, 5001)
	for0(j, 5001)dp[i][j] = INF;
	cout << f(0, n - 1);
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