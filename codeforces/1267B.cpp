#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int n, m, x, y, ok[mxN];
vector <int> adj[mxN];

void bfs(int st, int k, int ex) {
    queue <int> q; 
    int vis[n+5]; memset(vis, 0, sizeof(vis));
    q.emplace(st);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ok[u] += k;
        for (auto v : adj[u]) if (!vis[v] && v != ex) vis[v] = 1, q.emplace(v);
    }
}

void solve() {
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++) ok[i] = 0, adj[i].clear();
    for (int i = 0, u, v; i < m; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    bfs(x, 1, y);
    bfs(y, 2, x);
    ll p = 0, q = 0;
    for (int i = 1; i <= n; i++) if (i != x && i != y) {
        if (ok[i] == 1) p++;
        else if (ok[i] == 2) q++;
        else if (ok[i] == 0) p++, q++;
    }
    cout << p*q << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}