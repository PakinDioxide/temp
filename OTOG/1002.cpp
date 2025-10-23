/*
    author  : PakinDioxide
    created : 11/04/2025 01:26
    task    : 1002
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;
int n, m, q, lo[mxN], id[mxN], idx = 0;
ll dis[mxN];
vector <int> adj[mxN];
vector <pair <int, ll>> adjt[mxN];

void dfs(int u, int p) {
    lo[u] = id[u] = ++idx;
    for (auto v : adj[u]) {
        if (v == p) continue;
        if (!id[v]) dfs(v, u);
        lo[u] = min(lo[u], lo[v]);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        u++, v++;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        adjt[u].emplace_back(v, w);
        adjt[v].emplace_back(u, w);
    }
    for (int i = 1; i <= n; i++) if (!id[i]) dfs(i, i);
    while (q--) {
        int x, y;
        cin >> x >> y;
        x++, y++;
        if (lo[x] != lo[y]) { cout << -1 << '\n'; continue; }
        for (int i = 1; i <= n; i++) dis[i] = LLONG_MAX;
        priority_queue <pair <ll, int>> Q;
        Q.emplace(0, x);
        dis[x] = 0;
        while (!Q.empty()) {
            auto [w, u] = Q.top();
            Q.pop();
            w=-w;
            if (dis[u] != w) continue;
            for (auto &[v, ww] : adjt[u]) if (dis[v] > w+ww) Q.emplace(-(dis[v] = w+ww), v);
        }
        cout << dis[y] << '\n';
    }
}