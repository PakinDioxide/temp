#include <bits/stdc++.h>

using namespace std;

vector <int> adj[100005];
int vis[100005], dp[100005];

int dfs(int u) {
    if (vis[u]) return dp[u];
    dp[u] = 0, vis[u] = 1;
    for (int v : adj[u]) {
        dp[u] = max(dp[u], dfs(v)+1);
    }
    return dp[u];
}

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(dfs(i), ans);
    }
    cout << ans << '\n';
}