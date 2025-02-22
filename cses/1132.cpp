#include <bits/stdc++.h>

using namespace std;

vector <int> adj[200005];
int dp[200005], mainp[200005];

void dfs(int u, int p) {
    dp[u] = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u] = dp[v]+1;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0, u, v; i < n-1; i++) cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);

}