/*
    author  : PakinDioxide
    created : 16/07/2025 21:34
    task    : 2018_Opn_P_3
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 5e4+5, mxL = 20;

int n, m, dep[mxN], up[mxL][mxN], ans[mxN];
vector <pair <int, int>> adj[mxN];
set <pair <int, int>> add[mxN], del[mxN];

void dfs(int u, int p) {
    for (auto [v, idx] : adj[u]) if (v != p) {
        dep[v] = dep[u]+1;
        up[0][v] = u;
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

void dfs2(int u, int p) {
    for (auto [v, idx] : adj[u]) if (v != p) {
        dfs2(v, u);
        ans[idx] = (add[v].size() ? (*add[v].begin()).first : -1);
        if (add[u].size() < add[v].size()) swap(add[u], add[v]);
        for (auto &e : add[v]) add[u].emplace(e);
    }
    for (auto &e : del[u]) add[u].erase(add[u].find(e));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("disrupt.in", "r", stdin);
    freopen("disrupt.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i < n; i++) { int u, v; cin >> u >> v; adj[u].emplace_back(v, i), adj[v].emplace_back(u, i); }
    dfs(1, 1);
    for (int c = 1; c < mxL; c++) for (int i = 1; i <= n; i++) up[c][i] = up[c-1][up[c-1][i]];
    while (m--) {
        int x, y, w; cin >> x >> y >> w;
        int LCA = lca(x, y);
        add[x].emplace(w, m);
        add[y].emplace(w, m);
        del[LCA].emplace(w, m);
    }
    dfs2(1, 1);
    for (int i = 1; i < n; i++) cout << ans[i] << '\n';
}