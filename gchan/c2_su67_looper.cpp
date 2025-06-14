/*
    author  : PakinDioxide
    created : 24/03/2025 16:51
    task    : loop_travelling
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector <int> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
    }
    if (k == 1) {cout << 0 << ' ' << s << '\n'; return;}
    ll cyc[n+1];
    for (int i = 1; i <= n; i++) cyc[i] = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        queue <pair <int, int>> q;
        q.emplace(0, i);
        int vis[n+1];
        memset(vis, 0, sizeof(vis));
        while (!q.empty()) {
            auto [c, u] = q.front();
            q.pop();
            if (vis[u]) {
                if (u == i) {cyc[i] = c; break;}
                continue;
            }
            vis[u] = 1;
            for (auto v : adj[u]) q.emplace(c+1, v);
        }
    }
    ll ans = LLONG_MAX; int idx = -1;
    queue <pair <int, int>> q;
    q.emplace(0, s);
    int vis[n+1];
    memset(vis, 0, sizeof(vis));
    while (!q.empty()) {
        auto [c, u] = q.front();
        q.pop();
        if (cyc[u] < LLONG_MAX) {
            if (ans > c+cyc[u]*(k-1)) ans = c+cyc[u]*(k-1), idx = u;
            else if (ans == c+cyc[u]*(k-1)) idx = min(idx, u);
        }
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto v : adj[u]) q.emplace(c+1, v);
    }
    if (idx == -1) cout << -1 << '\n';
    else cout << ans << ' ' << idx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}