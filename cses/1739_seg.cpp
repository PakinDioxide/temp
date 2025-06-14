// TLE
/*
    author  : PakinDioxide
    created : 28/05/2025 23:40
    task    : 1739_seg
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e3+5;

struct T {
    ll s[4*mxN];
    T() { memset(s, 0, sizeof(s)); }
    void upd(int l, int r, int idx, ll x, int u) {
        if (l == r) s[u] = x;
        else {
            int mid = l + (r-l)/2;
            if (mid >= idx) upd(l, mid, idx, x, u<<1);
            else upd(mid+1, r, idx, x, u<<1|1);
            s[u] = s[u<<1] + s[u<<1|1];
        }
    }
    ll qr(int l, int r, int x, int y, int u) {
        if (x <= l && r <= y) return s[u];
        else {
            int mid = l + (r-l)/2; ll k = 0;
            if (mid >= x) k += qr(l, mid, x, y, u<<1);
            if (mid+1 <= y) k += qr(mid+1, r, x, y, u<<1|1);
            return k;
        }
    }
};

int n, q;
ll a[mxN][mxN];
T s[4*mxN];

void upd(int l, int r, int x, int y, ll v, int u) {
    if (l == r) s[u].upd(1, n, y, v, 1);
    else {
        int mid = l + (r-l)/2;
        if (mid >= x) upd(l, mid, x, y, v, u<<1);
        else upd(mid+1, r, x, y, v, u<<1|1);
        s[u].upd(1, n, y, s[u<<1].qr(1, n, y, y, 1) + s[u<<1|1].qr(1, n, y, y, 1), 1);
    }
}
ll qr(int l, int r, int x1, int y1, int x2, int y2, int u) {
    if (x1 <= l && r <= x2) return s[u].qr(1, n, y1, y2, 1);
    else {
        int mid = l + (r-l)/2; ll k = 0;
        if (mid >= x1) k += qr(l, mid, x1, y1, x2, y2, u<<1);
        if (mid+1 <= x2) k += qr(mid+1, r, x1, y1, x2, y2, u<<1|1);
        return k;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) { char x; cin >> x; a[i][j] = (x == '*'); upd(1, n, i, j, a[i][j], 1); }
    while (q--) {
        int t; cin >> t;
        if (t == 1) { int x, y; cin >> x >> y; upd(1, n, x, y, (a[x][y] = !a[x][y]), 1); }
        else { int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2; cout << qr(1, n, x1, y1, x2, y2, 1) << '\n'; }
    }
}