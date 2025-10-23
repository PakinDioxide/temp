/*
    author  : 
    created : 25/06/2025 19:29
    task    : 1136
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

vector <int> adj[mxN];
int n, q, up[25][mxN], dp[mxN], dep[mxN];

void dfs1(int u, int p) { for (auto v : adj[u]) if (v != p) up[0][v] = u, dep[v] = dep[u]+1, dfs1(v, u); }
void dfs2(int u, int p) { for (auto v : adj[u]) if (v != p) dfs2(v, u), dp[u] += dp[v]; }
int lca(int u, int v) {
    if (dep[v] > dep[u]) swap(u, v);
    int d = dep[u] - dep[v];
    for (int i = 0; i < 25; i++) if (d & (1 << i)) u = up[i][u];
    if (u == v) return u;
    for (int i = 24; i >= 0; i--) if (up[i][u] != up[i][v]) u = up[i][u], v = up[i][v];
    return up[0][u];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i < n; i++) { int u, v; cin >> u >> v; adj[u].emplace_back(v), adj[v].emplace_back(u); }
    dfs1(1, 1);
    for (int i = 1; i < 25; i++) for (int u = 1; u <= n; u++) up[i][u] = up[i-1][up[i-1][u]];
    for (int i = 0; i < q; i++) { int u, v; cin >> u >> v; dp[u]++, dp[v]++; dp[lca(u, v)]--; dp[up[0][lca(u, v)]]--; }
    dfs2(1, 1);
    for (int i = 1; i <= n; i++) cout << dp[i] << ' '; cout << '\n';
}