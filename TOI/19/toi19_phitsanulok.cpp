#include <bits/stdc++.h>

using namespace std;

vector <pair <int, int>> adj[1<<20];
vector <int> dis(1<<20, INT_MAX), vis(1<<20);

int main() {
    int n, s;
    scanf("%d %d", &n, &s);
    int p[n];
    for (int i = 0; i < n; i++) {
        int w, poi = 0, med = 0, x;
        scanf("%d", &w);
        for (int j = 0; j < s; j++) {
            scanf("%d", &x);
            if (x == 1) med |= (1 << j);
            else if (x == -1) poi |= (1 << j);
        }
        adj[poi].emplace_back(med, w);
        p[i] = poi;
    }
    priority_queue <pair <int, int>> q;
    dis[0] = 0;
    q.emplace(0, 0);
    while (!q.empty()) {
        int ww = q.top().first, u = q.top().second;
        ww *= -1;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = 0; i < s; i++) {
            if (u & (1 << i)) {
                int v = u ^ (1 << i);
                if (vis[v]) continue;
                if (dis[v] > ww) {
                    dis[v] = ww;
                    q.emplace(-ww, v);
                }
            }
        }
        for (auto [v, w] : adj[u]) {
            if (vis[v]) continue;
            if (dis[v] > ww + w) {
                dis[v] = ww + w;
                q.emplace(-dis[v], v);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) if (vis[p[i]]) ans = max(ans, dis[p[i]]);
    printf("%d", ans);
}