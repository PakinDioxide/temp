#include <bits/stdc++.h>

using namespace std;

int n, m, vis[2505], vis2[2505];
long long dis[2505];
vector <int> adj[2505], adj2[2505];
vector <tuple <int, int, int>> edge;

void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) if (!vis[v]) dfs(v);
}
void dfs2(int u) {
    vis2[u] = 1;
    for (int v : adj2[u]) if (!vis2[v]) dfs2(v);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj2[v].push_back(u);
        edge.emplace_back(u, v, -w);
    }
    dfs(1); dfs2(n);
    for (int i = 1; i <= n; i++) dis[i] = LLONG_MAX;
    dis[1] = 0;
    int cnt = 0, neg = 0, cng = 0;
    do {
        cnt++;
        cng = 0;
        for (auto [u, v, w] : edge) {
            if (!vis[u] || !vis2[v]) continue;
            if (dis[u] != LLONG_MAX && dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                cng = 1;
            }
        }
        if (cnt > n && cng) {
            neg = 1;
            break;
        }
    } while (cng);
    if (neg) cout << -1;
    else cout << -dis[n];
}