#include <bits/stdc++.h>

using namespace std;

#define int long long

int par[200005], c[200005];
vector <int> adj[200005];

void dfs(int u, int p) {
    c[u] = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        c[u] = (c[u], c[v] + 1);
    }
    par[u] = p;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) par[i] = c[i] = 0, adj[i].clear();
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    int q;
    cin >> q;
    while (q--) {
        int u, k, ans = 0, cnt = 0, r;
        cin >> u >> k;
        r = u;
        while (k > 0 && u != 0) {
            int mx = 0;
            for (int v : adj[u]) {
                if (v == par[u] || v == r) continue;
                mx = max(mx, c[v] + 1);
            }
            ans = max(ans, mx + cnt);
            r = u;
            u = par[u];
            cnt++;
            k--;
        }
        cout << ans << ' ';
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}