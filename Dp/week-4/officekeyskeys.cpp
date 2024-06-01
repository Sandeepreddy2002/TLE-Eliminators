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

int n, k, p;
vi persons;
vi keys;
const int INF = 1e18;
map<pair<int, vector<int>>, int> mp;
int c = 0;
int f(int i, vi &taken)
{
	c++;
	if (i == n)return 0;
	int ans = INF;
	if (mp[ {i, taken}] != 0)return mp[ {i, taken}];
	for (int m = i; m < n; m++)
	{
		for (int key = 0; key < k; key++)
		{
			if (taken[key] == 1)continue;
			taken[key] = 1;
			ans = min(ans, abs(persons[m] - keys[key]) + abs(keys[key] - p) + f(m + 1, taken));
			taken[key] = -1;
		}
	}
	return mp[ {i, taken}] = ans;
}

void solve()
{
	cin >> n >> k >> p;
	persons.resize(n);
	keys.resize(k);
	vi taken(k + 1, -1);
	for (auto &i : persons)cin >> i;
	for (auto &i : keys)cin >> i;

	cout << f(0, taken) << " " << c << endl;


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