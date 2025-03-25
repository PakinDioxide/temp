/*
    author  : PakinDioxide
    created : 22/03/2025 21:22
    task    : bulb
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, p, k;
    cin >> n >> p >> k;
    ll dp[2][p+1][k+1], mod = 1e9+7;
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= p; j++) for (int l = 0; l < k; l++) dp[!(i&1)][j][l] = 0;
        for (int j = 0; j <= p; j++) {
            for (int l = 0; l < k; l++) {
               if (j < p && l < k-1) dp[!(i&1)][j+1][l+1] += dp[i&1][j][l], dp[!(i&1)][j+1][l+1] %= mod;               ;
               dp[!(i&1)][j][0] += dp[i&1][j][l], dp[!(i&1)][j][0] %= mod;
            }
        }
    }
    ll ans = 0;
    for (int l = 0; l < k; l++) ans += dp[n&1][p][l], ans %= mod;
    cout << ans << '\n';
}