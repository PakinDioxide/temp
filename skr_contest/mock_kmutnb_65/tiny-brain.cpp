/*
    author  : PakinDioxide
    created : 22/03/2025 20:43
    task    : tiny-brain
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int dp[2][150005], a[n+1], sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum/2; j++) {
            dp[i&1][j] = dp[!(i&1)][j];
            if (j > 0) dp[i&1][j] = max(dp[i&1][j], dp[i&1][j-1]);
            if (j >= a[i]) dp[i&1][j] = max(dp[i&1][j], dp[!(i&1)][j-a[i]] + a[i]);
        }
    }
    cout << sum - 2*dp[n&1][sum/2] << '\n';
}