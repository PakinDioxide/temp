#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    ll dp[n+1][n+1], a[n+1], p[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i], p[i] = a[i] + p[i-1];
    for (int i = 1; i <= n; i++) dp[i][i] = 0;
    for (int l = 1; l <= n; l++) {
        for (int i = 1; i+l <= n; i++) {
            int j = i+l;
            dp[i][j] = LLONG_MAX;
            for (int k = i; k < j; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
            dp[i][j] += p[j] - p[i-1];
        }
    }
    cout << dp[1][n] << '\n';
}   