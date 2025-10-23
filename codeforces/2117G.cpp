#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int par[mxN];
vector <pair <int, ll>> adj[mxN];
pair <ll, ll> x[2][mxN];

int fi(int x) {
    if (x == par[x]) return x;
    return par[x] = fi(par[x]);
}

void dfs(int u, int p, int k, ll mn, ll mx) {
    x[k][u] = make_pair(mn, mx);
    for (auto [v, w] : adj[u]) if (v != p) dfs(v, u, k, min(mn, w), max(mx, w));
}

void solve() {
    int n, m; cin >> n >> m;
    iota(par, par+n+1, 0);
    for (int i = 1; i <= n; i++) adj[i].clear();
    vector <tuple <ll, int, int>> E(m);
    for (auto &[w, u, v] : E) cin >> u >> v >> w;
    sort(E.begin(), E.end());
    int c = 0;
    for (auto &[w, u, v] : E) {
        if (fi(u) != fi(v)) par[fi(u)] = fi(v), c++, adj[u].emplace_back(v, w), adj[v].emplace_back(u, w);
        if (c == n-1) break;
    }
    dfs(1, 1, 0, LLONG_MAX, LLONG_MIN);
    dfs(n, n, 1, LLONG_MAX, LLONG_MIN);
    ll ans = x[0][n].first + x[0][n].second;
    for (int i = 2; i < n; i++) ans = min(ans, min(x[0][i].first, x[1][i].first) + max(x[0][i].second, x[1][i].second));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
