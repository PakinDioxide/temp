#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n+1][3], dp[n+1][3];
    for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i][0];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + a[i][1];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + a[i][2];
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]});
}