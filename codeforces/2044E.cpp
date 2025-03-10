#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll k, l, r, x, y, ans = 0;
    cin >> k >> l >> r >> x >> y;
    ans = max(0LL, min(r, y) - max(l, x) + 1);
    for (ll m = k; l*m <= y; m*=k) {
        if (k == 1) break;
        // cout << m << '\n';
        ll p = min(r*m, y), q = max(x, l*m);
        // cout << p << ' ' << q << ' ' << m << '\n';
        ll pl = p/m - (q-1)/m;
        if (pl > 0) ans += pl;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}