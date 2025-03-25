/*
    author  : PakinDioxide
    created : 13/03/2025 15:44
    task    : 1680
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <int> adj[100005];
int dp[100005], par[100005], ok[100005], vis[100005];

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    dp[u] = 1;
    for (int v : adj[u]) {
        dfs(v);
        if (ok[v] && dp[v] + 1 > dp[u]) dp[u] = dp[v] + 1, ok[u] = 1, par[u] = v;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    ok[n] = 1;
    dfs(1);
    if (ok[1]) {
        cout << dp[1] << '\n';
        int k = 1;
        while (k != n) cout << k << ' ', k = par[k];
        cout << k << '\n';
    } else cout << "IMPOSSIBLE\n";
}