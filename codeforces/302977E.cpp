/*
    author  : 
    created : 23/06/2025 18:39
    task    : 302977E
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, k, p; cin >> n >> k >> p;
    ll a[n+1], b[k+1]; for (int i = 1; i <= n; i++) cin >> a[i]; for (int i = 1; i <= k; i++) cin >> b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+k+1);
    ll dp[n+1][k+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        ll mn = LLONG_MAX;
        for (int j = i; j <= k; j++) {
            mn = min(mn, max(dp[i-1][j-1], abs(a[i] - b[j]) + abs(p - b[j])));
            dp[i][j] = mn;
        }
    }
    cout << dp[n][k] << '\n';
}