#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector <int> adj[n+1];
    for (int i = 0, u, v; i < m; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    for (int x = 1; x <= n; x++) {
        if (adj[x].size() < 4) continue;
        int vis[n+1]; memset(vis, 0, sizeof(vis));
        int par[n+1]; memset(par, 0, sizeof(par));
        int vv[n+1]; memset(vv, 0, sizeof(vv));
        queue <pair <int, int>> q;
        par[x] = vis[x] = x;
        for (auto &v : adj[x]) q.emplace(v, v), vis[v] = v, par[v] = x;
        vector <pair <int, int>> E;
        int ok = 0;
        while (!q.empty()) {
            auto [u, p] = q.front();
            q.pop();
            for (auto v : adj[u]) if (v != x) {
                if (vis[v] == p) continue;
                else if (vis[v]) {
                    ok = 1;
                    E.emplace_back(v, u);
                    int t = v;
                    while (par[t] != t) E.emplace_back(t, par[t]), t = par[t];
                    t = u;
                    while (par[t] != t) E.emplace_back(t, par[t]), t = par[t];
                }
                if (ok) break;
                par[v] = u, vis[v] = p, q.emplace(v, p);
            }
            if (ok) break;
        }
        if (!ok) continue;
        int cnt = 0;
        for (auto &[x, y] : E) vv[x] = vv[y] = 1;
        for (auto &v : adj[x]) {
            if (!vv[v]) cnt++, E.emplace_back(v, x);
            if (cnt == 2) break;
        }
        cout << "YES\n";
        cout << E.size() << '\n';
        for (auto &[x, y] : E) cout << x << ' ' << y << '\n';
        return;
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}