#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll l, r, k, p, po, f;
    cin >> l >> r >> k >> po >> f;
    if (2*k >= po) {cout << -1 << '\n'; return;}
    ll n = r-l+1, val = 0;
    p = po - 2*k;
    ll ans = ceil((double) n/p);
    for (ll i = 1; i < ceil((double) n/po); i++) {
        val += i;
        ll nl = n - po*i + 2*val*f;
        ans = max(ans, (ll) (i + 1 + ceil((double) (nl-po)/p)));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}