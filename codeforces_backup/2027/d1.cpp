#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n+1], b[m+1];
    a[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    pair <int, int> dp[m+1][n+1];
    for (int i = 0; i <= m; i++) dp[i][0].first = dp[i][0].second = 0;
    for (int i = 0; i <= n; i++) dp[0][i].first = dp[0][i].second = 0;
    int mi = LLONG_MAX;
    for (int i = 1; i <= m; i++) {
        int re = 0;
        for (int j = 1; j <= n; j++) {
            dp[i][j].first = dp[i][j].second = -1;
            if (dp[i][j-1].second + a[j] <= b[i]) dp[i][j].first = m-i + re, dp[i][j].second = dp[i][j-1].second + a[j];
            else if (a[j] <= b[i]) re += dp[i][j-1].first, dp[i][j].first = m-i + re, dp[i][j].second = a[j];
            if (a[j] <= b[i]) {
                if (dp[i-1][j-1].first != -1 && (dp[i-1][j-1].first + m-i <= dp[i][j].first || dp[i][j].first == -1) && dp[i-1][j-1].first + m-i <= b[i]) re = dp[i-1][j-1].first, dp[i][j].first = m-i + re, dp[i][j].second = a[j];
            }
            if (dp[i][j].first == -1) break;
            if (j == n) mi = min(mi, dp[i][j].first);
        }
    }
    cout << (mi == LLONG_MAX ? -1 : mi) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}