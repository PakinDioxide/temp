/*
    author  : PakinDioxide
    created : 01/05/2025 13:18
    task    : c
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1005, mxD = 105;

int n, m, d, ans = 0, idx = 1, a[mxD][mxN], dis[mxD][mxN], par[mxD][mxN];
vector <int> adj[mxN];
priority_queue <tuple <int, int, int, int>> q;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> d;
    for (int i = 0; i < d; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
    for (int i = 0; i < m; i++) { int u, v; cin >> u >> v; adj[u].emplace_back(v), adj[v].emplace_back(u); }
    for (int i = 1; i <= n; i++) q.emplace(dis[0][i] = a[0][i], -(par[0][i] = i), 0, i);
    while (!q.empty()) {
        int w, k, u, p; tie(w, p, k, u) = q.top(); q.pop(); p=-p;
        if (dis[k][u] != w) continue;
        if (w > ans) ans = w, idx = p;
        else if (w == ans) idx = min(idx, p);
        if (k == d-1) continue;
        for (auto &v : adj[u]) {
            if (dis[k+1][v] < dis[k][u] + a[k+1][v]) q.emplace(dis[k+1][v] = dis[k][u] + a[k+1][v], -(par[k+1][v] = p), k+1, v);
            else if (dis[k+1][v] == dis[k][u] + a[k+1][v] && par[k+1][v] > p) q.emplace(dis[k+1][v] = dis[k][u] + a[k+1][v], -(par[k+1][v] = p), k+1, v);
        }
    }
    cout << ans << ' ' << idx << '\n';
}