/*
    author  : 
    created : 19/07/2025 23:28
    task    : 2122D
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector <int> adj[n+1];
    for (int i = 0, u, v; i < m; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    ll dis[n+1], t = 0;
    for (int i = 1; i <= n; i++) dis[i] = INT_MAX;
    dis[1] = 0;
    while (1) {
        ll dist[n+1]; for (int i = 1; i <= n; i++) dist[i] = dis[i] + 1;
        for (int u = 1; u <= n; u++) {
            int v = adj[u][t % ((int) (adj[u].size()))];
            dist[v] = min(dist[v], dis[u]);
        }
        for (int i = 1; i <= n; i++) dis[i] = dist[i];
        t++;
        if (dis[n] < INT_MAX) { cout << t << ' ' << dis[n] << '\n'; return; }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}