/*
    author  : PakinDioxide
    created : 24/03/2025 14:56
    task    : 1671
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <pair <int, int>> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    priority_queue <pair <ll, int>> q;
    ll dis[n+1];
    for (int i = 1; i <= n; i++) dis[i] = LLONG_MAX;
    dis[1] = 0;
    q.emplace(0, 1);
    while (!q.empty()) {
        auto [w, u] = q.top();
        q.pop();
        w=-w;
        if (dis[u] != w) continue;
        for (auto [v, ww] : adj[u]) {
            if (dis[v] > ww+w) q.emplace(-(dis[v] = ww+w), v);
        }
    }
    for (int i = 1; i <= n; i++) cout << dis[i] << ' ';
    cout << '\n';
}