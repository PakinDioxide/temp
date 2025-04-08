/*
    author  : PakinDioxide
    created : 22/03/2025 14:54
    task    : 2019_Jan_S_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair <int, int> d[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    int n;
    cin >> n;
    int a[n+2][n+2], vis[n+2][n+2];
    memset(a, 0, sizeof(a));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) a[i][j+1] = (s[j] == '#');
    }
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        if (vis[i][j] || a[i][j] == 0) continue;
        int area = 0, per = 0;
        queue <pair <int, int>> q;
        q.emplace(i, j);
        while (!q.empty()) {
            auto &[x, y] = q.front();
            q.pop();
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            area++;
            for (auto [dx, dy] : d) {
                int nx = x+dx, ny = y+dy;
                if (nx <= 0 || ny <= 0 || nx > n || ny > n || a[nx][ny] == 0) {per++; continue;}
                q.emplace(nx, ny); 
            }
        }
        if (area > ans1) ans1 = area, ans2 = per;
        else if (area == ans1) ans2 = min(ans2, per);
    }
    cout << ans1 << ' ' << ans2 << '\n';
}