/*
    author  : 
    created : 14/07/2025
    task    : 1687_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5, mxL = 30;

int n, q, dp[mxL][mxN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> dp[0][i];
    for (int c = 1; c < mxL; c++) for (int i = 1; i <= n; i++) dp[c][i] = dp[c-1][dp[c-1][i]];
    while (q--) {
        int u, k; cin >> u >> k;
        for (int i = 0; i < mxL; i++) if (k & (1 << i)) u = dp[i][u];
        cout << u << '\n';
    }
}