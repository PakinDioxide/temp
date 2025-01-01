#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    ll dis[n+1][k+1], vis[n+1];
    vector <pair <int, int>> adj[n+1];
    while (m--) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    for (int i = 1; i <= n; i++) for (int j = 0; j <= k; j++) dis[i][j] = LLONG_MAX, vis[i] = 0;
    dis[1][0] = 0;
    priority_queue <pair <int, int>> q;
    q.emplace(0, 1);
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        for (auto [v, w] : adj[u]) {
            if (w < -100) {
                for (int i = 0; i <= k-1; i++) {
                    if (dis[v][i+1] > dis[u][i]) {
                        dis[v][i+1] = dis[u][i];
                        q.emplace(-dis[v][i+1], v);
                        vis[v] = 0;
                    }
                }
            } else {
                for (int i = 0; i <= k; i++) {
                    if (dis[u][i] == LLONG_MAX) continue;
                    if (dis[v][i] > dis[u][i] + max(w, 0)) {
                        dis[v][i] = dis[u][i] + max(w, 0);
                        q.emplace(-dis[v][i], v);
                        vis[v] = 0;
                    }
                }
            }
        }
    }
    ll ans = LLONG_MAX;
    for (int i = 0; i <= k; i++) ans = min(ans, dis[n][i]);
    cout << (ans == LLONG_MAX ? -1 : ans);
}