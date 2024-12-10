#include <bits/stdc++.h>

using namespace std;

int n, q, dp[200005][40];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> dp[i][0];
    for (int k = 1; k <= 32; k++) for (int i = 1; i <= n; i++) dp[i][k] = dp[dp[i][k-1]][k-1];
    while (q--) {
        int u, k;
        cin >> u >> k;
        for (int i = 0; i < 32; i++) if (k & (1 << i)) u = dp[u][i];
        cout << u << '\n';
    }
}
