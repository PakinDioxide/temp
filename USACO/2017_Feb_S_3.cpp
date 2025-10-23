/*
    author  : PakinDioxide
    created : 23/03/2025 01:18
    task    : 2017_Feb_S_3
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair <int, int> d[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    int n, k, r;
    cin >> n >> k >> r;
    int vis[n+1][n+1], idx = 0;
    map <tuple <int, int, int, int>, int> road;
    memset(vis, 0, sizeof(vis));
    while (r--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        road[{a, b, c, d}] = road[{c, d, a, b}] = 1;
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        if (vis[i][j]) continue;
        ++idx;
        queue <pair <int, int>> q;
        q.emplace(i, j);
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (vis[x][y]) continue;
            vis[x][y] = idx;
            for (auto [dx, dy] : d) {
                int nx = x+dx, ny = y+dy;
                if (nx <= 0 || nx > n || ny <= 0 || ny > n || road[{x, y, nx, ny}]) continue;
                q.emplace(nx, ny);
            }
        }
    }
    map <int, int> ans;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        ans[vis[x][y]]++;
    }
    int cnt = 0;
    for (auto &[x, y] : ans) cnt += y*(k-y);
    cout << cnt/2 << '\n';
}