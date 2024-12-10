#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll ans = 0, siz;

void solve() {
    int n;
    scanf("%d", &n);
    ll a[n], dp[n][n], sz[n][n];
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]), dp[i][i] = 1, sz[i][i] = 1;
    for (int l = 1; l < n; l++) {
        for (int i = 0; i+l < n; i++) {
            int j = i+l;
            dp[i][j] = LLONG_MAX;
            sz[i][j] = 1;
            for (int k = i; k < j; k++) {
                if (dp[i][j] > dp[i][k] + dp[k+1][j]) dp[i][j] = dp[i][k] + dp[k+1][j], sz[i][j] = sz[i][j];
                else if (dp[i][j] == dp[i][k] + dp[k+1][j]) sz[i][j] = min(sz[i][j], sz[])
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (j >= i) printf("%lld ", dp[i][j]); else printf("  ");
        printf("\n");
    }
    ans = max(ans, dp[0][n-1]);
    printf("%lld\n", dp[0][n-1]);
}

int main() {
    int q;
    scanf("%d %lld", &q, &siz);
    while (q--) solve();
    printf("%lld", ans);
}