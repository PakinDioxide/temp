#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, q, s; cin >> n >> m >> q >> s;
    if (n == 0) exit(0);
    vector <pair <int, ll>> adj[n]; ll dis[n]; for (auto &e : dis) e = LLONG_MAX; dis[s] = 0;
    for (int i = 0; i < m; i++) { int u, v; ll w; cin >> u >> v >> w; adj[u].emplace_back(v, w); }
    for (int c = 0; c < n-1; c++) for (int u = 0; u < n; u++) if (dis[u] < LLONG_MAX) for (auto [v, w] : adj[u]) dis[v] = min(dis[v], dis[u] + w);
    queue <int> Q;
    for (int u = 0; u < n; u++) if (dis[u] < LLONG_MAX) for (auto [v, w] : adj[u]) if (dis[v] > dis[u] + w) Q.emplace(v);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        dis[u] = LLONG_MIN;
        for (auto [v, w] : adj[u]) if (dis[v] > LLONG_MIN) Q.emplace(v);
    }
    while (q--) {
        int x; cin >> x;
        if (dis[x] == LLONG_MAX) cout << "Impossible\n";
        else if (dis[x] == LLONG_MIN) cout << "-Infinity\n";
        else cout << dis[x] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while (1) solve();
    void solve();
}