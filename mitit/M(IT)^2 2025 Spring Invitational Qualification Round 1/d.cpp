/*
    author  : PakinDioxide
    created : 06/04/2025 22:31
    task    : d
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int x[k];
    for (auto &e : x) cin >> e;
    vector <int> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    queue <pair <int, int>> q;
    int dis[n+1];
    for (int i = 1; i <= n; i++) dis[i] = INT_MAX;
    dis[1] = 0;
    q.emplace(0, 1);
    while (!q.empty()) {
        auto [w, u] = q.front();
        q.pop();
        if (dis[u] != w) continue;
        for (auto v : adj[u]) if (dis[v] > w + 1) q.emplace(dis[v] = w+1, v);
    }
    vector <pair <int, int>> ans;
    int zr = 1, r = 1;
    if (x[0] == 1) zr = 0;
    for (int i = 0; i < k; i++) {
        if (dis[x[i]] < i+zr) {
            cout << -1 << '\n';
            return;
        }
        if (dis[x[i]] > i+zr) ans.emplace_back(r, x[i]), adj[r].emplace_back(x[i]), adj[x[i]].emplace_back(r);
        r = x[i];
    }
    for (int i = 1; i <= n; i++) dis[i] = INT_MAX;
    dis[1] = 0;
    q.emplace(0, 1);
    while (!q.empty()) {
        auto [w, u] = q.front();
        q.pop();
        if (dis[u] != w) continue;
        for (auto v : adj[u]) if (dis[v] > w + 1) q.emplace(dis[v] = w+1, v);
    }
    for (int i = 0; i < k-1; i++) {
        if (dis[x[i]] >= dis[x[i+1]]) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << ans.size() << '\n';
    for (auto &[x, y] : ans) cout << x << ' ' << y << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}