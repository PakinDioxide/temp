#include <bits/stdc++.h>

using namespace std;

int n, dp[200005];
vector <int> adj[200005];

int dfs(int u, int p) {
    dp[u] = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dp[u] = max(dp[u], dfs(v, u) + 1);
    }
    return dp[u];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) printf("%d ", dfs(i, -1));
}