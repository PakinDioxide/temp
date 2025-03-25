/*
    author  : PakinDioxide
    created : 16/03/2025 18:30
    task    : D2_B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    ll dp[m+1][n+1], mod = 1e9+7, ans = 0; // dp[i][j] : current level i has j on top
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) dp[0][i] = 1; // bottom level can be anything
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            // change item
            if (j < n) dp[i][j+1] += dp[i][j], dp[i][j+1] %= mod;
            // push to next level
            dp[i+1][j] += dp[i][j], dp[i+1][j] %= mod;
            if (j < n) dp[i+1][j+1] += dp[i][j], dp[i+1][j+1] %= mod;
            ans += dp[i][j], ans %= mod;
        }
    }
    cout << ans << '\n';
}

/*
if the current is level i and has j on top
dp[i][j] -> dp[i+1][j], dp[i+1][j+1]
dp[i][j] -> dp[i][j+1]
*/