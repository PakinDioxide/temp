/*
    author  : PakinDioxide
    created : 16/07/2025 20:12
    task    : 2015_Dec_P_1
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 5e4+5, mxL = 20;

int n, k, dep[mxN], up[mxL][mxN], dp[mxN];
vector <int> adj[mxN];

void dfs(int u, int p) {
    for (auto v : adj[u]) if (v != p) {
        up[0][v] = u;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    int k = dep[x] - dep[y];
    for (int i = 0; i < mxL; i++) if (k & (1 << i)) x = up[i][x];
    if (x == y) return x;
    for (int i = mxL - 1; i >= 0; i--) if (up[i][x] != up[i][y]) x = up[i][x], y = up[i][y];
    return up[0][x];
}

int dfs2(int u, int p) {
    int mx = 0;
    for (auto v : adj[u]) if (v != p) mx = max(mx, dfs2(v, u)), dp[u] += dp[v];
    return max(mx, dp[u]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i < n; i++) { int u, v; cin >> u >> v; adj[u].emplace_back(v), adj[v].emplace_back(u); }
    dfs(1, 1);
    for (int c = 1; c < mxL; c++) for (int i = 1; i <= n; i++) up[c][i] = up[c-1][up[c-1][i]];
    while (k--) {
        int x, y; cin >> x >> y;
        int LCA = lca(x, y);
        dp[x]++, dp[y]++, dp[LCA]--, dp[up[0][LCA]]--;
    }
    cout << dfs2(1, 1) << '\n';
}