#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll dp[n+1][2];
    dp[0][0] = 0, dp[0][1] = INT_MAX;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i-1][1];
        if (i >= 2) dp[i][0] = min(dp[i][0], dp[i-2][1]);
        dp[i][1] = dp[i-1][0] + a[i];
        if (i >= 2) dp[i][1] = min(dp[i][1], dp[i-2][0] + a[i-1] + a[i]);
    }
    cout << min(dp[n][0], dp[n][1]) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t; while (t--) solve();
}