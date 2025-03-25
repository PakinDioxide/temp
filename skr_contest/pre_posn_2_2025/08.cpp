/*
    author  : PakinDioxide
    created : 17/03/2025 20:11
    task    : 08
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 1e8+7;
ll dp[1000005][3];
ll p[1000005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    dp[0][0] = dp[0][1] = dp[0][2] = 1, p[0] = 2;
    for (int i = 1; i < n; i++) {
        dp[i][0] = ((dp[i-1][0] + dp[i-1][1]) % mod) + dp[i-1][2];
        dp[i][1] = ((dp[i-1][1] + (i >= 2 ? dp[i-2][1] : 0)) % mod) + (i >= 3 ? p[i-3] : 0) + 1;
        dp[i][2] = ((dp[i-1][2] + (i >= 2 ? dp[i-2][2] : 0)) % mod) + (i >= 3 ? p[i-3] : 0) + 1;
        dp[i][0] %= mod, dp[i][1] %= mod, dp[i][2] %= mod;
        p[i] = ((p[i-1] + dp[i][1]) % mod + dp[i][2]) % mod, p[i] %= mod;
    }
    ll ans = 0;
    for (int j = 0; j < 3; j++) ans += dp[n-1][j];
    cout << ans % mod << '\n';
}