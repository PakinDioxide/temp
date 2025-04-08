/*
    author  : PakinDioxide
    created : 08/04/2025 16:15
    task    : v
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <int> adj[100005];
ll dp[100005], ans = 0, mod;

void dfs(int u, int p) {
    dp[u] = 1;
    for (auto v : adj[u]) if (v != p) dfs(v, u), dp[u] *= dp[v], dp[u] %= mod;
    ans += dp[u];
    dp[u]++;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n >> mod;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1, 1);
    cout << dp[1] << '\n';
}