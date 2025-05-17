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

int n, c, s, m, ok[mxN], dis[mxN][mxN], mn = INT_MAX;
vector <int> K;
vector <pair <int, int>> adj[mxN];
priority_queue <pair <int, int>> q;

int main() {
    scanf("%d %d %d", &n, &c, &s);
    K.resize(c);
    for (auto &e : K) scanf("%d", &e), ok[e] = 1;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int u, v; int w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dis[i][j] = INT_MAX;
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
    for (auto &e : K) {
        int x = INT_MAX, y = INT_MAX;
        for (auto &ee : K) if (e != ee) {
            if (dis[e][ee] + dis[s][ee] <= x) y = x, x = dis[e][ee] + dis[s][ee];
            else if (dis[e][ee] + dis[s][ee] <= y) y = dis[e][ee] + dis[s][ee];
        }
        mn = min(mn, x+y);
    }
    cout << mn << '\n';
}