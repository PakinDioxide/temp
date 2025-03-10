// BRUTEFORCE
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <int> adj[100005];
map <int, int> c[100005];
int vis[100005];

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int v : adj[u]) {
        dfs(v);
        c[u][v] = max(c[u][v], 2);
        for (auto [V, w] : c[v]) c[u][V] = max(c[u][V], w+1);
    }
    c[u][u] = 1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0, u, v; i < m; i++) cin >> u >> v, adj[min(u, v)].push_back(max(u, v));
    dfs(1);
    while (q--) {
        int t, y, ans = -1;
        cin >> t >> y;
        map <int, int> x;
        for (int i = 0, k; i < y; i++) cin >> k, x[k] = 1;
        for (int i = 1; i <= t; i++) if (!x[i]) ans = max(ans, c[i][t]-1);
        cout << ans << '\n';
    }
}