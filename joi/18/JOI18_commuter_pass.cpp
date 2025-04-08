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
    map <pair <int, int>, ll> E;
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        E[make_pair(u, v)] = E[make_pair(v, u)] = w;
    }
    ll dis[n+1], par[n+1];
    for (int i = 1; i <= n; i++) dis[i] = LLONG_MAX, par[i] = i;
    dis[s] = 0;
    priority_queue <pair <ll, int>> q;
    q.emplace(0, s);
    while (!q.empty()) {
        auto [w, u] = q.top(); w=-w;
        q.pop();
        if (dis[u] != w) continue;
        for (auto &[v, ww] : adj[u]) if (dis[v] > w+ww) q.emplace(-(dis[v] = w+ww), v), par[v] = u;
    }
    
}