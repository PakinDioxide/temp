#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    ll a[n];
    for (auto &e : a) cin >> e;
    for (int i = 1; i < n; i++) a[i] += a[i-1];
    ll x, y; cin >> x >> y;
    for (int i = 0; i < n; i++) if (a[i] >= x && a[i] <= y && a[n-1] - a[i] >= x && a[n-1] - a[i] <= y) { cout << i+2 << '\n'; return; }
    cout << 0 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // int t; cin >> t;
    int t = 1;
    while (t--) solve();
}