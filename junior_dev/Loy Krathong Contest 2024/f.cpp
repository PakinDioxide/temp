#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll n;
    cin >> n;
    ll a[n+1], sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    ll k = sum/2;
    ll dp[n+1][k+1];
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int i = 0; i <= k; i++) dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i-1][j];
            if (a[i] <= j) dp[i][j] = max(dp[i][j], dp[i-1][j-a[i]] + a[i]);
        }
    }
    cout << sum - dp[n][k] - dp[n][k];
}