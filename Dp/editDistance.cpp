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
#define all(s) s.begin(),s.end()
#define vi vector<int>
#define nw cout<<endl;
/*------------------------------------------------------------*/


int f(string a, string b)
{
	map<char, int> ma, mb;
	for (auto i : a)ma[i]++;
	for (auto i : b)mb[i]++;
	int a1 = 0, a2 = 0;
	for (auto i : ma)
	{
		int k = ma[i.first] > mb[i.first] ? ma[i.first] - mb[i.first] : 0;
		a1 += k;
	}
	return a1;
}


void solve()
{
	string a, b;
	cin >> a >> b;

	cout << max(f(a, b), f(b, a)) << endl;


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