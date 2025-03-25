/*
    author  : PakinDioxide
    created : 24/03/2025 15:05
    task    : 1195
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <pair <int, ll>> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    ll dis[n+1][2];
    for (int i = 1; i <= n; i++) dis[i][0] = dis[i][1] = LLONG_MAX;
    dis[1][0] = dis[1][1] = 0;
    priority_queue <tuple <ll, int, int>> q;
    q.emplace(0, 1, 0);
    while (!q.empty()) {
        auto [w, u, k] = q.top();
        q.pop();
        w=-w;
        if (dis[u][k] != w) continue;
        for (auto [v, ww] : adj[u]) {
            if (dis[v][k] > w+ww) q.emplace(-(dis[v][k] = w+ww), v, k);
            if (k == 0) if (dis[v][1] > w+ww/2) q.emplace(-(dis[v][1] = w+ww/2), v, 1);
        }
    }
    cout << min(dis[n][0], dis[n][1]) << '\n';
}