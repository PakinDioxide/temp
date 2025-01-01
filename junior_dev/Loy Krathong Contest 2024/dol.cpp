#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, x, y, d, s, t;
    cin >> n >> m >> x >> y >> d;
    vector <pair <int, int>> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    cin >> s >> t;
    ll vis[n+1], mmm = -1;
    for (int i = 1; i <= n; i++) vis[i] = 0;
    queue <pair <pair <ll, ll>, ll>> q;
    q.push({{s, 0}, LLONG_MAX});
    while (!q.empty()) {
        ll u = q.front().first.first, c = q.front().first.second, mm = q.front().second;
        q.pop();
        if (vis[u]) continue;
        // cerr << u << '\n';
        if (u == t) {
            mmm = max(mmm, mm);
            continue;
        }
        vis[u] = 1;
        for (auto [v, w] : adj[u]) {
            if (w > x - y*c || vis[v]) continue;
            q.push({{v, c+1}, min(mm, x - y*c - w)});
        }
    }
    if (mmm == -1) cout << "Simp";
    else cout << mmm/d;
}