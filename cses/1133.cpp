/*
    author  : PakinDioxide
    created : 12/03/2025 17:10
    task    : 1133
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <int> adj[200005];
ll dep[200005], dp[200005], par[200005], cnt[200005];

void dfs(int u, int p) {
    dp[u] = 0;
    cnt[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        if (u == 1) par[v] = v;
        else par[v] = par[u];
        dfs(v, u);
        dp[u] += dp[v] + cnt[v];
        cnt[u] += cnt[v];
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {int u, v; cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);}
    dfs(1, 0);
    cout << dp[1] << ' ';
    for (int i = 2; i <= n; i++) cout << dp[1] - dp[i] + 
}