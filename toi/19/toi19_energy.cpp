/*
    author  : PakinDioxide
    created : 18/03/2025 13:19
    task    : toi19_energy
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, k, d;
    cin >> n >> k >> d;
    ll a[n], mod = 1e9+7;
    for (auto &e : a) cin >> e;
    ll dp[n][n][k], p[n+1];
    memset(dp, 0, sizeof(dp));
    p[0] = 0;
    for (int i = 0; i < n; i++) p[i+1] = p[i] + a[i];
    for (int h = 0; h < k; h++) {
        for (int l = 0; l <= n; l++) {
            for (int i = 0; i+l < n; i++) {
                int j = i+l;
                if (h == 0) {dp[i][j][h] = 1; continue;}
                for (int k = i; k < j; k++) if (abs((p[k+1] - p[i]) - (p[j+1] - p[k+1])) <= d) dp[i][j][h] += (dp[i][k][h-1] * dp[k+1][j][h-1]) % mod, dp[i][j][h] %= mod;
            }
        }
    }
    cout << dp[0][n-1][k-1] << '\n';
}