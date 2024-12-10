#include <bits/stdc++.h>

using namespace std;

int n, m, s, d, h, qq;

vector <pair <int, int>> adj[2005];

int main() {
    scanf("%d %d %d %d", &n, &s, &d, &m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].emplace_back(v, w);
    }
    vector <vector <pair <int, int>>> dis(n);
    dis[s].emplace_back(0, 0);
    priority_queue <tuple <int, int, int>> q;
    q.emplace(0, 0, s);
    while (!q.empty()) {
        auto [ww, c, u] = q.top();
        ww *= -1;
        q.pop();
        for (auto [v, w] : adj[u]) {
            bool ok = 1;
            for (auto [x, y] : dis[v]) {
                if (ww + w >= x && c+1 >= y) {ok = 0; break;}
            }
            if (ok) {
                dis[v].emplace_back(ww + w, c+1);
                q.emplace(-(ww + w), c+1, v);
            }
        }
    }
    scanf("%d", &qq);
    while (qq--) {
        scanf("%d", &h);
        int ans = INT_MAX;
        for (auto [x, y] : dis[d]) ans = min(ans, x + (y-1)*h);
        printf("%d ", ans);
    }
}