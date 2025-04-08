/*
    author  : PakinDioxide
    created : 07/04/2025 20:42
    task    : abc187_f
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int dp[1 << 20];
int adj[20];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u] |= (1 << v);
        adj[v] |= (1 << u);
    }
    for (int i = 0; i < (1 << n); i++) dp[i] = INT_MAX;
    dp[0] = 0;
    for (int i = 0; i < (1 << n); i++) {
        if (dp[i] == INT_MAX) continue;
        int k = (1 << n) - 1;
        for (int j = 0; j < n; j++) if (i & (1 << j)) k &= adj[j];
        for (int j = 0; j < n; j++) if (k & (1 << j)) dp[i | (1 << j)] = 1;
    }
    for (int i = 1; i < (1 << n); i++) {
        for (int j = i; j > 0; j = (j-1) & i) {
            int k = i^j;
            dp[i] = min(dp[i], dp[j] + dp[k]);
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
}