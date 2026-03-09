#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

ll n, q, fen[mxN][3], a[mxN];

void upd(int idx, ll x, int k) { for (int i = idx; i <= n; i += i & -i) fen[i][k] += x; }
ll qr(int idx, int k) { ll x = 0; for (int i = idx; i > 0; i -= i & -i) x += fen[i][k]; return x; }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    auto UPD = [&] (int idx, ll x) {
        upd(idx, x-a[idx], 0);
        upd(idx, (x-a[idx])*idx, 1);
        upd(idx, (x-a[idx])*(n-idx+1), 2);
        a[idx] = x;
    };
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        UPD(i, x);
    }
    auto QR = [&] (int l, int r, int k) {
        if (r < l) return 0LL;
        return qr(r, k) - qr(l-1, k);
    };
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int idx; ll x; cin >> idx >> x;
            UPD(idx, x);
        } else {
            int l, r, k; cin >> l >> r >> k;
            int x = min(k, (r-l+1) - k + 1);
            // cout << (QR(l, l+x-2, 1) - (l-1)*QR(l, l+x-2, 0)) << ' ';
            // cout << (QR(r-x+2, r, 2) - (n-r)*QR(r-x+2, r, 0)) << ' ';
            cout << (QR(l, l+x-2, 1) - (l-1)*QR(l, l+x-2, 0)) + (QR(r-x+2, r, 2) - (n-r)*QR(r-x+2, r, 0)) + (x)*(QR(l+x-1, r-x+1, 0)) << '\n';
        }
    }
}

