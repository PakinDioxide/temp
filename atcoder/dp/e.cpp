#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, W;
    cin >> n >> W;
    ll dp[n+1][100005], ans = 0;
    for (int i = 0; i <= 100000; i++) dp[0][i] = INT_MAX;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        ll w, v;
        cin >> w >> v;
        for (ll j = 0; j <= 100000; j++) {
            if (j - v < 0) dp[i][j] = dp[i-1][j];
            else {
                dp[i][j] = min({dp[i-1][j-v] + w, dp[i-1][j]});
            }
            if (dp[i][j] <= W) ans = max(ans, j);
        }
    }
    cout << ans;
}