/*
    author  : PakinDioxide
    created : 14/04/2025 16:38
    task    : 2019_Opn_G_1
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 405;
ll n, k, a[mxN], p[mxN], dp[mxN][mxN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], p[i] = p[i-1] + a[i];
    for (int i = 0; i <= k+1; i++) for (int j = 0; j <= n; j++) dp[i][j] = LLONG_MAX;
    dp[0][0] = 0;
    ll ans = LLONG_MAX;
    for (int o = 1; o <= k+1; o++) {
        for (int i = 1; i <= n; i++) {
            ll mx = 0;
            for (int j = i; j > 0; j--) mx = max(mx, a[j]), dp[o][i] = min(dp[o][i], (dp[o-1][j-1] == LLONG_MAX ? LLONG_MAX : dp[o-1][j-1] + mx*(i-j+1) - (p[i] - p[j-1])));
            if (i == n) ans = min(ans, dp[o][i]);
        }
    }
    cout << ans << '\n';
}

/*
it is o(n^3) : o(kn^2)
*/