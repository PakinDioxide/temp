#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int k = n%2, dp[n][n];
    for (int i = 0; i < n; i++) dp[i][i] = k ? a[i] : -a[i];
    for (int l = 1; l < n; l++) {
        for (int i = 0; i+l < n; i++) {
            int j = i+l;
            if (k != l%2) dp[i][j] = max(dp[i][j-1] + a[j], dp[i+1][j] + a[i]);
            else dp[i][j] = min(dp[i][j-1] - a[j], dp[i+1][j] - a[i]);
        }
    }
    cout << dp[0][n-1];
}