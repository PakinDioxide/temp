#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    ll mn = LLONG_MAX, mx = LLONG_MIN;
    for (ll i = 0, x, y; i < n; i++) cin >> x >> y, mn = min(mn, x+y), mx = max(mx, x+y);
    cout << 2*(mx - mn) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}