#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    vector <int> adj[n+1];
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    vector <pair <int, int>> b;
    int lf[n+1], vis[n+1], deg[n+1], par[n+1]; memset(lf, 0, sizeof(lf)), memset(vis, 0, sizeof(vis)), memset(deg, 0, sizeof(deg));
    function <void(int, int)> dfs = [&] (int u, int p) {
        int cnt = 0, cc = 0;
        for (auto v : adj[u]) if (v != p) cnt++, dfs(v, u), cc += lf[v];
        lf[u] = !cnt;
        deg[u] = cnt;
        par[u] = p;
        if (lf[u] || u == 1) return;
        if (cc == cnt) {
            // cout << "B " << cc << ' ' << u << '\n';
            b.emplace_back(cc, u);
            for (auto v : adj[u]) if (v != p) vis[v] = 1;
        }
    };
    deg[0] = INT_MAX;
    dfs(1, 0);
    int ff = 0;
    int idx = -1;
    for (int i = 1; i <= n; i++) if (lf[i] && !vis[i]) { idx = i; break; }
    while (b.size()) {
        int x, y;
        tie(x, y) = b.back(); b.pop_back();
        for (auto v : adj[y]) if (v != par[y]) vis[v] = 1;
        if (par[y] > 1 && deg[par[y]] == 1) {
            // cout << "BRUH\n";
            deg[par[y]]--;
            lf[par[y]] = 1;
            if (par[par[y]] > 1) {
                int k = par[par[y]];
                int ok = 1, cc = 0;
                for (auto v : adj[k]) if (v != par[k]) {
                    if (deg[v] >= 1) { ok = 0; break; }
                    else if (deg[v] == 0) cc++;
                }
                if (ok && cc > 0) b.emplace_back(cc, k);//, cout << "A " << cc << ' ' << k << '\n';
            }
            // cout << x << ' ' << y << ' ' << ff << '\n';
        }
        deg[y] = -1;
        deg[par[y]]--;
        if (idx > -1) deg[idx] = -1, vis[idx] = 1, idx = -1, ff++;
        if (ff) ff = ff + x - 1;
        else ff = ff + x;
        // cout << x << ' ' << y << ' ' << ff << '\n';
    }
    for (int i = 1; i <= n; i++) if (lf[i]) ff += !vis[i];
    cout << ff << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

