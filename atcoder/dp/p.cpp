#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <int> adj[100005];
ll dp[100005][2], mod = 1e9+7;

void dfs(int u, int p) {
    int cnt = 0;
    dp[u][0] = dp[u][1] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u][0] *= dp[v][1];
        dp[u][1] *= dp[v][0] + dp[v][1];
        dp[u][0] %= mod;
        dp[u][1] %= mod;
    }
    dp[u][0] %= mod;
    dp[u][1] %= mod;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {int u, v; cin >> u >> v; adj[u].push_back(v), adj[v].push_back(u);}
    dfs(1, 0);
    cout << (dp[1][0] + dp[1][1])%mod << '\n';
}