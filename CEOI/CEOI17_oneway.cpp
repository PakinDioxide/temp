#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n, m, dep[mxN], cnt[mxN], PU[mxN], PD[mxN], id[mxN], ans[mxN], it = 0, up[30][mxN], vis[mxN];
vector <pair <int, int>> adj[mxN], adt[mxN];

void dfs(int u, int p, int ii) {
    id[u] = ++it;
    dep[u] = dep[p]+1;
    up[0][u] = p;
    for (auto [v, idx] : adj[u]) if (abs(idx) != abs(ii)) {
        if (id[v]) {
            if (id[v] > id[u]) cnt[u]--, ans[abs(idx)] = 3;
            else if (id[v] < id[u]) cnt[u]++, ans[abs(idx)] = 3;
            else if (id[v] == id[u]) ans[abs(idx)] = 3;
        } else {
            dfs(v, u, idx);
            if (cnt[v] > 0) ans[abs(idx)] = 3;
            cnt[u] += cnt[v];
            adt[u].emplace_back(v, idx);
        }
    }
    // cout << "DFS : " << u << ' ' << cnt[u] << '\n';
}

int LCA(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int k = dep[u] - dep[v];
    for (int i = 0; i < 30; i++) if (k & (1 << i)) u = up[i][u];
    if (u == v) return u;
    for (int i = 29; i >= 0; i--) if (up[i][u] != up[i][v]) u = up[i][u], v = up[i][v];
    return up[0][u];
}

set <int> U[mxN], D[mxN];

void dfs2(int u, int p) {
    vis[u] = 1;
    for (auto [v, idx] : adt[u]) {
        dfs2(v, u);
        if (ans[abs(idx)] == 0 && U[v].size()) ans[abs(idx)] = (idx > 0 ? 1 : 2);
        if (ans[abs(idx)] == 0 && D[v].size()) ans[abs(idx)] = (idx > 0 ? 2 : 1);
        // if (ans[abs(idx)] != 3 && U[v].size() && D[v].size()) cerr << "BRUH " << u << '\n';;
        if (U[v].size() > U[u].size()) swap(U[u], U[v]);
        for (auto &e : U[v]) U[u].emplace(e);
        if (D[v].size() > D[u].size()) swap(D[u], D[v]);
        for (auto &e : D[v]) D[u].emplace(e);
        U[v].clear(), D[v].clear();
    }
    if (PU[u] != dep[u]) U[u].emplace(PU[u]);
    if (PD[u] != dep[u]) D[u].emplace(PD[u]);
    if (U[u].find(dep[u]) != U[u].end()) U[u].erase(U[u].find(dep[u]));
    if (D[u].find(dep[u]) != D[u].end()) D[u].erase(D[u].find(dep[u]));
    // cout << u << " : \n";
    // for (auto &e : U[u]) cout << e << ' '; cout << '\n';
    // for (auto &e : D[u]) cout << e << ' '; cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    assert(n == 1);
    for (int i = 1, u, v; i <= m; i++) cin >> u >> v, adj[u].emplace_back(v, i), adj[v].emplace_back(u, -i);
    // dfs(1, 0, INT_MIN);
    for (int i = 1; i <= n; i++) if (!id[i]) dfs(i, 0, INT_MIN);
    // for (int i = 1; i <= m; i++) cout << ans[i] << ' '; cout << '\n';
    int q; cin >> q;
    for (int i = 1; i <= n; i++) PU[i] = PD[i] = dep[i];
    for (int c = 1; c < 30; c++) for (int i = 1; i <= n; i++) up[c][i] = up[c-1][up[c-1][i]];
    while (q--) {
        int u, v; cin >> u >> v;
        int lca = LCA(u, v);
        // cout << u << ' ' << v << ' ' << lca << '\n';
        PU[u] = min(PU[u], dep[lca]);
        PD[v] = min(PD[v], dep[lca]);
    }
    // for (int i = 1; i <= n; i++) cout << PU[i] << ' ' << PD[i] << '\n';
    // dfs2(1, 0);
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs2(i, 0);
    for (int i = 1; i <= m; i++) {
        if (ans[i] == 1) cout << 'L';
        else if (ans[i] == 2) cout << 'R';
        else cout << 'B';
    }
    cout << '\n';
}

