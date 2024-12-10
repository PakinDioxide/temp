#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    long long n, m;
    cin >> n >> m;
    vector <pair <long long, long long>> adj[n];
    for (long long i = 0; i < m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].emplace_back(v, w);
    }
    long long dis[n][2], vis[n];
    for (long long i = 0; i < n; i++) {dis[i][0] = dis[i][1] = LLONG_MAX; vis[i] = 0;}
    dis[0][0] = dis[0][1] = 0;
    priority_queue <pair <long long, long long>> q;
    q.emplace(0, 0);
    while (!q.empty()) {
        long long u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : adj[u]) {
            if (dis[u][0] + w < dis[v][0] || dis[u][0] + w/2 < dis[v][1] || dis[u][1] + w < dis[v][1]) {
                dis[v][0] = min(dis[v][0], dis[u][0] + w);
                dis[v][1] = min({dis[v][1], dis[u][0] + w/2, dis[u][1] + w});
                if (dis[v][1] == dis[u][0] + w/2 || dis[v][1] == dis[u][1] + w) vis[u] = 0;
                q.emplace(-min(dis[v][0], dis[v][1]), v);
            }
        }
    }
    cout << min(dis[n-1][0], dis[n-1][1]);
}