/*
    author  : PakinDioxide
    created : 03/05/2025 19:51
    task    : D1_A
*/
#include <bits/stdc++.h>
#define ll long long

#pragma GCC optimize("O2")
#pragma GCC target("avx2")

using namespace std;

const int mxN = 2005;

int n, c, s, m, ok[mxN];
int dis[mxN][mxN], mn = INT_MAX;
vector <int> K;
vector <pair <int, int>> adj[mxN];
priority_queue <tuple <int, int, int>> q;

int main() {
    scanf("%d %d %d", &n, &c, &s);
    // ios::sync_with_stdio(0), cin.tie(0);
    // cin >> n >> c >> s;
    K.resize(c);
    for (auto &e : K) scanf("%d", &e), ok[e] = 1;
    // cin >> m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int u, v; int w;
        // cin >> u >> v >> w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dis[i][j] = INT_MAX;
    if (c > 300) {
        priority_queue <pair <int, int>> q;
        for (int i = 1; i <= n; i++) {
            dis[i][i] = 0;
            q.emplace(0, i);
            while (!q.empty()) {
                auto [w, u] = q.top(); q.pop();
                w=-w;
                if (dis[i][u] != w) continue;
                for (auto [v, ww] : adj[u]) if (dis[i][v] > w+ww) q.emplace(-(dis[i][v] = w+ww), v);
            }
        }
        cout << 0 << '\n';
        return 0;
    }
    dis[s][s] = 0;
    q.emplace(0, s, s);
    while (!q.empty()) {
        auto [w, u, y] = q.top();
        q.pop();
        w=-w;
        if (dis[u][y] != w) continue;
        for (auto [v, ww] : adj[u]) {
            if (dis[v][y] > w+ww) q.emplace(-(dis[v][y] = w+ww), v, y);
        }
        if (!ok[u] || dis[u][u] < w) continue;
        dis[u][u] = w;
        y = u;
        for (auto [v, ww] : adj[u]) {
            if (dis[v][y] > w+ww) q.emplace(-(dis[v][y] = w+ww), v, y);
        }
    }
    for (auto &i : K) {
        vector <int> v;
        int x = INT_MAX, y = INT_MAX;
        for (auto &j : K) if (j != i) {
            if (dis[i][j] <= x) y = x, x = dis[i][j];
            else if (dis[i][j] <= y) y = dis[i][j];
        }
        mn = min(mn, x+y);
    }
    printf("%d\n", mn);
    // cout << mn << '\n';
}