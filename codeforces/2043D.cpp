#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll l, r, g;
    cin >> l >> r >> g;
    ll p = l + ((g-l%g)%g), q = r - (r%g);
    p/=g, q/=g;
    if (p == q && p != 1) {cout << "-1 -1\n"; return;}
    for (ll k = (q-p); k >= 0; k--) {
        for (ll i = p; i + k <= q; i++) {
            ll j = i+k;
            if (__gcd(i, j) == 1) {cout << g*i << ' ' << g*j << '\n'; return;}
            if (k == 0) break;
        }
    }
    cout << "-1 -1\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}