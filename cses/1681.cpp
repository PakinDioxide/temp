/*
    author  : PakinDioxide
    created : 25/03/2025 13:20
    task    : 1681
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <int> adj[100005];
ll n, m, vis[100005], dp[100005], mod = 1e9+7;
vector <int> q;

void dfs(int u) {
    if (vis[u]) return;
    for (int v : adj[u]) dfs(v);
    vis[u] = 1;
    q.push_back(u);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {int u, v; cin >> u >> v; adj[v].push_back(u);}
    dfs(n);
    dp[1] = 1;
    for (auto &u : q) for (auto &v : adj[u]) dp[u] += dp[v], dp[u] %= mod;
    cout << dp[n] << '\n';
}