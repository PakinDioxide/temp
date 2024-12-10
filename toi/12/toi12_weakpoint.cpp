#include <bits/stdc++.h>

using namespace std;

vector <int> adj[500001];
int n, m, ans = -2, ans2 = 0, dp[500001], cangom[500001];

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == m) {
            cangom[u] = 1;
            continue;
        } else if (v == p || dp[v] > 0) continue;
        dfs(v, u);
        if (!cangom[v]) dp[u] += dp[v];
        cangom[u] = max(cangom[u], cangom[v]);
    }
    if (adj[u].size() == 1 || dp[u] > 0) dp[u]++;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(m, -1);
    for (int u = 1; u <= n; u++) {
        if (u == m) continue;
        if (dp[u] > ans) {
            ans = dp[u];
            ans2 = u;
        }
    }
    cout << ans2 << '\n' << ans - (ans != 0);
}