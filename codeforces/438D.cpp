#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

ll seg[4*mxN], mx[4*mxN], a[mxN];

void build(int l, int r, int u) {
    if (l == r) seg[u] = a[l], mx[u] = a[l];
    else {
        int m = l + (r-l)/2;
        build(l, m, u<<1);
        build(m+1, r, u<<1|1);
        seg[u] = seg[u<<1] + seg[u<<1|1];
        mx[u] = max(mx[u<<1], mx[u<<1|1]);
    }
}

ll qr(int l, int r, int x, int y, int u) {
    if (r < x || y < l) return 0;
    else if (x <= l && r <= y) return seg[u];
    else {
        int m = l + (r-l)/2;
        return qr(l, m, x, y, u<<1) + qr(m+1, r, x, y, u<<1|1);
    }
}

void upd1(int l, int r, int x, int y, ll k, int u) {
    if (r < x || y < l || mx[u] < k) return;
    else if (l == r) a[l] %= k, seg[u] = a[l], mx[u] = a[l];
    else {
        int m = l + (r-l)/2;
        upd1(l, m, x, y, k, u<<1);
        upd1(m+1, r, x, y, k, u<<1|1);
        seg[u] = seg[u<<1] + seg[u<<1|1];
        mx[u] = max(mx[u<<1], mx[u<<1|1]);
    }
}

void upd2(int l, int r, int x, ll k, int u) {
    if (l == r) a[l] = k, seg[u] = a[l], mx[u] = a[l];
    else {
        int m = l + (r-l)/2;
        if (m >= x) upd2(l, m, x, k, u<<1);
        else upd2(m+1, r, x, k, u<<1|1);
        seg[u] = seg[u<<1] + seg[u<<1|1];
        mx[u] = max(mx[u<<1], mx[u<<1|1]);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 1);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r; cin >> l >> r;
            cout << qr(1, n, l, r, 1) << '\n';
        } else if (t == 2) {
            int l, r; ll x; cin >> l >> r >> x;
            upd1(1, n, l, r, x, 1);
        } else {
            int x; ll k;
            cin >> x >> k;
            upd2(1, n, x, k, 1);
        }
    }
}