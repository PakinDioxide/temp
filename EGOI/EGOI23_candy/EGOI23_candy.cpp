#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, f; cin >> n >> f; ll t; cin >> t;
    ll a[n+1]; for (int i = 1; i <= n; i++) cin >> a[i];
    map <int, ll> dp[n+1];
    dp[0][0] = 0;
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        for (int k = min(i, f); k > 0; k--) {
            for (auto &[x, y] : dp[k-1]) {
                if (y+a[i] >= t) ans = min(ans, x+i-k);
                else dp[k][x+i-k] = max(dp[k][x+i-k], y+a[i]);
            }
        }
    }
    // int ans = INT_MAX;
    // for (auto &[x, y] : dp[f]) if (x >= t) ans = min(y, ans);
    if (ans == INT_MAX) cout << "NO\n";
    else cout << ans << '\n';
}

