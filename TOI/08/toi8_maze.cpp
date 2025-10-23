#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, sx, sy, dx, dy, mov[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    cin >> n >> m >> sx >> sy >> dx >> dy;
    int a[n+1][m+1], vis[n+1][m+1][2], vis2[n+1][m+1][2], bomb[n+1][m+1], ans = INT_MAX, ans2 = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {cin >> a[i][j]; vis[i][j][0] = vis[i][j][1] = vis2[i][j][0] = vis2[i][j][1] = bomb[i][j] = 0;}
    queue <tuple <int, int, int, int, int, int>> q;
    q.emplace(sx, sy, 1, 0, 0, 0);
    while (!q.empty()) {
        auto [x, y, c, alr, bx, by] = q.front();
        q.pop();
        if (x == dx && y == dy) {
            ans = min(ans, c);
            continue;
        }
        if (vis[x][y][alr]) continue;
        vis[x][y][alr] = 1;
        for (auto [i, j] : mov) {
            if (x+i == 0 || y+j == 0 || x+i > n || y+j > m || (!a[x+i][y+j] && alr)) continue;
            if (a[x+i][y+j] == 0) {q.emplace(x+i, y+j, c+1, 1, x+i, y+j); bomb[x+i][y+j] = 1;}
            else q.emplace(x+i, y+j, c+1, alr, bx, by);
        }
    }
    q.emplace(dx, dy, 1, 0, 0, 0);
    while (!q.empty()) {
        auto [x, y, c, alr, bx, by] = q.front();
        q.pop();
        if (x == sx && y == sy) {
            continue;
        }
        if (vis2[x][y][alr]) continue;
        vis2[x][y][alr] = 1;
        for (auto [i, j] : mov) {
            if (x+i == 0 || y+j == 0 || x+i > n || y+j > m || (!a[x+i][y+j] && alr)) continue;
            if (a[x+i][y+j] == 0) {if (bomb[x+i][y+j] == 1) {ans2++; bomb[x+i][y+j] = 2;} else continue;}
            else q.emplace(x+i, y+j, c+1, alr, bx, by);
        }
    }
    cout << ans2 << '\n' << ans;
}