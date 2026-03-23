#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mod = 1e9+7;

ll poww(ll x, ll y) {
    if (y == 0) return 1;
    ll k = poww(x, y/2);
    k *= k, k %= mod;;
    if (y % 2 == 1) k *= x, k %= mod;
    return k;
}

ll inv(ll x) {
    return poww(x, mod-2);
}

void solve() {
    // DO DFS TREE?
    // path[n] = k * (k-1) ^ (n-1)
    // cycle[n] = path[n] - cycle[n-1] (when 1 = n, can be seen as merging 1 and n)
    int n, m; cin >> n >> m;
    ll k; cin >> k;
    ll path[n+5], cycle[n+5];
    path[1] = k, cycle[1] = k, cycle[2] = k * (k-1);
    for (int i = 2; i <= n; i++) path[i] = path[i-1] * (k-1), path[i] %= mod;
    for (int i = 3; i <= n; i++) cycle[i] = (((path[i] - cycle[i-1]) % mod) + mod) % mod;
    vector <int> adj[n+1];
    for (int i = 0, u, v; i < m; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    int dep[n+1]; memset(dep, 0, sizeof(dep));
    ll ans = 1;
    function <void(int, int)> dfs = [&] (int u, int p) {
        dep[u] = dep[p] + 1;
        for (auto v : adj[u]) if (v != p) {
            if (!dep[v]) dfs(v, u);
            else if (dep[v] < dep[u]) {
                m -= (dep[u] - dep[v]) + 1;
                n -= (dep[u] - dep[v]) + 1;
                ans *= cycle[dep[u] - dep[v] + 1];
                ans %= mod;
            }
        }
    };
    dfs(1, 0);
    ans *= poww(k, n), ans %= mod;
    ans *= poww(((k-1) * inv(k) % mod), m), ans %= mod;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

