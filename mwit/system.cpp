#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, t, k;
    cin >> n >> m >> t >> k;
    vector <pair <int, ll>> adj[n];
    ll l = 0, r = 0, ans = 0;
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        r += w;
    }
    while (l <= r) {
        ll x = l + (r-l)/2, dc[n][2];
        int dis[n][2];
        for (int i = 0; i < n; i++) dis[i][0] = dis[i][1] = INT_MAX, dc[i][0] = dc[i][1] = LLONG_MAX;
        dis[0][0] = 0;
        dc[0][0] = x;
        priority_queue <tuple <int, ll, int, int>> q;
        q.emplace(0, x, 0, 0);
        while (!q.empty()) {
            auto [w, W, c, u] = q.top();
            q.pop();
            w=-w;
            if (w != dis[u][c] || W != dc[u][c]) continue;
            for (auto [v, ww] : adj[u]) {
                if (ww > x) continue;
                if (dis[v][c] > w + (W < ww)) q.emplace(-(dis[v][c] = w + (W < ww)), (dc[v][c] = (W - ww < 0 ? x - ww : W - ww)), c, v);
                else if (dis[v][c] == w + (W < ww) && dc[v][c] < (W - ww < 0 ? x - ww : W - ww)) q.emplace(-(dis[v][c] = w + (W < ww)), (dc[v][c] = (W - ww < 0 ? x - ww : W - ww)), c, v);
            }
            if (c) continue;
            for (auto [v, ww] : adj[u]) {
                if (dis[v][1] > w) q.emplace(-(dis[v][1] = w), (dc[v][1] = max(0LL, W-ww)), 1, v);
                else if (dis[v][1] == w && dc[v][1] < max(0LL, W-ww)) q.emplace(-(dis[v][1] = w), (dc[v][1] = max(0LL, W-ww)), 1, v);
            }
        }
        int mn = dis[n-1][0];
        if (k) mn = min(mn, dis[n-1][1]);
        if (mn <= t) ans = x, r = x-1;
        else l = x+1;
    }
    cout << ans << '\n';
}