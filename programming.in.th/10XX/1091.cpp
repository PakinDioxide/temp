#include <bits/stdc++.h>

using namespace std;

int n, dp[300001];
vector <int> adj[300001];

int dfs(int u) {
    if (dp[u] > 0) return dp[u];
    int k = 0;
    for (int v : adj[u]) {
        k = max(k, dfs(v));
    }
    return dp[u] = k+1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[min(u, v)].push_back(max(u, v));
    }
    int ans = 0;
    for (int i = 0; i < n-1; i++) ans = max(ans, dfs(i));
    cout << ans;
}