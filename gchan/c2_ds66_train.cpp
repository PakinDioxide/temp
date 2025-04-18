#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    int idk[n+1][n+1];
    memset(idk, 0, sizeof(idk));
    vector <pair <int, int>> adjt[n+1], adjc[n+1], adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjt[u].emplace_back(v, 10*abs(v-u));
        adjt[v].emplace_back(u, 10*abs(v-u));
        idk[u][v] = idk[v][u] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (!idk[i][j]) adjc[i].emplace_back(j, 10*abs(j-i)), adjc[j].emplace_back(i, 10*abs(j-i));
        }
    }
    if (idk[1][n]) for (int i = 0; i < n; i++) adj[i] = adjc[i];
    else for (int i = 0; i < n; i++) adj[i] = adjt[i];
    int dis[n+1], vis[n+1];
    for (int i = 0; i <= n; i++) dis[i] = INT_MAX, vis[i] = 0;
    dis[1] = 0;
    priority_queue <pair <int, int>> q;
    q.emplace(0, 1);
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : adj[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.emplace(-dis[v], v);
            }
        }
    }
    cout << (dis[n] == INT_MAX ? -1 : dis[n]) << '\n';
}