/*
    author  : PakinDioxide
    created : 
    task    : 
*/
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector <tuple <ll, int, int>> E(m);
    for (auto &[w, u, v] : E) cin >> u >> v >> w;
    sort(E.begin(), E.end());
    int par[n+1]; iota(par, par+n+1, 0);
    vector <pair <int, ll>> adj[n+1];
    function <int(int)> fi = [&] (int x) {
        if (x == par[x]) return x;
        return par[x] = fi(par[x]);
    };
    int cnt = 0;
    for (auto &[w, u, v] : E) {
        if (fi(u) == fi(v)) continue;
        par[fi(u)] = fi(v);
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        if (cnt == n-1) break;
    }
    pair <ll, ll> dp[n+1];
    dp[1] = make_pair(LLONG_MAX, LLONG_MIN);
    function <void(int, int)> dfs = [&] (int u, int p) {
        for (auto [v, w] : adj[u]) if (v != p) {
            dp[v] = make_pair(min(dp[u].first, w), max(dp[u].second, w));
            dfs(v, u);
        }
    };
    dfs(1, 1);
    ll mn = LLONG_MAX;
    for (int i = 2; i <= n; i++) mn = min(mn, min(dp[i].first, dp[n].first) + max(dp[i].second, dp[n].second));
    cout << mn << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

