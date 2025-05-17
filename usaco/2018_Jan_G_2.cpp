/*
    author  : PakinDioxide
    created : 02/05/2025 21:55
    task    : 2018_Jan_G_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n, k, deg[mxN], dp[mxN], cnt = 0;
vector <int> adj[mxN];

void dfs1(int u, int p) {
    dp[u] = (deg[u] != 1) * INT_MAX;
    for (auto v : adj[u]) if (v != p) {
        dfs1(v, u);
        dp[u] = min(dp[u], dp[v] + 1);
    }
}

void dfs2(int u, int p, int d) {
    if (d >= dp[u]) { cnt++; return; }
    for (auto v : adj[u]) if (v != p) dfs2(v, u, d+1);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u), deg[u]++, deg[v]++;
    dfs1(k, k), dfs2(k, k, 0);
    cout << cnt << '\n';
}