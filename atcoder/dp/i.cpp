#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    double a[n+1], dp[n+1][n+1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) dp[i][0] = dp[i-1][0] * (1.0-a[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dp[i][j] = dp[i-1][j-1] * a[i] + dp[i-1][j] * (1.0 - a[i]);
    }
    double ans = 0;
    for (int i = ceil(n/2.0); i <= n; i++) ans += dp[n][i];
    cout << setprecision(12) << ans << '\n';
}