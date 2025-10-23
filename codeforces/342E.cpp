/*
    author  : 
    created : 20/08/2025 19:43
    task    : 342E
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int n, q, sz[mxN], vis[mxN], par[mxN], dis[mxN], up[20][mxN], dep[mxN];
vector <int> adj[mxN];
vector <pair <int, int>> Q;

void dfs(int u, int p) {
    up[0][u] = p;
    for (auto v : adj[u]) if (v != p) dep[v] = dep[u] + 1, dfs(v, u);
}

int fsz(int u, int p) {
    sz[u] = 1;
    for (auto v : adj[u]) if (v != p && !vis[v]) sz[u] += fsz(v, u);
    return sz[u];
}

int ct(int u, int p, int tsz) {
    for (auto v : adj[u]) if (v != p && !vis[v]) if (sz[v] * 2 > tsz) return ct(v, u, tsz);
    return u;
}

void ctd(int u, int p) {
    int C = ct(u, u, fsz(u, u));
    vis[C] = 1;
    if (p == -1) p = C;
    par[C] = p;
    for (auto v : adj[C]) if (!vis[v]) ctd(v, C);
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    int k = dep[x] - dep[y];
    for (int i = 0; i < 20; i++) if (k & (1 << i)) x = up[i][x];
    if (x == y) return x;
    for (int i = 19; i >= 0; i--) if (up[i][x] != up[i][y]) x = up[i][x], y = up[i][y];
    return up[0][x];
}

int fdis(int x, int y) {
    int LCA = lca(x, y);
    return dep[x] + dep[y] - 2*dep[LCA];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q; Q.resize(q+1);
    for (int i = 1; i <= n; i++) dis[i] = INT_MAX;
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    Q[0] = {1, 1};
    for (int i = 1; i <= q; i++) cin >> Q[i].first >> Q[i].second;
    dfs(1, 1);
    ctd(1, -1);
    for (int c = 1; c < 20; c++) for (int i = 1; i <= n; i++) up[c][i] = up[c-1][up[c-1][i]];
    for (auto &[t, x] : Q) {
        int u = x;
        if (t == 1) {
            while (1) {
                dis[x] = min(fdis(u, x), dis[x]);
                if (x == par[x]) break; x = par[x];
            }
        } else {
            int mn = dis[x], c = 0;
            while (1) {
                if (dis[x] < INT_MAX) mn = min(mn, dis[x] + fdis(u, x));
                if (x == par[x]) break; x = par[x];
            }
            cout << mn << '\n';
        }
    }
}