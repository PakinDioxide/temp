/*
    author  : PakinDioxide
    created : 24/05/2025 22:23
    task    : 2110D
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

void solve() {
    int n, m; cin >> n >> m;
    ll b[n+1], mn[n+1], mx[n+1];
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector <pair <int, ll>> adj[n+1], adjt[n+1];
    for (int i = 0; i < m; i++) {int u, v; ll w; cin >> u >> v >> w; adj[v].emplace_back(u, w); adjt[u].emplace_back(v, w); }
    mn[1] = 0, mx[1] = b[1];
    for (int u = 2; u <= n; u++) {
        mn[u] = LLONG_MAX, mx[u] = LLONG_MIN;
        for (auto [v, w] : adj[u]) if (mn[v] != LLONG_MAX) {
            mn[u] = min(mn[u], max(mn[v], w));
            mx[u] = max(mx[u], mx[v]+b[u]);
        }
    }
    // cout << "MX ";
    // for (int i = 1; i <= n; i++) cout << mx[i] << ' ';
    // cout << '\n';
    // cout << (mn[n] == LLONG_MAX ? -1 : mn[n]) << '\n';
    ll l = 0, r = mx[n], ans = -1;
    while (l <= r) {
        ll x = l + (r-l)/2, dis[n+1];
        for (auto &e : dis) e = LLONG_MIN;
        dis[1] = min(b[1], x);
        for (int u = 2; u <= n; u++) {
            for (auto [v, ww] : adj[u]) if (dis[v] >= ww) dis[u] = max(dis[u], min(x, dis[v] + b[u]));
        }
        // priority_queue <pair <ll, int>> q;
        // q.emplace(0, 1); dis[1] = 0;
        // while (!q.empty()) {
        //     auto [w, u] = q.top(); q.pop();
        //     if (dis[u] != w) continue;
        //     w = min(x, w+b[u]);
        //     for (auto [v, ww] : adjt[u]) if (dis[v] < w && w >= ww) q.emplace(dis[v] = w, v);
        // }
        // if (x == 3) {
        //     for (int i = 1; i <= n; i++) cout << dis[i] << ' ';
        //     cout << '\n';
        // }
        if (dis[n] > LLONG_MIN) r = x-1, ans = x;
        else l = x+1;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}