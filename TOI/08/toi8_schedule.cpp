#include <bits/stdc++.h>

using namespace std;

int k, n;
pair <int, int> cal(pair <int, int> a, int b) {
    if (a.second + b <= k) return {a.first, a.second + b};
    else return  {a.first+1, b};
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> k >> n;
    int a[n+1], b[n+1];
    pair <int, int> dp[n+1][n+1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    a[0] = b[0] = 0;
    dp[0][0] = {1, 0};
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 && j == 0) continue;
            if (i > 0 && j > 0) {
                dp[i][j] = min(cal(dp[i-1][j], a[i]), cal(dp[i][j-1], b[j]));
            } else if (i > 0) dp[i][j] = cal(dp[i-1][j], a[i]);
            else dp[i][j] = cal(dp[i][j-1], b[j]);
        }
    }
    cout << dp[n][n].first << '\n' << dp[n][n].second;
}