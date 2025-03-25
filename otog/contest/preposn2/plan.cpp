/*
    author  : PakinDioxide
    created : 23/03/2025 18:27
    task    : plan
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair <int, int> d[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int k, n, m;
    vector <int> v;
    cin >> k >> n >> m;
    for (int l = 0; l < k; l++) {
        string a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int vis[n][m], mx = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (a[i][j] == '#' || vis[i][j]) continue;
            int cnt = 0;
            queue <pair <int, int>> q;
            q.emplace(i, j);
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                if (vis[x][y]) continue;
                vis[x][y] = 1;
                cnt += (a[x][y] == 'X');
                for (auto [dx, dy] : d) {
                    int nx = x+dx, ny = y+dy;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] || a[nx][ny] == '#') continue;
                    q.emplace(nx, ny);
                }
            }
            mx = max(mx, cnt);
        }
        v.push_back(mx);
    }
    sort(v.begin(), v.end());
    int p[k+1];
    p[0] = 0;
    for (int i = k-1; i >= 0; i--) p[k-i] = p[k-i-1] + v[i];
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int idx = lower_bound(p, p+k+1, x) - p;
        if (idx == k+1) cout << -1 << '\n';
        else cout << idx << '\n';
    }
}