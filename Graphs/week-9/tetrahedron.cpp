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
#ifndef ONLINE_JUDGE
#include "../../debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

/*------------------------------------------------------------*/





void solve()
{
	int n; cin >> n;
	vi pre = {0, 1, 1, 1};

	for (int i = 2; i <= n; i++)
	{
		vi curr(4);
		curr[0] = (pre[1] + pre[2] + pre[3]) % MOD;
		curr[1] = (pre[0] + pre[2] + pre[3]) % MOD;
		curr[2] = (pre[1] + pre[0] + pre[3]) % MOD;
		curr[3] = (pre[1] + pre[2] + pre[0]) % MOD;
		pre = curr;

	}
	cout << pre[0] << endl;
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