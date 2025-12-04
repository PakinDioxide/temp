/*
    author  : PakinDioxide
    created : 10/04/2025 19:45
    task    : HORRIBLE_fenwick
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, q;
    cin >> n >> q;
    vector <ll> fen[2];
    fen[0].resize(n+5), fen[1].resize(n+5);
    auto upd = [&] (int idx, ll x, int k) { for (int i = idx; i <= n; i += i & -i) fen[k][i] += x; };
    auto qr = [&] (int idx, int k) { ll s = 0; for (int i = idx; i > 0; i -= i & -i) s += fen[k][i]; return s;};
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            ll l, r, x;
            cin >> l >> r >> x;
            upd(l, x, 0); upd(r+1, -x, 0);
            upd(l, l*x, 1); upd(r+1, -(r+1)*x, 1);
        } else {
            ll l, r;
            cin >> l >> r;
            ll ans = 0;
            ans += (r+1)*qr(r, 0) - qr(r, 1);
            ans -= l*qr(l-1, 0) - qr(l-1, 1);
            cout << ans << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}