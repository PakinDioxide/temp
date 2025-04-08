/*
    author  : PakinDioxide
    created : 06/04/2025 17:28
    task    : abc197_f
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <pair <int, char>> adj[n];
    pair <int, int> E[m];
    for (int i = 0; i < m; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        u--, v--;
        if (u > v) swap(u, v);
        E[i] = make_pair(u, v);
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }
    int dis[n][n];
    queue <tuple <int, int, int>> q;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dis[i][j] = INT_MAX;
    for (int i = 0; i < n; i++) q.emplace(0, i, i), dis[i][i] = 0;
    for (auto [u, v] : E) if (dis[u][v] == INT_MAX) q.emplace(1, u, v), dis[u][v] = dis[v][u] = 1;
    while (!q.empty()) {
        auto [w, u, v] = q.front();
        q.pop();
        if (dis[u][v] != w) continue;
        for (auto [uu, k1]  : adj[u]) for (auto [vv, k2] : adj[v]) {
            if (k1 != k2) continue;
            if (dis[uu][vv] > w+2) q.emplace(dis[uu][vv] = dis[vv][uu] = w+2, uu, vv);
        }
    }
    cout << (dis[0][n-1] == INT_MAX ? -1 : dis[0][n-1]) << '\n';
}