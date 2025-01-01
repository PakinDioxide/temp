// PakinDioxide
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll a[n+5], dp[n+5][2], dp2[n+5][2];
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[0][0] = dp[0][1] = 0;
    dp[1][0] = 0, dp[1][1] = a[1];
    dp[2][0] = a[1], dp[2][1] = 0;
    for (int i = 3; i <= n; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        if (i < 2) dp[i][1] = a[i];
        else dp[i][1] = dp[i-1][0] + a[i];
    }
    dp2[0][0] = dp2[0][1] = 0;
    dp2[1][0] = 0, dp2[1][1] = 0;
    dp2[2][0] = 0, dp2[2][1] = a[2];
    for (int i = 3; i <= n; i++) {
        dp2[i][0] = max(dp2[i-1][0], dp2[i-1][1]);
        if (i < 2) dp2[i][1] = a[i];
        else dp2[i][1] = dp2[i-1][0] + a[i];
    }
    cout << max({dp[n][0], dp2[n][0], dp2[n][1]});
}