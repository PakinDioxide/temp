/*
    author  : 
    created : 23/08/2025 22:05
    task    : 685B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 3e5+5;

int n, q, sz[mxN], ct[mxN], par[mxN], w[mxN];
vector <int> adj[mxN];

void dfs(int u) {
    sz[u] = 1, ct[u] = u;
    for (auto v : adj[u]) {
        dfs(v);
        sz[u] += sz[v];
        w[u] = max(w[u], sz[v]);
    }
    for (auto v : adj[u]) {
        int x = ct[v];
        while (x != u) {
            if (max(w[x], sz[u] - sz[x]) <= sz[u]/2) {
                ct[u] = x;
                break;
            } else {
                x = par[x];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 2, u, v; i <= n; i++) cin >> par[i], adj[par[i]].emplace_back(i);
    dfs(1);
    while (q--) { int x; cin >> x; cout << ct[x] << '\n'; }
}