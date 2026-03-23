#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    ll a[n]; for (auto &e : a) cin >> e;
    sort(a, a+n);
    ll ans = 0;
    for (int i = 1; i < n; i++) ans += max(abs(a[i] - a[0]), abs(a[n-1] - a[i]));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

