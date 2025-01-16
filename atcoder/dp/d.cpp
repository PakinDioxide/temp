#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, W;
    cin >> n >> W;
    ll dp[n+1][W+5];
    memset(dp[0], 0, sizeof(dp[0]));
    for (int i = 1; i <= n; i++) {
        ll w, v;
        cin >> w >> v;
        for (int j = 0; j <= W; j++) {
            if (j - w < 0) dp[i][j] = dp[i-1][j];
            else {
                dp[i][j] = max({dp[i-1][j-w] + v, dp[i][j-1], dp[i-1][j]});
            }
        }
    }
    cout << dp[n][W];
}