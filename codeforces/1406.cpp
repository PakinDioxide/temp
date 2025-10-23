/*
    author  : 
    created : 24/08/2025 06:39
    task    : 1406
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n, wi[mxN], sz[mxN], ct[2], par[mxN];
vector <int> adj[mxN];

void dfs(int u, int p) {
    sz[u] = 1, wi[u] = 0;
    par[u] = p;
    for (auto v : adj[u]) if (v != p) dfs(v, u), sz[u] += sz[v], wi[u] = max(wi[u], sz[v]);
    if (max(wi[u], n-sz[u]) <= n/2) ct[ct[0] != 0] = u;
}

void solve() {
    cin >> n;
    ct[0] = ct[1] = 0;
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    dfs(1, 1);
    if (ct[1] == 0) { cout << 1 << ' ' << adj[1][0] << '\n' << 1 << ' ' << adj[1][0] << '\n'; return; }
    ct[1] = par[ct[0]];
    for (auto v : adj[ct[0]]) if (v != par[ct[0]]) { cout << ct[0] << ' ' << v << '\n' << v << ' ' << ct[1] << '\n'; break; }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}