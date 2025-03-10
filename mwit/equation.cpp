#include <bits/stdc++.h>
#define ll long long

using namespace std;

int par[300005];
vector <tuple <int, ll, ll, ll>> adj[300005];
ll x[300005];

int fi(int x) {
    if (par[x] != x) return par[x] = fi(par[x]);
    return x;
}

void dfs(int u, int p) {
    for (auto [v, a, b, c] : adj[u]) {
        if (v == p) continue;
        x[v] = (c - a*x[u])/b;
        dfs(v, u);
    }
}

int main() {
    int n, m;
    cin >> n >> m >> x[1];
    ll ans = 0;
    vector <tuple <ll, ll, ll, ll, int, int>> E(m);
    for (auto &[w, a, b, c, u, v] : E) {
        cin >> u >> v >> a >> b >> c;
        w = a+b+c;
    }
    iota(par+1, par+n+1, 1);
    sort(E.begin(), E.end());
    for (auto [w, a, b, c, u, v] : E) {
        if (fi(u) == fi(v)) continue;
        par[fi(u)] = fi(v);
        adj[u].emplace_back(v, a, b, c);
        adj[v].emplace_back(u, b, a, c);
        ans += w;
    }
    cout << ans << '\n';
    dfs(1, 0);
    for (int i = 1; i <= n; i++) cout << x[i] << '\n';
}