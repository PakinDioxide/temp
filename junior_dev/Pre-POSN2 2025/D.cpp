#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    int a[n+1]; for (int i = 1; i <= n; i++) cin >> a[i];
    vector <int> adj[n+1];
    int deg[n+1]; memset(deg, 0, sizeof(deg));
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u), deg[u]++, deg[v]++;
    queue <int> q;
    for (int i = 1; i <= n; i++) if (deg[i] == 1) q.emplace(i);
    int mx[n+1]; for (auto &e : mx) e = n;
    int vis[n+1]; memset(vis, 0, sizeof(vis));
    int dd[n+1]; memset(dd, 0, sizeof(dd));
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int v;
        for (auto e : adj[u]) if (!vis[e]) v = e;
        vis[u] = 1;
        cout << u << ' ' << v << '\n';
        if (a[u] > 1 && a[v] > a[u]-1) { cout << "NO\n"; return 0; }
        dd[v] += a[u] - 1;
        deg[v]--;
        if (deg[v] == 1) q.emplace(v);
    }
    cout << "YES\n";
}

