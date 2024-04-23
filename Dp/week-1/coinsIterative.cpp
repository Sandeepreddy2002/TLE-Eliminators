#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	vector<double> v;
	int n;
	cin >> n;
	v.resize(n);
	for (auto &i : v)cin >> i;
	vector<double> curr(n + 1, 0);
	curr[0] =  1 - v[0]; curr[1] = v[0];

	for (int i = 2; i <= n; i++)
	{
		for (int j = n; j >= 0; j--)
		{
			if (j > i)continue;
			if (j == 0)
			{
				curr[j] = (1 - v[i - 1]) * curr[j];
			} else if (j == i)
			{
				curr[j] = v[i - 1] * curr[j - 1];
			} else
			{
				curr[j] =
				    v[i - 1] * curr[j - 1] + (1 - v[i - 1]) * curr[j];
			}
		}

	}
	double ans = 0;

	for (int i = (n + 1) / 2; i <= n; i++)ans += curr[i];
	cout << setprecision(10) << fixed << ans << endl;





	return 0;

}