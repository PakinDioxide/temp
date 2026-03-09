/*
    author  : PakinDioxide
    created : 07/04/2025 18:11
    task    : JOI18_commuter_pass
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, s, t, x, y;
    cin >> n >> m >> s >> t >> x >> y;
    vector <pair <int, ll>> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    ll disx[n+1], disy[n+1];
    for (int i = 1; i <= n; i++) disx[i] = disy[i] = LLONG_MAX;
    priority_queue <pair <ll, int>> q;
    disx[x] = disy[y] = 0;
    q.emplace(0, x);
    while (!q.empty()) {
        auto [w, u] = q.top();
        q.pop();
        w=-w;
        if (disx[u] != w) continue;
        for (auto [v, ww] : adj[u]) if (disx[v] > ww+w) q.emplace(-(disx[v] = ww+w), v);
    }
    q.emplace(0, y);
    while (!q.empty()) {
        auto [w, u] = q.top();
        q.pop();
        w=-w;
        if (disy[u] != w) continue;
        for (auto [v, ww] : adj[u]) if (disy[v] > ww+w) q.emplace(-(disy[v] = ww+w), v);
    }
    priority_queue <tuple <ll, ll, ll, ll, int>> Q; // dis, minx+miny, minx, miny, u
    pair <ll, ll> dis[n+1];
    for (int i = 1; i <= n; i++) dis[i] = make_pair(LLONG_MAX, LLONG_MAX);
    dis[s] = make_pair(0, disx[s] + disy[s]);
    Q.emplace(0, -(disx[s] + disy[s]), -disx[s], -disy[s], s);
    while (!Q.empty()) {
        auto [w, sum, minx, miny, u] = Q.top();
        Q.pop();
        w=-w, sum=-sum, minx=-minx, miny=-miny;
        if (make_pair(w, sum) != dis[u]) continue;
        for (auto [v, ww] : adj[u]) {
            ll nw = w+ww, nx = min(minx, disx[v]), ny = min(miny, disy[v]), ns = nx+ny;
            if (dis[v].first > nw) Q.emplace(-(dis[v].first = nw), -(dis[v].second = ns), -nx, -ny, v);
            else if (dis[v].first == nw && dis[v].second > ns) Q.emplace(-(dis[v].first = nw), -(dis[v].second = ns), -nx, -ny, v);
        }
    }
    cout << min(dis[t].second, disx[y]) << '\n';
}