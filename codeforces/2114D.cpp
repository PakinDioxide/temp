/*
    author  : PakinDioxide
    created : 26/05/2025 21:49
    task    : 2114D
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    vector <pair <ll, ll>> a(n); for (auto &[x, y] : a) cin >> x >> y;
    if (n == 1) { cout << 1 << '\n'; return; }
    vector <ll> xc, yc; for (auto &[x, y] : a) xc.emplace_back(x), yc.emplace_back(y);
    sort(xc.begin(), xc.end()), sort(yc.begin(), yc.end());
    ll mn = LLONG_MAX;
    for (auto &[x, y] : a) {
        ll xw = (x == xc[n-1] ? xc[n-2] : xc[n-1]) - (x == xc[0] ? xc[1] : xc[0]) + 1, yw = (y == yc[n-1] ? yc[n-2] : yc[n-1]) - (y == yc[0] ? yc[1] : yc[0]) + 1;
        if (xw*yw > n-1) mn = min(mn, xw*yw);
        else mn = min(mn, xw*yw+min(xw, yw));
    }
    cout << mn << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}