#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    int imp[k];
    for (auto &e : imp) cin >> e;
    vector <pair <int, int>> adj[n+1];
    while (m--) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    int vis[n+1], en[n+1];
    ll ans = 0;
    memset(vis, 0, sizeof(vis));
    memset(en, 0, sizeof(en));
    priority_queue <tuple <ll, int, int, int>> q;
    for (auto e : imp) q.emplace(0, e, e, e);
    while (!q.empty()) {
        auto [w, u, pp, p] = q.top(); w=-w;
        q.pop();
        if (en[p]) continue;
        // cout <<'k' << w << ' ' << u << ' ' << p << '\n';
        ans += w;
        if (vis[u]) {en[p] = 1; continue;}
        vis[u] = 1;
        for (auto [v, ww] : adj[u]) {
            if (v == pp) continue;
            q.emplace(-ww, v, u, p);
        }
    }
    cout << ans << '\n';
}