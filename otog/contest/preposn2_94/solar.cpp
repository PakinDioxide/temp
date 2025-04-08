/*
    author  : PakinDioxide
    created : 27/03/2025 19:02
    task    : solar
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, q, s, e;
    cin >> n >> m >> q >> s >> e;
    vector <pair <int, ll>> adj[n+1];
    tuple <int, int, ll> E[m+1];
    for (int i = 1; i <= m; i++) {
        auto &[u, v, w] = E[i];
        cin >> u >> v >> w;
        u++, v++;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    s++, e++;
    ll dis[n+1], dis2[n+1];
    for (int i = 1; i <= n; i++) dis[i] = dis2[i] = LLONG_MAX;
    dis[s] = dis2[e] = 0;
    priority_queue <pair <ll, int>> Q;
    Q.emplace(0, s);
    while (!Q.empty()) {
        auto [w, u] = Q.top();
        w=-w;
        Q.pop();
        if (w != dis[u]) continue;
        for (auto [v, ww] : adj[u]) if (dis[v] > w+ww) Q.emplace(-(dis[v] = ww+w), v);
    }
    Q.emplace(0, e);
    while (!Q.empty()) {
        auto [w, u] = Q.top();
        w=-w;
        Q.pop();
        if (w != dis2[u]) continue;
        for (auto [v, ww] : adj[u]) if (dis2[v] > w+ww) Q.emplace(-(dis2[v] = ww+w), v);
    }
    while (q--) {
        int x;
        cin >> x;
        x++;
        auto [u, v, w] = E[x];
        cout << min(dis[u] + w + dis2[v], dis2[u] + w + dis[v]) << '\n';
    }
}