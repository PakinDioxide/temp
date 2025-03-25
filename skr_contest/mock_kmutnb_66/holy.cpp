/*
    author  : PakinDioxide
    created : 25/03/2025 20:26
    task    : holy
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair <int, int> d[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    ll a[n], b[m], k;
    cin >> k;
    for (auto &e : a) cin >> e;
    for (auto &e : b) cin >> e;
    int vis[n][m], cnt = 0, mx = 0;
    memset(vis, 0, sizeof(vis));
    auto calc = [&] (int x, int y) {
        return a[x] - b[y];
    };
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (vis[i][j] || calc(i, j) < k) continue;
        queue <pair <int, int>> q;
        q.emplace(i, j);
        cnt++;
        int sum = 0;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            sum++;
            for (auto [dx, dy] : d) {
                int nx = dx+x, ny = dy+y;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || calc(nx, ny) < k) continue;
                q.emplace(nx, ny);
            }
        }
        mx = max(mx, sum);
    }
    cout << cnt << ' ' << mx << '\n';
}