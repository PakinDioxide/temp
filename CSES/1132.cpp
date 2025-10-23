#include <bits/stdc++.h>

using namespace std;

vector <int> adj[200005];

int f[200005], g[200005], h[200005], k[200005];

void dfs1(int u, int p) {
    f[u] = h[u] = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        if (f[v]+1 >= f[u]) h[u] = f[u], f[u] = f[v]+1, k[u] = v;
        else h[u] = max(h[u], f[v]+1);
    }
}

void dfs2(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        g[v] = max(g[u]+1, (v == k[u] ? h[u] : f[u]) + 1);
        dfs2(v, u);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {int u, v; cin >> u >> v; adj[u].push_back(v), adj[v].push_back(u);}
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) cout << max(f[i], g[i]) << ' ';
    cout << '\n';
}