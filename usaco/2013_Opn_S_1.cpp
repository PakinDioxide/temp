/*
    author  : PakinDioxide
    created : 29/03/2025 16:40
    task    : 2013_Opn_S_1
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("gravity.in", "r", stdin);
    freopen("gravity.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    string a[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] = ' ' + a[i];
    int sx = 0, sy = 0, ex = 0, ey = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (a[i][j] == 'C') sx = i, sy = j;
        else if (a[i][j] == 'D') ex = i, ey = j;
    }
    int dis[n+1][m+1][2];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) dis[i][j][0] = dis[i][j][1] = INT_MAX;
    dis[sx][sy][0] = 0;
    priority_queue <tuple <int, int, int, int>> Q;
    Q.emplace(0, 0, sx, sy);
    while (!Q.empty()) {
        auto [w, c, x, y] = Q.top();
        Q.pop();
        w=-w;
        if (dis[x][y][c] != w) continue;
        if (c == 0 && (x == n || a[x+1][y] != '#')) {
            int nx = x+1, ny = y;
            if (nx < 1 || nx > n) continue;
            if (dis[nx][ny][c] > w) Q.emplace(-(dis[nx][ny][c] = w), c, nx, ny);
            continue;
        } else if (c == 1 && (x == 0 || a[x-1][y] != '#')) {
            int nx = x-1, ny = y;
            if (nx < 1 || nx > n) continue;
            if (dis[nx][ny][c] > w) Q.emplace(-(dis[nx][ny][c] = w), c, nx, ny);
            continue;
        }
        if (y > 1) {
            int nx = x, ny = y-1;
            if (a[nx][ny] == '#') goto o;
            if (dis[nx][ny][c] > w) Q.emplace(-(dis[nx][ny][c] = w), c, nx, ny);
        }
        o:
        if (y < m) {
            int nx = x, ny = y+1;
            if (a[nx][ny] == '#') goto oo;
            if (dis[nx][ny][c] > w) Q.emplace(-(dis[nx][ny][c] = w), c, nx, ny);
        }
        oo:
        if (dis[x][y][!c] > w+1) Q.emplace(-(dis[x][y][!c] = w+1), !c, x, y);
    }
    int ans = min(dis[ex][ey][0], dis[ex][ey][1]);
    cout << (ans == INT_MAX ? -1 : ans) << '\n';
}