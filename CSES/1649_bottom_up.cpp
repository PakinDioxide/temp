/*
    author  : PakinDioxide
    created : 18/05/2025 02:17
    task    : 1649_bottom_up
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int n, q;
ll seg[2*mxN], a[mxN];

void upd(int idx, ll x) {
    idx += n, seg[idx] = x, idx /= 2;
    while (idx) seg[idx] = min(seg[idx*2], seg[idx*2+1]), idx /= 2;
}

ll qr(int x, int y) {
    ll l = LLONG_MAX, r = LLONG_MAX;
    x += n, y += n+1;
    while (x < y) {
        if (x & 1) l = min(l, seg[x++]);
        if (y & 1) r = min(r, seg[--y]);
        x /= 2, y /= 2;
    }
    return min(l, r);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i], upd(i, a[i]);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int idx; ll x; cin >> idx >> x;
            upd(idx, x);
        } else {
            int x, y; cin >> x >> y;
            cout << qr(x, y) << '\n';
        }
    }
}