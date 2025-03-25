/*
    author  : PakinDioxide
    created : 22/03/2025 21:30
    task    : horse
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair <int, int> d[4] = {{1, -2}, {1, 2}, {2, -1}, {2, 1}};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int dp[n+1][n+1], a[n+1][n+1], aa[n+1][n+1], w, b;
    memset(a, 0, sizeof(a));
    memset(aa, 0, sizeof(aa));
    memset(dp, 0, sizeof(dp));
    cin >> w >> b;
    pair <int, int> WWWWWWW[w];
    for (auto &[x, y] : WWWWWWW) cin >> x >> y, aa[x][y] = 1;
    while (b--) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    for (int i = n; i > 0; i--) for (int j = 1; j <= n; j++) {
        for (auto [dx, dy] : d) {
            int nx = i+dx, ny = j+dy;
            if (nx <= 0 || nx > n || ny <= 0 || ny > n || aa[nx][ny]) continue;
            dp[i][j] = max(dp[i][j], dp[nx][ny]);
        }
        dp[i][j] += a[i][j];
    }
    // for (int i = n; i > 0; i--) {
    //     for (int j = 1; j <= n; j++) cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
    vector <pair <int, int>> ans;
    int mx = 0;
    for (auto &[x, y] : WWWWWWW) {
        if (dp[x][y] > mx) ans.clear(), mx = dp[x][y];
        if (dp[x][y] >= mx) ans.emplace_back(x, y);
    }
    cout << mx << ' ' << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
}