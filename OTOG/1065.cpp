/*
    author  : PakinDioxide
    created : 30/04/2025 19:54
    task    : 1065
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;
int n, m, k; ll dis[mxN];
vector <int> c;
vector <pair <int, ll>> adj[mxN];
priority_queue <pair <ll, int>> q;

int main() {
    scanf("%d %d %d", &n, &m, &k);
    while (m--) { int u, v; ll w; scanf("%d %d %lld", &u, &v, &w); adj[u].emplace_back(v, w), adj[v].emplace_back(u, w); }
    while (k--) { int x; ll y; scanf("%d %lld", &x, &y); y++; if (dis[x] < y) q.emplace(dis[x] = y, x); }
    while (!q.empty()) { auto [w, u] = q.top(); q.pop(); if (dis[u] != w || w == 0) continue; for (auto [v, ww] : adj[u]) if (dis[v] < w-ww) q.emplace(dis[v] = w-ww, v); }
    for (int i = 1; i <= n; i++) if (dis[i]) c.emplace_back(i);
    printf("%d\n", (int) c.size());
    for (auto &e : c) printf("%d ", e);
    printf("\n");
}