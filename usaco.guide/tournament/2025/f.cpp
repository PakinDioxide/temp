#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k, s, t;
    cin >> n >> m >> k >> s >> t;
    vector <tuple <int, int, int>> adj[n+1];
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w, 0);
        // adj[v].emplace_back(u, w, 0);
    }
    while (k--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w, 1);
        // adj[v].emplace_back(u, w, 1);
    }
    int dis[n+1][2], vis[n+1][2];
    for (int i = 1; i <= n; i++) dis[i][0] = dis[i][1] = LLONG_MAX, vis[i][0] = vis[i][1] = 0;
    dis[s][0] = dis[s][1] = 0;
    priority_queue <tuple <int, int, int>> q;
    q.emplace(0, s, 0);
    while (!q.empty()) {
        int u = get<1>(q.top()), y = get<2>(q.top());
        q.pop();
        // if (vis[u][y]) continue;
        // vis[u][y] = 1;
        for (auto [v, w, x] : adj[u]) {
            if (x && y) continue;
            if (dis[v][max(x, y)] > dis[u][y] + w) {
                dis[v][max(x, y)] = dis[u][y] + w;
                q.emplace(-dis[v][x], v, max(x, y));
            }
        }
    }
    // for (int i = 1; i <= n; i++) cout << dis[i][0] << ' ';
    // cout << '\n';
    // for (int i = 1; i <= n; i++) cout << dis[i][1] << ' ';
    // cout << '\n';
    cout << min(dis[t][0], dis[t][1]) << '\n';
}