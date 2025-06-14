/*
    author  : PakinDioxide
    created : 26/05/2025 21:59
    task    : 2114E
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    ll a[n];
    for (auto &e : a) cin >> e;
    vector <int> adj[n];
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, u--, v--, adj[u].emplace_back(v), adj[v].emplace_back(u);
    vector <vector <ll>> dp(n, vector <ll>(2));
    function<void(int, int)> dfs = [&] (int u, int p) {
        dp[u][1] = max(dp[u][1], a[u]);
        for (auto v : adj[u]) if (v != p) {
            dp[v][1] = a[v] - dp[u][0];
            dp[v][0] = min(0LL, a[v] - dp[u][1]);
            dfs(v, u);
        }
    };
    dfs(0, 0);
    for (auto &e : dp) cout << e[1] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}