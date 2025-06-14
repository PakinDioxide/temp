/*
    author  : PakinDioxide
    created : 19/05/2025 23:11
    task    : 2014_Dec_G_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n, q;
pair <ll, ll> a[mxN];
ll seg[2][4*mxN];

void upd(int l, int r, int idx, ll x, int node, int k) {
    if (l == r) seg[k][node] = x;
    else {
        int mid = l + (r-l)/2;
        if (mid >= idx) upd(l, mid, idx, x, node<<1, k);
        else upd(mid+1, r, idx, x, node<<1|1, k);
        if (k == 0) seg[k][node] = seg[k][node<<1] + seg[k][node<<1|1];
        else seg[k][node] = min(seg[k][node<<1], seg[k][node<<1|1]);
    }
}

ll qr(int l, int r, int x, int y, int node, int k) {
    if (x > y) return 0;
    else if (x <= l && r <= y) return seg[k][node];
    else {
        int mid = l + (r-l)/2; ll v = 0;
        if (mid >= x) v = (k ? min(v, qr(l, mid, x, y, node<<1, k)) : v + qr(l, mid, x, y, node<<1, k));
        if (mid+1 <= y) v = (k ? min(v, qr(mid+1, r, x, y, node<<1|1, k)) : v + qr(mid+1, r, x, y, node<<1|1, k));
        return v;
    }
}

ll calc(pair <ll, ll> p, pair <ll, ll> q) {
    return abs(p.first-q.first) + abs(p.second-q.second);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    for (int i = 1; i <= n-1; i++) upd(1, n, i, calc(a[i], a[i+1]), 1, 0);
    for (int i = 1; i <= n-2; i++) upd(1, n, i, calc(a[i], a[i+2]) - calc(a[i], a[i+1]) - calc(a[i+1], a[i+2]), 1, 1);
    while (q--) {
        char t; cin >> t;
        if (t == 'Q') {
            int l, r; cin >> l >> r;
            cout << qr(1, n, l, r-1, 1, 0) + qr(1, n, l, r-2, 1, 1) << '\n';
        } else {
            int idx; ll x, y; cin >> idx >> x >> y;
            a[idx] = make_pair(x, y);
            for (int j = max(1, idx-1); j <= min(idx, n-1); j++) upd(1, n, j, calc(a[j], a[j+1]), 1, 0);
            for (int j = max(1, idx-2); j <= min(idx, n-2); j++) upd(1, n, j, calc(a[j], a[j+2]) - calc(a[j], a[j+1]) - calc(a[j+1], a[j+2]), 1, 1);
        }
    }
}