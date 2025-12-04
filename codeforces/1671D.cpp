#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    ll a[n], mx = 0; for (auto &e : a) cin >> e, mx = max(mx, e);
    ll x1 = LLONG_MAX, x2 = LLONG_MAX;
    if (mx < x) {
        mx = x;
        x1 = min(mx - a[0], mx - a[n-1]);
        for (int i = 0; i < n-1; i++) x1 = min(x1, 2*(mx - max(a[i], a[i+1])));
    } else x1 = 0;
    x2 = min(a[0] - 1, a[n-1] - 1);
    for (int i = 0; i < n-1; i++) x2 = min(x2, 2*(min(a[i], a[i+1]) - 1));
    ll c = 0;
    for (int i = 0; i < n-1; i++) c += abs(a[i] - a[i+1]);
    cout << c + x1 + x2 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}