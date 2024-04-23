#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// author: Krishna Sharma

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	// total
	int n, total;
	int dp[n + 1][total + 1][total + 1];
	memset(dp, 0, sizeof(dp));
	// dp[i][j][k]
	// we are on the ith index and
	// we have given sum of the elements that alice have picked are j
	// we have given sum of the elements that bob have picked are k
	// dp[0][0][total]=1;
	for (int i = 1; i <= n; i++) {
		// i means we are on the ith index
		// we will gave this value to alice
		for (int j = a[i - 1]; j <= total; j++) {
			// dp[i][j][k]
			// j is the sum alice have at this index
			// and we have taken this index val
			// till the last index the value that alice would have is j-(a[i-1])
			dp[i][j][total - j] += dp[i - 1][j - a[i - 1]][total - (j - a[i - 1])];
		}
		//
		for (int j = a[i - 1]; j <= total; j++) {
			// dp[i][j][k]
			// j is the sum alice have at this index
			// and we have taken this index val
			// till the last index the value that alice would have is j-(a[i-1])
			dp[i][total - j][j] += dp[i - 1][total - (j - a[i - 1])][j - a[i - 1]];
		}
	}
	// dp[n][i][j] // i and j are the sum taht alice and bob could
	// this is value is 1
	int ans = INT_MAX;
	ans = min(ans, abs(i - j));
}