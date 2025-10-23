/*
    author  : 
    created : 14/07/2025
    task    : 1687_2
*/
#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5+5;

int n, q, dp[30][mxN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 2; i <= n; i++) cin >> dp[0][i];
    for (int c = 1; c < 30; c++) for (int i = 1; i <= n; i++) dp[c][i] = dp[c-1][dp[c-1][i]];
    while (q--) {
        int u, x; cin >> u >> x;
        for (int i = 0; i < 30; i++) if (x & (1 << i)) u = dp[i][u];
        cout << (u > 0 ? u : -1) << '\n';
    }
}