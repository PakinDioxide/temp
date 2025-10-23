/*
    author  : PakinDioxide
    created : 08/05/2025 17:06
    task    : 2020_Feb_G_1
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n, c, m;
ll s[mxN], dp[mxN];
vector <tuple <int, ll>> adj[mxN];

ll dfs(int u) {
    if (dp[u]) return dp[u];
    dp[u] = s[u];
    for (auto [v, w] : adj[u]) dp[u] = max(dp[u], dfs(v) + w);
    return dp[u];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);
    cin >> n >> c >> m;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 0; i < m; i++) { int u, v; ll w; cin >> u >> v >> w; adj[v].emplace_back(u, w); }
    for (int i = 1; i <= n; i++) cout << dfs(i) << '\n';
}