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
const int INF = 1e6;
/*------------------------------------------------------------*/




int dp[200005] {};
void solve()
{
	int n; cin >> n;
	vi a(n);
	map<int, int> mp;
	for (auto &i : a)
	{
		cin >> i;
		mp[i] = INF;
	}

	dp[0] = 1;
	mp[a[0]] = 0;
	for (int i = 1; i < n; i++)
	{
		int k = 1 + dp[i - 1];
		int l = mp[a[i]];
		dp[i] = min(k, l);
		mp[a[i]] = min(l, dp[i - 1]);
	}

	cout << n - dp[n - 1] << endl;

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