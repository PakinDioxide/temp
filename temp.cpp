/*
    author  : PakinDioxide
    created : 23/04/2025 19:04
    task    : temp
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k, s, e;
    cin >> n >> m >> k >> s >> e;
    vector <tuple <int, ll, ll>> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v; ll w, c;
        cin >> u >> v >> c >> w;
        adj[u].emplace_back(v, w, c);
        adj[v].emplace_back(u, w, c);
    }
    ll dis[n+1][k+1], ans = -1;
    memset(dis, 0, sizeof(dis));
    priority_queue <tuple <ll, ll, int>> q;
    q.emplace(0, 0, s);
    dis[s][0] = 0;
    while (!q.empty()) {
        auto [w, t, u] = q.top();
        q.pop();
        if (dis[u][t] != w) continue;
        if (u == e) ans = max(ans, w);
        for (auto [v, tt, ww] : adj[u]) if (t+tt <= k && dis[v][t+tt] < w+ww) q.emplace(dis[v][t+tt] = w+ww, t+tt, v);
    }
    if (ans == -1) cout << "Impossible\n";
    else cout << ans << '\n';
}