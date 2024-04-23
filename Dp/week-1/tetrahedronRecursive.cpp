#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int f(int i, char c)
{
	if (i == n and c != 'D')return 1;
	else if (i == n and c == 'D')return 0;
	int ans = 0;
	if (c != 'A')ans +=  f(i + 1, 'A');
	if (c != 'B')ans +=  f(i + 1, 'B');
	if (c != 'C')ans +=  f(i + 1, 'C');
	if (c != 'D')ans +=  f(i + 1, 'D');
	return ans;
}

signed main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	n--;
	cout << f(0, 'D') << endl;
	return 0;

}