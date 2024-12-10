#include <bits/stdc++.h>

using namespace std;

struct warphole {
    int ix, iy, ox, oy;
};

int n, m, k, p;
struct warphole warp[20005];

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &p);
    for (int i = 1; i <= k; i++) scanf("%d %d %d %d", &warp[i].ix, &warp[i].iy, &warp[i].ox, &warp[i].oy);
    vector <vector <long long>> dis(k+2, vector <long long>(p+1, INT_MAX));
    vector <bool> vis(k+2);
    dis[0][0] = 0;
    warp[0].ix = warp[0].iy = warp[0].ox = warp[0].oy = 1;
    warp[k+1].ix = warp[k+1].ox = n;
    warp[k+1].iy = warp[k+1].oy = m;
    priority_queue <pair <int, int>> q;
    q.emplace(0, 0);
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        vis[u] = 1;
        if (u == k+1) break;
        for (int v = 1; v <= k+1; v++) {
            if (u == v || vis[v]) continue;
            bool pa = 0, pb = 0;
            if (dis[u][0] + abs(warp[u].ix - warp[v].ix) + abs(warp[u].iy - warp[v].iy) < dis[v][0]) {
                dis[v][0] = dis[u][0] + abs(warp[u].ix - warp[v].ix) + abs(warp[u].iy - warp[v].iy);
                q.emplace(-dis[v][0], v);
            }
            for (int i = p; i >= 1; i--) {
                if (dis[u][i-1] + abs(warp[u].ox - warp[v].ix) + abs(warp[u].oy - warp[v].iy) < dis[v][i]) {
                    dis[v][i] = dis[u][i-1] + abs(warp[u].ox - warp[v].ix) + abs(warp[u].oy - warp[v].iy);
                    if (!pb) q.emplace(-dis[v][i], v);
                    pb = 1;
                }
            }
        }
    }

    int a1 = INT_MAX, a2 = 0;
    for (int i = 0; i <= p; i++) {
        if (dis[k+1][i] < a1) {
            a1 = dis[k+1][i];
            a2 = i;
        }
    }
    printf("%d %d", a1, a2);
}