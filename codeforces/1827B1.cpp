#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    int a[n]; for (auto &e : a) cin >> e;
    ll ans = 0;
    int MX[n][n], MN[n][n];
    for (int i = 0; i < n; i++) {
        MX[i][i] = MN[i][i] = a[i];
        for (int j = i+1; j < n; j++) MX[i][j] = max(MX[i][j-1], a[j]), MN[i][j] = min(MN[i][j-1], a[j]);
    }
    for (int i = 0; i < n; i++) {
        vector <int> rc;
        int mx = a[i], dp[n];
        dp[i] = 0;
        rc.emplace_back(i-1);
        rc.emplace_back(i);
        for (int j = i+1; j < n; j++) {
            mx = max(mx, a[j]);
            if (a[j] == mx) dp[j] = dp[j-1];
            else {
                while (rc.size() > 1 && MX[i][rc.back()] > MN[rc.back()+1][j]) rc.pop_back();
                dp[j] = (rc.back() >= i ? dp[rc.back()] : 0) + max(0, (j - (rc.back() + 1)));
            }
            rc.emplace_back(j);
            ans += dp[j];
            // cout << i << ' ' << j << ' ' << dp[i] << '\n';
            // if (i == 0 && j == 9) cout << dp[j] << '\n';
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

