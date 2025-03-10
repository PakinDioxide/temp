#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll n, m, k, t;
    cin >> n >> m >> k >> t;
    vector <pair <int, ll>> adj[n];
    for (int i = 0; i < m; i++) {int u, v; ll w; cin >> u >> v >> w, adj[u].emplace_back(v, w), adj[v].emplace_back(u, w);}
    ll l = 0, r = 1e9, ans = 0;
    while (l <= r) {
        ll f = l+(r-l)/2;
        ll dis[n][2];
        for (int i = 0; i < n; i++) dis[i][0] = dis[i][1] = LLONG_MAX;
    }
}

// bsearch then dijkstra sort by (charge cnt, current power, ..) done;