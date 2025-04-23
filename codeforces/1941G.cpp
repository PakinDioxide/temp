/*
    author  : PakinDioxide
    created : 17/04/2025 23:20
    task    : 1941G
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <pair <int, int>> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }
    deque <tuple <int, int, int, int>> q;
    int s, e;
    cin >> s >> e;
    int dis[n+1];
    for (int i = 1; i <= n; i++) dis[i] = INT_MAX;
    q.emplace_front(0, s, s, -1);
    dis[s] = 0;
    while (!q.empty()) {
        auto [w, u, p, c] = q.front();
        q.pop_front();
        if (w != dis[u]) continue;
        if (u == e) {cout << w << '\n'; return;}
        // cout << w << ' ' << u << ' ' << p << ' ' << c << '\n';
        for (auto [v, ww] : adj[u]) if (v != p) {
            if (ww != c && dis[v] >= w+1) q.emplace_back(dis[v] = w+1, v, u, ww);
            else if (ww == c && dis[v] >= w) q.emplace_front(dis[v] = w, v, u, c);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}