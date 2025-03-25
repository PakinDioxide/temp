/*
    author  : PakinDioxide
    created : 17/03/2025 19:28
    task    : 05
*/
#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

pair <int, int> d[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n+1][m+1];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
    int dis[n+1][m+1], vis[n+1][m+1];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) dis[i][j] = LLONG_MAX, vis[i][j] = 0;
    dis[1][1] = a[1][1];
    priority_queue <tuple <ll, int, int>> q;
    q.emplace(a[1][1], 1, 1);
    while (!q.empty()) {
        int ux = get<1>(q.top()), uy = get<2>(q.top());
        q.pop();
        if (vis[ux][uy]) continue;
        vis[ux][uy] = 1;
        // cout << ux << ' ' << uy << '\n';
        for (auto [i, j] : d) {
            if (ux+i < 0 || ux+i > n || uy+j < 0 || uy+j > m) continue;
            if (dis[ux+i][uy+j] > max(dis[ux][uy], a[ux+i][uy+j])) {
                dis[ux+i][uy+j] = max(dis[ux][uy], a[ux+i][uy+j]);
                q.emplace(-dis[ux+i][uy+j], ux+i, uy+j);
            }
        }
    }
    // for (int i = 1; i <= n; i++) {for (int j = 1; j <= m; j++) cout << dis[i][j] << ' '; cout << '\n';}

    cout << dis[n][m] << '\n';
}