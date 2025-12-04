#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    queue <int> q;
    vector <int> adj[n+1];
    int vis[n+1]; memset(vis, 0, sizeof(vis));
    for (int i = 0, u, v; i < m; i++) cin >> u >> v, adj[u].emplace_back(v);
    function <void(int)> dfs = [&] (int u) {
        vis[u] = 1;
        for (auto v : adj[u]) if (!vis[v]) dfs(v);
        q.emplace(u);
    };
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
    bitset <(int) 5e4+1> t[n+1];
    while (!q.empty()) {
        int u = q.front(); q.pop();
        t[u][u] = 1;
        for (auto v : adj[u]) t[u] |= t[v];
    }
    for (int i = 1; i <= n; i++) cout << t[i].count() << ' '; cout << '\n';
}