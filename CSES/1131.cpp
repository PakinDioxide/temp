#include <bits/stdc++.h>

using namespace std;

vector <int> adj[200005];
int dp[200005][2];

void dfs(int u, int p) {
    int a = 0, b = 0, c = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (dp[v][0] >= a) b = a, a = dp[v][0];
        else if (dp[v][0] >= b) b = dp[v][0];
        c = max(c, dp[v][1]);
    }
    dp[u][0] = a+1;
    dp[u][1] = max(a+b+1, c);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1])-1 << '\n';
}