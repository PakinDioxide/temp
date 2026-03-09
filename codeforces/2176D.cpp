#include <bits/stdc++.h>
#define ll long long
#define int ll

const ll mod = 998244353;

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector <pair <int, int>> q;
    int a[n+1], ans[n+1]; for (int i = 1; i <= n; i++) ans[i] = 0, cin >> a[i], q.emplace_back(a[i], i);
    vector <int> adj[n+1];
    unordered_map <int, int> val[n+1];
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v, adj[u].emplace_back(v);
        val[v][a[u]+a[v]]++;
        ans[v]++;
    }
    sort(q.begin(), q.end());
    int ttamx = 0;
    for (auto &[x, u] : q) {
        for (auto v : adj[u]) if (val[u][a[v]] > 0) val[v][a[u]+a[v]] += val[u][a[v]], val[v][a[u]+a[v]] %= mod, ans[v] += val[u][a[v]], ans[v] %= mod;
        ttamx += ans[u], ttamx %= mod;
    }
    cout << ttamx << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}