/*
    author  : PakinDioxide
    created : 23/03/2025 21:57
    task    : 2014E
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector <pair <int, ll>> adj[n+1];
    int h[n+1];
    memset(h, 0, sizeof(h));
    for (int i = 0; i < k; i++) {int x; cin >> x, h[x] = 1;}
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    ll dis[n+1][2], dis2[n+1][2], vis[n+1], vis2[n+1];
    priority_queue <pair <ll, int>> q;
    for (int i = 1; i <= n; i++) dis[i][0] = dis[i][1] = dis2[i][0] = dis2[i][1] = LLONG_MAX, vis[i] = vis2[i] = 0;
    q.emplace(0, 1);
    dis[1][0] = 0;
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : adj[u]) {
            int ok = 0;
            if (dis[v][0] > dis[u][0] + w) dis[v][0] = dis[u][0] + w, ok = 1, vis[v] = 0;
            if (h[u] && dis[v][1] > dis[u][0] + w/2) dis[v][1] = dis[u][0] + w/2, ok = 1, vis[v] = 0;
            if (dis[u][1] < LLONG_MAX && dis[v][1] > dis[u][1] + w/2) dis[v][1] = dis[u][1] + w/2, ok = 1, vis[v] = 0;
            if (ok) q.emplace(-min(dis[v][0], dis[v][1]), v);
        }
    }
    q.emplace(0, n);
    dis2[n][0] = 0;
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis2[u]) continue;
        vis2[u] = 1;
        for (auto [v, w] : adj[u]) {
            int ok = 0;
            if (dis2[v][0] > dis2[u][0] + w) dis2[v][0] = dis2[u][0] + w, ok = 1, vis2[v] = 0;
            if (h[u] && dis2[v][1] > dis2[u][0] + w/2) dis2[v][1] = dis2[u][0] + w/2, ok = 1, vis2[v] = 0;
            if (dis2[u][1] < LLONG_MAX && dis2[v][1] > dis2[u][1] + w/2) dis2[v][1] = dis2[u][1] + w/2, ok = 1, vis2[v] = 0;
            if (ok) q.emplace(-min(dis2[v][0], dis2[v][1]), v);
        }
    }
    ll ans = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        ll x = min(dis[i][0], dis[i][1]), y = min(dis2[i][0], dis2[i][1]);
        if (x == LLONG_MAX || y == LLONG_MAX) continue;
        ans = min(ans, max(x, y));
    }
    cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}