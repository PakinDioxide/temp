/*
    author  : PakinDioxide
    created : 30/04/2025 19:54
    task    : 1065
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;
ll n, m, k, dis[mxN], c = 0;
vector <pair <ll, ll>> adj[mxN];
priority_queue <pair <ll, ll>> q;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    while (m--) { ll u, v, w; cin >> u >> v >> w; adj[u].emplace_back(v, w), adj[v].emplace_back(u, w); }
    while (k--) { ll x, y; cin >> x >> y; y++; if (dis[x] < y) q.emplace(dis[x] = y, x); }
    while (!q.empty()) { auto [w, u] = q.top(); q.pop(); if (dis[u] != w || w == 0) continue; for (auto [v, ww] : adj[u]) if (dis[v] < w-ww) q.emplace(dis[v] = w-ww, v); }
    for (int i = 1; i <= n; i++) c += (dis[i] > 0);
    cout << c << '\n';
    for (int i = 1; i <= n; i++) if (dis[i]) cout << i << ' ';
    cout << '\n';
}