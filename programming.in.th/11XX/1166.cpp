/*
    author  : PakinDioxide
    created : 19/04/2025 19:01
    task    : 1166
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair <int, int> d[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    char a[n+2][m+2];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
    int vis[n+2][m+2], ok[n+2][m+2], mx = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        int k = (a[i][j] != '#');
        for (auto [dx, dy] : d) {
            int nx = i+dx, ny = j+dy;
            k = min(k, (int)(a[nx][ny] != '#'));
        }
        ok[i][j] = k;
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (ok[i][j] && !vis[i][j]) {
        int cnt = 0;
        queue <pair <int, int>> q;
        q.emplace(i, j);
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            cnt++;
            for (auto [dx, dy] : d) {
                int nx = x+dx, ny = y+dy;
                if (nx < 1 || nx > n || ny < 1 || ny > m || !ok[nx][ny]) continue;
                q.emplace(nx, ny);
            }
        }
        mx = max(mx, cnt);
    }
    cout << mx << '\n';
}