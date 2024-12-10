#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

int n;
vector <int> adj[200005];
int dp[200005][2];

void dfs(int u, int p) {
    int cnt = 0;
    dp[u][0] = 1, dp[u][1] = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u][1] += max(dp[v][0], dp[v][1]);
        dp[u][0] += max(dp[v][0]-1, dp[v][1]);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) adj[i].clear(), dp[i][0] = dp[i][1] = sz[i] = 0;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    // for (int i = 1; i <= n; i++) cout << dp[i][0] << ' ' << dp[i][1] << '\n';
    cout << max(dp[1][0], dp[1][1]) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}