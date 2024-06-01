#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int, int>>points;

double find_distance(int index1, int index2) {
    int x1 = points[index1].first;
    int y1 = points[index1].second;
    int x2 = points[index2].first;
    int y2 = points[index2].second;
    double distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return distance;
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; int y; cin >> x >> y;
        points.push_back({x, y});
    }
    double ans = 1e18;
    int counter = 0;
    vector<vector<double>>dp((1 << n) + 1, vector<double>(n + 1, 1e17));
    for (int i = 0; i < n; i++)dp[(1 << i)][i] = 0;
    for (int i = 2; i <= n; i++) { // i denotes the no of elements taken upto now
        // j denotes the index of the element we want to take now as ith element
        // h denotes all the possibilities of previous elements
        for (int mask = 0; mask < (1 << n); mask++) {
            int no_of_setbits = __builtin_popcountll(mask);
            if (no_of_setbits != i - 1)continue;
            for (int j = 0; j < n; j++) {
                for (int h = 0; h < n; h++) {

                    counter++;

                    if ((mask >> j) & 1)continue; // if the present element we want to include is already present in the mask we will continue;
                    if ((mask >> h) & 1) { //checking if the element we want to consider as the prev element is present in the mask

                        dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], find_distance(h, j) + dp[mask][h]);
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[(1 << n) - 1][i]);
    }

    cout << ans << endl;
    cout << counter << endl;
}

signed main() {
    int t; t = 1;
    // cin>>t;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    while (t--)solve();
}