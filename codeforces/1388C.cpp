#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; ll m;
    cin >> n >> m;
    ll dp[n+1], h[n+1], P[n+1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) cin >> dp[i], P[i] = dp[i];
    for (int i = 1; i <= n; i++) cin >> h[i];
    vector <int> adj[n+1];
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    function <int(int, int)> dfs = [&] (int u, int p) {
        for (auto v : adj[u]) if (v != p) dp[u] += dfs(v, u);
        return dp[u];
    };
    dfs(1, 0);
    ll bd[n+1];
    bd[0] = 0;
    for (int i = 1; i <= n; i++) {
        // (T - bd) - bd = h
        // T - h = 2 * bd;
        bd[i] = dp[i] - h[i];
        if (bd[i] % 2 == 1 || bd[i] < 0 || bd[i]/2 > dp[i]) { cout << "NO\n"; return; }
        bd[i] /= 2;
    }
    // for (int i = 1; i <= n; i++) cout << bd[i] << ' '; cout << '\n';
    function <int(int, int)> dfs2 = [&] (int u, int p) {
        ll s = 0;
        for (auto v : adj[u]) if (v != p) {
            if (!dfs2(v, u)) return 0;
            s += bd[v];
        }
        if (s < bd[u] - P[u]) { return 0; }
        return 1;
    };
    if (dfs2(1, 0)) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

