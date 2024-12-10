#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll n, m, s, e, k;
    cin >> n >> m >> s >> e >> k;
    vector <pair <ll, ll>> adj[n+1];
    for (int i = 1; i <= m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    ll vis[n+1], dis[n+1][2];
    for (int i = 1; i <= n; i++) vis[i] = 0, dis[i][0] = dis[i][1] = LLONG_MAX;
    dis[s][0] = dis[s][1] = 0;
    priority_queue <pair <ll, ll>> q;
    q.emplace(0, s);
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : adj[u]) {
            if (dis[v][0] > dis[u][0] + )
        }
    }
}