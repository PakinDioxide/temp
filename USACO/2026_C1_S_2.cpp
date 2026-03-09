#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    int l[n+1], r[n+1];
    for (int i = 1; i <= n; i++) cin >> l[i];
    for (int i = 1; i <= n; i++) cin >> r[i];
    vector <pair <int, int>> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    vector <int> val(n+1, LLONG_MIN), cc(n+1), ccc(n+1);
    int it = 0, ok = 1;
    function <void(int, int)> dfs = [&] (int u, int p) {
        if (ok == 0) return;
        for (auto [v, w] : adj[u]) if (v != p) {
            int nxc = -cc[u], nnc = w - ccc[u];
            if (!cc[v]) cc[v] = nxc, ccc[v] = nnc, dfs(v, u);
            else {
                if (nxc == cc[v]) {
                    if (nnc != ccc[v]) { ok = 0; return; }
                } else {
                    int V = (ccc[v] - nnc);
                    if (V % 2 != 0) { ok = 0; return; }
                    V /= 2;
                    if (cc[u] > 0) V = -V;
                    if (val[abs(cc[u])] == LLONG_MIN || val[abs(cc[u])] == V) val[abs(cc[u])] = V;
                    else { ok = 0; return; }
                }
            }
        }
    };
    for (int i = 1; i <= n; i++) if (!cc[i]) {
        cc[i] = ++it;
        dfs(i, 0);
    }
    if (!ok) { cout << -1 << '\n'; return; }
    vector <int> RV(n+1);
    map <int, vector <int>> mp;
    for (int i = 1; i <= n; i++) mp[abs(cc[i])].emplace_back(i);
    int ans = 0;
    for (auto &[x, V] : mp) {
        if (val[x] != LLONG_MIN) {
            for (auto &e : V) RV[e] = (cc[e] < 0 ? -1 : 1) * val[x] + ccc[e];
            for (auto &e : V) ans += (l[e] <= RV[e] && RV[e] <= r[e]);
        } else {
            for (auto &e : V) l[e] -= ccc[e], r[e] -= ccc[e];
            for (auto &e : V) if (cc[e] < 0) l[e] *= -1, r[e] *= -1, swap(l[e], r[e]);
            vector <pair <int, int>> vv;
            for (auto &e : V) vv.emplace_back(l[e], 1), vv.emplace_back(r[e]+1, -1);
            sort(vv.begin(), vv.end());
            int mx = 0, c = 0;
            for (auto &[x, y] : vv) c += y, mx = max(mx, c);
            ans += mx;
        }
    }
    // for (int i = 1; i <= n; i++) cout << RV[i] << ' '; cout << '\n';
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
