/*
    author  : 
    created : 14/07/2025
    task    : 1687_2
*/
#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5+5;

int n, q, dp[30][mxN], dep[mxN];
vector <int> adj[mxN];

void dfs(int u) { for (auto v : adj[u]) dep[v] = dep[u]+1, dfs(v); }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 2; i <= n; i++) cin >> dp[0][i], adj[dp[0][i]].emplace_back(i);
    dp[0][1] = 1;
    for (int c = 1; c < 30; c++) for (int i = 1; i <= n; i++) dp[c][i] = dp[c-1][dp[c-1][i]];
    dfs(1);
    while (q--) {
        int u, v; cin >> u >> v;
        if (dep[u] < dep[v]) swap(u, v);
        int x = dep[u] - dep[v];
        for (int i = 0; i < 30; i++) if (x & (1 << i)) u = dp[i][u];
        if (u == v) { cout << u << '\n'; continue; }
        for (int i = 29; i >= 0; i--) if (dp[i][u] != dp[i][v]) u = dp[i][u], v = dp[i][v];
        cout << dp[0][u] << '\n';
    }
}