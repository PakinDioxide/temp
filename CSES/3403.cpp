/*
    author  : 
    created : 25/06/2025 18:49
    task    : 3403
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    int a[n], b[m]; for (auto &e : a) cin >> e; for (auto &e : b) cin >> e;
    pair <int, int> p[n][m];
    int dp[n][m];
    for (int i = 1; i < n; i++) {
        if (a[i] == b[0]) dp[i][0] = 1, p[i][0] = {-1, -1};
        else dp[i][0] = dp[i-1][0], p[i][0] = {-1, 0};
    }
    for (int i = 1; i < m; i++) {
        if (a[0] == b[i]) dp[0][i] = 1, p[0][i] = {-1, -1};
        else dp[0][i] = dp[0][i-1], p[0][i] = {-1, 0};
    }
    if (a[0] == b[0]) dp[0][0] = 1, p[0][0] = {-1, -1};
    else dp[0][0] = 0, p[0][0] = {-1, 0};
    for (int i = 1; i < n; i++) for (int j = 1; j < m; j++) {
        if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1, p[i][j] = {-1, -1};
        else if (dp[i-1][j] >= dp[i][j-1]) dp[i][j] = dp[i-1][j], p[i][j] = {-1, 0};
        else dp[i][j] = dp[i][j-1], p[i][j] = {0, -1};
    }
    cout << dp[n-1][m-1] << '\n';
    int x = n-1, y = m-1;
    vector <int> k;
    while (x >= 0 && y >= 0) {
        if (p[x][y] == make_pair(-1, -1)) k.emplace_back(a[x]);
        int tx = x+p[x][y].first, ty = y+p[x][y].second;
        x = tx, y = ty;
    }
    reverse(k.begin(), k.end());
    for (auto &e : k) cout << e << ' ';
    cout << '\n';
}