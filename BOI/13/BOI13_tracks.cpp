/*
    author  : PakinDioxide
    created : 06/04/2025 16:36
    task    : BOI13_tracks
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair <int, int> d[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    string a[n];
    for (auto &e : a) cin >> e;
    int dis[n][m];
    for (auto &E : dis) for (auto &e : E) e = INT_MAX;
    dis[0][0] = 1;
    deque <tuple <int, int, int>> q;
    q.emplace_back(1, 0, 0);
    int ans = 0;
    while (!q.empty()) {
        auto [w, x, y] = q.front();
        q.pop_front();
        if (dis[x][y] != w) continue;
        ans = max(ans, w);
        for (auto [dx, dy] : d) {
            int nx = x+dx, ny = y+dy;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == '.') continue;
            if (a[x][y] != a[nx][ny] && dis[nx][ny] > dis[x][y]+1) q.emplace_back((dis[nx][ny] = dis[x][y]+1), nx, ny);
            else if (a[x][y] == a[nx][ny] && dis[nx][ny] > dis[x][y]) q.emplace_front((dis[nx][ny] = dis[x][y]), nx, ny);
        }
    }
    cout << ans << '\n';
}