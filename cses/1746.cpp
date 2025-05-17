/*
    author  : PakinDioxide
    created : 29/04/2025 19:21
    task    : 1746
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    ll dp[n][m+2], a[n], mod = 1e9+7, ans = 0;
    memset(dp, 0, sizeof(dp));
    for (auto &e : a) cin >> e;
    if (a[0] == 0) for (int i = 1; i <= m; i++) dp[0][i] = 1;
    else dp[0][a[0]] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != 0) dp[i][a[i]] = dp[i-1][a[i]-1] + dp[i-1][a[i]] + dp[i-1][a[i]+1], dp[i][a[i]] %= mod;
        else for (int j = 1; j <= m; j++) dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1], dp[i][j] %= mod;
    }
    for (int i = 1; i <= m; i++) ans += dp[n-1][i], ans %= mod;
    cout << ans << '\n';
}