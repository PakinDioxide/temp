/*
    author  : PakinDioxide
    created : 17/03/2025 20:05
    task    : 07
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    int co[n], ci[n];
    for (auto &e : ci) cin >> e;
    for (auto &e : co) cin >> e;
    vector <pair <int, int>> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v, co[u] + ci[v]);
    }
    int dis[n], vis[n];
    for (int i = 0; i < n; i++) dis[i] = INT_MAX, vis[i] = 0;
    dis[0] = 0;
    priority_queue <pair <int, int>> q;
    q.emplace(0, 0);
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
    for (int i = 0; i < n; i++) cout << (dis[i] == INT_MAX ? -1 : dis[i]) << ' ';
    cout << '\n';
}