#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, s, t; ll p;
    cin >> n >> m >> s >> t >> p;
    vector <pair <int, ll>> adj[n+1], adt[n+1];
    vector <tuple <ll, int, int>> E;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        ll w; cin >> w;
        adj[u].emplace_back(v, w);
        adt[v].emplace_back(u, w);
        E.emplace_back(w, u, v);
    }
    auto dijk = [&] (vector <ll> &dis, int S) {
        dis.resize(n+1);
        for (auto &e : dis) e = LLONG_MAX;
        dis[S] = 0;
        priority_queue <pair <ll, int>> q;
        q.emplace(0, S);
        while (!q.empty()) {
            ll w; int u;
            tie(w, u) = q.top(); q.pop();
            w = -w;
            if (dis[u] != w) continue;
            if (S == s) for (auto &e : adj[u]) {
                int v; ll w;
                tie(v, w) = e;
                if (dis[v] > dis[u] + w) q.emplace(-(dis[v] = dis[u] + w), v);
            } else for (auto &e : adt[u]) {
                int v; ll w;
                tie(v, w) = e;
                if (dis[v] > dis[u] + w) q.emplace(-(dis[v] = dis[u] + w), v);
            }
        }
    };
    vector <ll> disx, disy;
    dijk(disx, s);
    dijk(disy, t);
    ll mx = -1;
    for (auto &e : E) {
        ll w; int u, v;
        tie(w, u, v) = e;
        if (disx[u] < LLONG_MAX && disy[v] < LLONG_MAX && w + disx[u] + disy[v] <= p) mx = max(mx, w);
    }
    cout << mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
}
