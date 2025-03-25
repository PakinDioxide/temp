#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    ll dp[n+1];
    dp[n] = 0;
    for (int i = n-1; i >= 0; i--) {
        dp[i] = min(dp[i+1]*2 + a[i], dp[i+1] + b[i]);
    }
    cout << dp[0] << '\n';
}