#include <bits/stdc++.h>

using namespace std;

int n, m, dep[200005];
vector <int> adj[200005], path[200005];

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dep[v] = dep[u]+1;
        dfs(v, u);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0, u, v; i < n-1; i++) cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
    for (int i = 0, u, v; i < m; i++) cin >> u >> v, path[v].push_back(u), path[u].push_back(v);
}