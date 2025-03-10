#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <pair <int, ll>> adj[n+5];
    while (m--) {int u, v; ll w; cin >> u >> v >> w; adj[u].emplace_back(v, w);}
    ll dis[n+5], vis[n+5];
    for (int i = 1; i <= n; i++) vis[i] = 0, dis[i] = LLONG_MAX;
    dis[1] = 0;
    priority_queue <pair <ll, int>> q;
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
    for (int i = 1; i <= n; i++) cout << dis[i] << ' ';
    cout << '\n';
}