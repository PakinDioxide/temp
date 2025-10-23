/*
    author  : 
    created : 18/08/2025 19:29
    task    : 2079
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int n, sz[mxN];
vector <int> adj[mxN];

void dfs(int u, int p) {
    sz[u] = 1;
    for (auto v : adj[u]) if (v != p) dfs(v, u), sz[u] += sz[v];
}

int ctd(int u, int p) {
    for (auto v : adj[u]) if (v != p) if (sz[v] * 2 > n) return ctd(v, u);
    return u;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) { int u, v; cin >> u >> v; adj[u].emplace_back(v); adj[v].emplace_back(u); }
    dfs(1, 1);
    cout << ctd(1, 1) << '\n';
}