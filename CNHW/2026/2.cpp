#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;
const int INF = 1e9;

int n, m, k;
vector <int> adj[mxN], adt[mxN];
vector <int> bk[mxN]; // back edge
int dep[mxN], par[mxN], vis[mxN], sz[mxN];
int it = 0, id[mxN];
int dis[20][15][mxN], mn[mxN][15];

void dfs(int u, int p) {
    par[u] = p;
    dep[u] = dep[p] + 1;
    bk[u].emplace_back(u);
    for (auto v : adt[u]) if (v != p) {
        if (!dep[v]) dfs(v, u), adj[u].emplace_back(v), adj[v].emplace_back(u);
        else if (dep[v] < dep[u]) for (int x = u; x != v; x = par[x]) bk[x].emplace_back(v);
    }
}

int fsz(int u, int p) {
    sz[u] = 1;
    id[u] = it;
    for (auto v : adj[u]) if (v != p && !vis[v]) sz[u] += fsz(v, u);
    return sz[u];
}

int ct(int u, int p, int SZ) {
    for (auto v : adj[u]) if (v != p && !vis[v] && sz[v] * 2 > SZ) return ct(v, u, SZ);
    return u;
}

void ctd(int u, int p) {
    ++it;
    u = ct(u, u, fsz(u, u));
    par[u] = p;
    dep[u] = dep[p] + 1;
    for (int i = 0; i < bk[u].size(); i++) {
        int v = bk[u][i];
        if (id[v] != it) continue;
        queue <int> q;
        q.emplace(v);
        dis[dep[u]][i][v] = 0;
        while (!q.empty()) {
            int e = q.front(); q.pop();
            for (auto E : adt[e]) if (id[E] == it && dis[dep[u]][i][E] > dis[dep[u]][i][e] + 1) dis[dep[u]][i][E] = dis[dep[u]][i][e] + 1, q.emplace(E);
        }
    }
    vis[u] = 1;
    for (auto v : adj[u]) if (!vis[v]) ctd(v, u);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0, u, v; i < m; i++) cin >> u >> v, adt[u].emplace_back(v), adt[v].emplace_back(u);
    for (int i = 0; i < 20; i++) for (int j = 0; j < 15; j++) for (int k = 1; k <= n; k++) dis[i][j][k] = INF;
    for (int i = 1; i <= n; i++) for (int j = 0; j < 15; j++) mn[i][j] = INF;
    dfs(1, 0);
    dep[0] = -1;
    ctd(1, 0);
    int q; cin >> q;
    while (q--) {
        int t, u; cin >> t >> u;
        if (t == 1) {
            for (int v = u; v != 0; v = par[v]) {
                for (int i = 0; i < bk[v].size(); i++) {
                    mn[v][i] = min(mn[v][i], dis[dep[v]][i][u]);
                }
            }
        } else {
            int ans = INF;
            for (int v = u; v != 0; v = par[v]) {
                for (int i = 0; i < bk[v].size(); i++) {
                    ans = min(ans, mn[v][i] + dis[dep[v]][i][u]);
                }
            }
            cout << ans << '\n';
        }
    }
}

