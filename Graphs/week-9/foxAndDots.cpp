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
int n, m;
bool isValid(int i, int j)
{
	if (i >= 0 and i < n and j >= 0 and j < m)return true;
	return false;
}

vi dx = { -1, 0, 1, 0};
vi dy = {0, 1, 0, -1};
bool dfs(int i, int j, vector<vector<int>> &vis, vector<string> matrix, char c)
{
	vis[i][j] = 1;

	for (int k = 0; k < 4; k++)
	{
		int newX = i + dx[k];
		int newY = j + dy[k];
		if (isValid(newX, newY) and vis[newX][newY] == 1)return true;
		if (isValid(newX, newY)  and  matrix[newX][newY] == c)
		{
			cout << newX << " " << newY << endl;

			dfs(newX, newY, vis, matrix, c);
		}
	}

	return false;
}


void solve()
{
	cin >> n >> m;

	vector<string> matrix(n);
	for (auto &it : matrix)cin >> it;


	for (char c = 'A'; c <= 'Z'; c++)
	{
		vector<vector<int>> vis(n, vector<int>(m, 0));

		if (dfs(0, 0, vis, matrix, c))
		{
			YES;
			return;
		}
		debug(vis);
		break;
	}
	NO;



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