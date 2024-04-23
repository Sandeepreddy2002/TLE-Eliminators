#include <bits/stdc++.h>
using namespace std;
#define int long long
#define NO cout<<"NO\n"
const int MOD = 1e9 + 7;

/*------------------------------------------------------------*/


void solve()
{
	int n; cin >> n;
	if (n == 1)
	{
		cout << 0 << endl;
		return;
	}
	else if (n == 2)
	{
		cout << 3 << endl;
		return;
	}

	int ans = 3;
	int val = 3;
	for (int i = 3; i <= n; i++)
	{
		ans = ((val * 3 - ans) % MOD + MOD) % MOD;
		val = (val * 3) % MOD;
	}

	cout << ans << endl;
}

signed main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	//cin>>t;

	for (int i = 1; i <= t; i++)
	{
		solve();
	}

	return 0;

}