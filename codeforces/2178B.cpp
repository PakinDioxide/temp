#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.size();
    ll dp[n+1][2]; memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        ll e = (s[i-1] == 's');
        if (i == 1 || i == n) dp[i][0] = INT_MAX;
        else dp[i][0] = dp[i-1][1] + e;
        dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + (e == 0);
        // cout << dp[i][0] << ' ' << dp[i][1] << '\n';
    }
    cout << dp[n][1] << '\n';
}

/*
make u not adjacent
*/

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

