/*
    author  : PakinDioxide
    created : 24/03/2025 12:44
    task    : 1194
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair <int, int> d[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    string a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int dis[n][m], vis[n][m];
    queue <pair <int, int>> q;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {if (a[i][j] == 'M') dis[i][j] = 0, q.emplace(i, j); else dis[i][j] = INT_MAX;}
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (vis[x][y]) continue;
        vis[x][y] = 1;
        for (auto [dx, dy] : d) {
            int nx = dx+x, ny = dy+y;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == '#') continue;
            if (dis[nx][ny] > dis[x][y] + 1) {
                dis[nx][ny] = dis[x][y] + 1;
                q.emplace(nx, ny);
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    pair <int, int> par[n][m];
    memset(par, 0, sizeof(par));
    int sx, sy;
    queue <tuple <int, int, int>> Q;
    for (int i = 0; i < n; i++) {for (int j = 0; j < m; j++) if (a[i][j] == 'A') {Q.emplace(0, i, j); sx = i, sy = j; break;} if (Q.size()) break;}
    while (!Q.empty()) {
        auto [c, x, y] = Q.front();
        Q.pop();
        if (dis[x][y] <= c || vis[x][y]) continue;
        vis[x][y] = 1;
        if (x == 0 || x == n-1 || y == 0 || y == m-1) {
            cout << "YES\n";
            cout << c << '\n';
            string s = "";
            while (x != sx || y != sy) {
                auto [dx, dy] = par[x][y];
                if (dx == 0 && dy == 1) s += 'R';
                else if (dx == 0 && dy == -1) s += 'L';
                else if (dx == 1 && dy == 0) s += 'D';
                else s += 'U';
                x -= dx, y -= dy;
            }
            reverse(s.begin(), s.end());
            cout << s << '\n';
            return 0;
        }
        for (auto [dx, dy] : d) {
            int nx = dx+x, ny = dy+y;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == '#') continue;
            if (!vis[nx][ny]) par[nx][ny] = {dx, dy}, Q.emplace(c+1, nx, ny);
        }
    }
    cout << "NO\n";
}