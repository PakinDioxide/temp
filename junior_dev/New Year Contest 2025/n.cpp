// PakinDioxide
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll par[100005], dep[100005], up[20][100005], dp[100005];
vector <pair <int, ll>> adj[100005];

int fi(int u) {
    if (u != par[u]) return par[u] = fi(par[u]);
    return u;
}

void dfs(int u, int p) {
    for (auto [v, w] : adj[u]) {
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        up[0][v] = u;
        dp[v] = dp[u] + w;
        dfs(v, u);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; ll k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) par[i] = i;
    priority_queue <tuple <ll, int, int>> edge;
    while (m--) {
        int u, v; ll w;
        cin >> u >> v >> w;
        edge.emplace(-w, u, v);
    }
    int q;
    cin >> q;
    int cnt = 0;
    while (!edge.empty() && cnt < n-1) {
        auto [w, u, v] = edge.top();
        edge.pop();
        if (fi(u) == fi(v)) continue;
        par[fi(u)] = fi(v);
        adj[u].emplace_back(v, -w);
        adj[v].emplace_back(u, -w);
        cnt++;
    }
    dep[1] = 1;
    dfs(1, 0);
    up[1][0] = 1;
    for (int i = 1; i < 20; i++) for (int j = 1; j <= n; j++) up[i][j] = up[i-1][up[i-1][j]];
    while (q--) {
        int xx, yy, x, y;
        cin >> xx >> yy;
        x = xx, y = yy;
        if (dep[x] < dep[y]) swap(x, y), swap(xx, yy);
        ll k = dep[x] - dep[y];
        for (int i = 0; i < 20; i++) if (k & (1 << i)) x = up[i][x];
        int lca = x;
        if (x != y) {
            for (int i = 19; i >= 0; i--) if (up[i][x] != up[i][y]) x = up[i][x], y = up[i][y];
            lca = up[0][x];
        }
        cout << dp[xx] + dp[yy] - 2*dp[lca] << '\n';
    }
}