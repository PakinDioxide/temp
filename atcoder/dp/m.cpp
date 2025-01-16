#include <bits/stdc++.h>
#define ll long long

ll mod = 1e9+7;

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    ll dp[n][k+2];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= k+1; i++) dp[0][i] = dp[0][i-1] + (i <= a[0]+1);
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k+1; j++) {
            dp[i][j] = dp[i-1][j] - dp[i-1][max(0, j-a[i]-1)] + dp[i][j-1];
            dp[i][j] %= mod;
        }
    }
    ll ans = dp[n-1][k+1] - dp[n-1][k];
    while (ans < 0) ans += mod;
    cout << ans << '\n';
}