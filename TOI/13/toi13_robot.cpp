#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    string a[n];
    int vis[n][m], mov[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue <tuple <int, int, int>> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'X') q.emplace(i, j, 0);
            vis[i][j] = 0;
        }
    }

    int ans = 0, cc = 0;
    
    while (!q.empty()) {
        auto [x, y, c] = q.front();
        q.pop();
        if (a[x][y] == 'A') {
            ans += 2*c;
            cc++;
            a[x][y] = 'E';
        }
        if (vis[x][y]) continue;
        vis[x][y] = 1;
        for (auto [i, j] : mov) {
            if (x+i >= 0 && x+i < n && y+j >= 0 && y+j < m && a[x+i][y+j] != 'W' && a[x+i][y+j] != 'X') {
                q.emplace(x+i, y+j, c+1);
            }
        }
    }

    cout << cc << ' ' << ans;
}