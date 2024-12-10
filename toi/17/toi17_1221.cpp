#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    long long dp[n][n][2];
    for (int i = 0; i < n; i++) {for (int j = 0; j < n; j++) {dp[i][j][0] = INT_MAX; dp[i][j][1] = 0;} cin >> dp[i][i][0]; dp[i][i][1] = 1;}
    for (int i = 0; i < m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        dp[u][v][0] = dp[v][u][0] = w;
        dp[u][v][1] = dp[v][u][1] = 2;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j][0] >= dp[i][i][0] + dp[j][j][0]) {
                dp[i][j][0] = dp[i][i][0] + dp[j][j][0];
                dp[i][j][1] = 2;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j][0] > dp[i][k][0] + dp[k][j][0] || (dp[i][j][0] == dp[i][k][0] + dp[k][j][0] && dp[i][j][1] < dp[i][k][1] + dp[k][j][1])) {
                    dp[i][j][0] = dp[i][k][0] + dp[k][j][0];
                    dp[i][j][1] = dp[i][k][1] + dp[k][j][1];
                }
            }
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << dp[a][b][0] << ' ' << dp[a][b][1] << '\n';
    }
}