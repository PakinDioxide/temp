#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, v;
    cin >> n >> m >> v;
    ll a[n+1];
    a[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll dp[n+1], ds[n+2], sum = 0;
    dp[0] = ds[n+1] = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        dp[i] = dp[i-1];
        if (sum >= v) dp[i]++, sum = 0;
    }
    sum = 0;
    for (int i = n; i > 0; i--) {
        sum += a[i];
        ds[i] = ds[i+1];
        if (sum >= v) ds[i]++, sum = 0;
    }
    ll mx = -1, l = 0, r = 1, ssum = 0;
    while (r <= n+1) {
        if (dp[l] + ds[r] >= m) {mx = max(mx, ssum); ssum += a[r]; r++;}
        else l++, ssum -= a[l];
    }
    cout << mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}