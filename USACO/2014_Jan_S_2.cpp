/*
    author  : PakinDioxide
    created : 22/03/2025 15:10
    task    : 2014_Jan_S_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair <int, int> d[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    int n, m, sx, sy;
    cin >> n >> m;
    ll a[n][m], b[n][m];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {cin >> b[i][j]; if (b[i][j]) sx = i, sy = j;}
    ll mx = 0;
    priority_queue <tuple <ll, int, int>> q;
    q.emplace(0, sx, sy);
    int vis[n][m];
    memset(vis, 0, sizeof(vis));
    while (!q.empty()) {
        auto [c, x, y] = q.top();
        c=-c;
        q.pop();
        if (vis[x][y]) continue;
        vis[x][y] = 1;
        if (b[x][y]) mx = max(mx, c);
        for (auto [dx, dy] : d) {
            int nx = x+dx, ny = y+dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            q.emplace(-max(c, abs(a[x][y] - a[nx][ny])), nx, ny);
        }
    }
    cout << mx << '\n';
}