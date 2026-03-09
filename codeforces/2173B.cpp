#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

void solve() {
    int n; cin >> n;
    int a[n]; for (auto &e : a) cin >> e;
    int b[n]; for (auto &e : b) cin >> e;
    int mx[n], mn[n];
    mx[0] = max(-a[0], b[0]), mn[0] = min(-a[0], b[0]);
    for (int i = 1; i < n; i++) {
        mx[i] = max({mx[i-1]-a[i], b[i]-mx[i-1], mn[i-1]-a[i], b[i]-mn[i-1]});
        mn[i] = min({mx[i-1]-a[i], b[i]-mx[i-1], mn[i-1]-a[i], b[i]-mn[i-1]});
    }
    cout << mx[n-1] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}