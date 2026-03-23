#include "cyberland.h"
#include <bits/stdc++.h>
#define ll long long
#define db double

using namespace std;

db solve(int N, int M, int K, int H, vector <int> x, vector <int> y, vector <int> c, vector <int> P) {
    K = min(K, 70);
    vector <pair <int, db>> adj[N];
    for (int i = 0; i < M; i++) adj[x[i]].emplace_back(y[i], c[i]), adj[y[i]].emplace_back(x[i], c[i]);
    db dis[N][K + 1];
    for (auto &E : dis) for (auto &e : E) e = DBL_MAX;
    int vis[N]; memset(vis, 0, sizeof(vis));
    queue <int> Q;
    Q.emplace(0); vis[0] = 1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (u == H) continue;
        for (auto [v, w] : adj[u]) if (!vis[v]) vis[v] = 1, Q.emplace(v);
    }
    memset(dis[0], 0, sizeof(dis[0]));
    priority_queue <tuple <db, int, int>> q;
    q.emplace(0, 0, 0);
    for (int i = 1; i < N; i++) if (P[i] == 0 && vis[i]) memset(dis[i], 0, sizeof(dis[i])), q.emplace(0, i, 0);
    while (!q.empty()) {
        auto [W, u, k] = q.top();
        q.pop();
        W = -W;
        if (dis[u][k] != W || u == H) continue;
        for (auto [v, w] : adj[u]) {
            if (dis[v][k] > dis[u][k] + w) q.emplace(-(dis[v][k] = dis[u][k] + w), v, k);
            if (P[v] == 2 && k < K) if (dis[v][k+1] > (dis[u][k] + w) / 2) q.emplace(-(dis[v][k+1] = (dis[u][k] + w)/2), v, k+1);
        }
    }
    db ans = DBL_MAX;
    for (int i = 0; i <= K; i++) ans = min(ans, dis[H][i]);
    return (ans == DBL_MAX ? -1 : ans);
}
