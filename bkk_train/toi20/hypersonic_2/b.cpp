/*
    author  : PakinDioxide
    created : 11/04/2025 17:30
    task    : b
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair <int, int> d[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void solve() {
    int n, m;
    cin >> n >> m;
    string a[n];
    for (auto &e : a) cin >> e;
    int sx = 0, sy = 0, dis[n][m];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {if (a[i][j] == 'A') sx = i, sy = j; dis[i][j] = INT_MAX;}
    dis[sx][sy] = 0;
    priority_queue <tuple <int, int, int>> q;
    q.emplace(0, sx, sy);
    while (!q.empty()) {
        auto [w, x, y] = q.top(); w=-w;
        q.pop();
        if (dis[x][y] != w) continue;
        if (a[x][y] == 'B') { cout << w << '\n'; return; }
        for (auto &[dx, dy] : d) {
            int nx = x+dx, ny = y+dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == '#') continue;
            if (dis[nx][ny] > w+1) q.emplace(-(dis[nx][ny] = w+1), nx, ny);
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}