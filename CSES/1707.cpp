/*
    author  : PakinDioxide
    created : 25/03/2025 00:34
    task    : 1707
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> adj[n+1];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int mn = INT_MAX;
    for (int i = 1; i < n; i++) {
        queue <tuple <int, int, int>> q;
        q.emplace(0, i, i);
        int vis[n+1], dis[n+1];
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) dis[i] = INT_MAX;
        while (!q.empty()) {
            auto [c, u, p] = q.front();
            q.pop();
            if (vis[u]) {
                mn = min(mn, dis[u] + c);
                continue;
            }
            vis[u] = 1;
            dis[u] = c;
            for (auto v : adj[u]) if (v != p) q.emplace(c+1, v, u);
        }
    }
    cout << (mn == INT_MAX ? -1 : mn) << '\n';
}