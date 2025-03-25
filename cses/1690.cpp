/*
    author  : PakinDioxide
    created : 20/03/2025 14:19
    task    : 1690
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <int> adj[25];
int n, m, vall = 0;
ll dp[25][1 << 20], vis[25][1 << 20], mod = 1e9+7;

ll dfs(int u, int k) {
    k |= (1 << u);
    if (vis[u][k]) return dp[u][k];
    vis[u][k] = 1;
    if (u == n-1) return dp[u][k] = (k == vall);
    ll ans = 0;
    for (int v : adj[u]) {
        if (k & (1 << v)) continue;
        ans += dfs(v, k);
    }
    return dp[u][k] = ans % mod;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) vall |= (1 << i);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }
    cout << dfs(0, 0) << '\n';
}