#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int dp[n][m];
    string a[n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) cin >> a[i];
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#') continue;
            if (i > 0) dp[i][j] += dp[i-1][j];
            if (j > 0) dp[i][j] += dp[i][j-1];
            dp[i][j]%=1000000007;
        }
    }
    cout << dp[n-1][m-1];
}