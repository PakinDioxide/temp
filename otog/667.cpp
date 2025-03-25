/*
    author  : PakinDioxide
    created : 19/03/2025 21:56
    task    : 667
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector <pair <int, int>> adj[n+1];
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    int dis[n], vis[n];
    for (int i = 0; i < n; i++) dis[i] = INT_MAX, vis[i] = 0;
    priority_queue <pair <int, int>> q;
    q.emplace(0, s);
    dis[s] = 0;
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
    cout << dis[t] << '\n';
}