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




void solve()//using two arrays
{
	int n, k; cin >> n >> k;
	vi a(n);
	vi b(n);
	for (auto &i : a)cin >> i;
	for (auto &i : b)cin >> i;
	vi c(k + 1), p(k + 1) ;

	for (int i = n - 1; i >= 0 ; i--)
	{
		p = c;
		c.resize(k + 1);
		for (int j = 1; j <= k; j++)
		{
			if (i == n - 1)
			{
				c[j] = j - a[i] >= 0 ? b[i] : 0;
			} else
			{
				int A = p[j];
				int B = j - a[i] >= 0 ? p[j - a[i]] + b[i] : 0;
				c[j] = max(A, B);
			}
		}
	}

	cout << c[k] << endl;

}

void solve2()//using one array
{
	int n, k; cin >> n >> k;
	vi a(n);
	vi b(n);
	for (auto &i : a)cin >> i;
	for (auto &i : b)cin >> i;
	vi c(k + 1);

	for (int i = n - 1; i >= 0 ; i--)
	{
		for (int j = k; j >= 1; j--)
		{
			if (i == n - 1)
			{
				c[j] = j - a[i] >= 0 ? b[i] : 0;
			} else
			{
				int A = c[j];
				int B = j - a[i] >= 0 ? c[j - a[i]] + b[i] : 0;
				c[j] = max(A, B);
			}
		}
	}

	cout << c[k] << endl;
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
		solve2();
	}

	return 0;

}