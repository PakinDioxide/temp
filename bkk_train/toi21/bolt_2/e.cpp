/*
    author  : PakinDioxide
    created : 27/04/2025 14:20
    task    : e
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 205, mxM = 1e6+5;

pair <int, int> a[mxN];
ll dp[mxM];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a, a+n);
    for (int i = 0; i <= m; i++) dp[i] = LLONG_MIN;
    dp[0] = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll x = a[i].first, y = a[i].second;
        for (int j = m; j >= x; j--) {
            if ((j-x)%2 != 0) continue;
            dp[j] = max(dp[j], dp[(j-x)/2] + y);
            ans = max(ans, dp[j]);
        }
        // for (int i = 0; i <= m; i++) cout << max(-1LL, dp[i]) << ' ';
        // cout << '\n';
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}