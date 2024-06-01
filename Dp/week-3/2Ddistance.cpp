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

vector<pair<double, double>> points;
int n;

double dist(int i, int j) {
    double x1 = points[i].first, x2 = points[j].first;
    double y1 = points[i].second, y2 = points[j].second;
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double f(int last, int mask, vector<vector<double>> &dp)
{
    if (mask == (1 << n) - 1)return 0;
    double ans = 1e6;
    if (dp[last][mask] != -1)return dp[last][mask];
    for (int i = 0; i < n; i++)
    {
        if ((mask >> i) & 1 == 1)continue;
        ans = min(ans, dist(last, i) + f(i, mask | (1 << i), dp));
    }

    return dp[last][mask] = ans;
}



void solve()
{
    cin >> n;
    points.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].first >> points[i].second;
    }
    vector<vector<double>> dp(n + 1, vector<double> ((1 << n), -1));

    double ans = 1e10;
    for (int i = 0;  i < n; i++)
    {
        ans = min(ans, f(i, (1 << i), dp));
    }
    cout << ans << endl;
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