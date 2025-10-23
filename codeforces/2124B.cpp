/*
    author  : 
    created : 06/07/2025 21:40
    task    : 2124B
*/
#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

void solve() {
    int n; cin >> n;
    int a[n+2]; for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = a[n+1] = INT_MAX;
    int mn = a[1], s = a[1], ans = INT_MAX;
    int mx = 0, idx[n+1];
    for (int i = 1; i <= n; i++) {
        if (a[i] >= mx) idx[i] = i, mx = a[i];
        else idx[i] = idx[i-1];
    }
    for (int i = 2; i <= n; i++) {
        ans = min(ans, s + a[i]*(idx[i-1] == 1));
        mn = min(mn, a[i]);
        s += mn;
    }
    cout << min(s, ans) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}