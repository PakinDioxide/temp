#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

ll seg[4*mxN], fen[mxN], a[mxN];

void build(int l, int r, int u) {
    if (l == r) seg[u] = a[l];
    else {
        int m = l + (r-l)/2;
        build(l, m, u<<1);
        build(m+1, r, u<<1|1);
        seg[u] = min(seg[u<<1], seg[u<<1|1]);
    }
}

void upd(int l, int r, int idx, int u) {
    if (l == r) seg[u] = a[l];
    else {
        int m = l + (r-l)/2;
        if (m >= idx) upd(l, m, idx, u<<1);
        else upd(m+1, r, idx, u<<1|1);
        seg[u] = min(seg[u<<1], seg[u<<1|1]);
    }
}

ll qr(int l, int r, int x, int y, int u) {
    if (x <= l && r <= y) return seg[u];
    else {
        int m = l + (r-l)/2; ll ans = LLONG_MAX;
        if (m >= x) ans = min(ans, qr(l, m, x, y, u<<1));
        if (m+1 <= y) ans = min(ans, qr(m+1, r, x, y, u<<1|1));
        return ans;
    }
}

int n;

void UPD(int idx, ll x) { for (int i = idx; i <= n; i += i & -i) fen[i] += x; }
ll QR(int idx) { ll x = 0; for (int i = idx; i > 0; i -= i & -i) x += fen[i]; return x; }


void solve() {
    int q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) fen[i] = 0;
    build(1, n, 1);
    for (int i = 1; i <= n; i++) UPD(i, a[i]);
    if (n % 2 == 0) {
        ll A = qr(1, n, 1, n/2, 1), B = qr(1, n, n/2+1, n, 1);
        cout << QR(n/2) - A + max(A, B) << ' ' << QR(n) - QR(n/2) - B + min(A, B) << '\n';
    } else {
        ll A = qr(1, n, 1, n/2+1, 1), B = qr(1, n, n/2+2, n, 1);
        cout << QR(n/2+1) - A + min(A, B) << ' ' << QR(n) - QR(n/2+1) - B + max(A, B) << '\n';
    }
    while (q--) {
        int idx; ll x;
        cin >> idx >> x;
        UPD(idx, x - a[idx]);
        a[idx] = x;
        upd(1, n, idx, 1);
        if (n % 2 == 0) {
            ll A = qr(1, n, 1, n/2, 1), B = qr(1, n, n/2+1, n, 1);
            cout << QR(n/2) - A + max(A, B) << ' ' << QR(n) - QR(n/2) - B + min(A, B) << '\n';
        } else {
            ll A = qr(1, n, 1, n/2+1, 1), B = qr(1, n, n/2+2, n, 1);
            cout << QR(n/2+1) - A + min(A, B) << ' ' << QR(n) - QR(n/2+1) - B + max(A, B) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

