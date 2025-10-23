#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    ll l = LLONG_MIN, r = LLONG_MAX;
    while (n--) {
        ll c, d; cin >> c >> d;
        if (d == 2) {
            if (l >= 1900) { cout << "Impossible\n"; return; }
            r = min(r, (ll) 1899);
        } else if (d == 1) {
            if (r < 1900) { cout << "Impossible\n"; return; }
            l = max(l, (ll) 1900);
        }
        if (l > LLONG_MIN) l += c;
        if (r < LLONG_MAX) r += c;
    }
    if (r == LLONG_MAX) cout << "Infinity\n";
    else cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // int t; cin >> t;
    int t = 1;
    while (t--) solve();
}