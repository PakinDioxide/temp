#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int dp[n][n], pos[n][2];
    for (int i = 0; i < n; i++) cin >> pos[i][0] >> pos[i][1];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            dp[i][j] = abs(pos[i][0] - pos[j][0]) + abs(pos[i][1] - pos[j][1]);
            dp[j][i] = dp[i][j];
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[j][i]);
            }
        }
    }
    int ans = 0;
    while (m--) {
        int x;
        cin >> x;
        for (int i = 1; i < n-1; i++) {
            if (c + dp[r][i] > x) {
                c = dp[r][i];
                ans++;
                r = i;
            } else c += dp[r][i];
        }
    }
}