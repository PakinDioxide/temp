/*
    author  : PakinDioxide
    created : 24/05/2025 00:51
    task    : 2015_Dec_P_3
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

struct T {
    ll s, mn, lz, sz;
    T operator+(const T &o) {
        return T{s+o.s, min(mn, o.mn), 0, sz+o.sz};
    }
};

int n, q;
ll a[mxN];
T seg[4*mxN];

void push(int u, int l, int r) {
    seg[l].s += seg[u].lz*seg[l].sz, seg[l].mn += seg[u].lz, seg[l].lz += seg[u].lz;
    seg[r].s += seg[u].lz*seg[r].sz, seg[r].mn += seg[u].lz, seg[r].lz += seg[u].lz;
    seg[u].lz = 0;
}

void build(int l, int r, int node) {
    if (l == r) seg[node].mn = seg[node].s = a[l], seg[node].lz = 0, seg[node].sz = 1;
    else {
        int mid = l + (r-l)/2;
        build(l, mid, node<<1);
        build(mid+1, r, node<<1|1);
        seg[node] = seg[node<<1] + seg[node<<1|1];
    }
}

void upd(int l, int r, int x, int y, ll k, int node) {
    if (x <= l && r <= y) seg[node].lz += k, seg[node].s += k*seg[node].sz, seg[node].mn += k;
    else {
        push(node, node<<1, node<<1|1);
        int mid = l + (r-l)/2;
        if (mid >= x) upd(l, mid, x, y, k, node<<1);
        if (mid+1 <= y) upd(mid+1, r, x, y, k, node<<1|1);
        seg[node] = seg[node<<1] + seg[node<<1|1];
    }
}

T qr(int l, int r, int x, int y, int node) {
    if (x <= l && r <= y) return seg[node];
    else {
        push(node, node<<1, node<<1|1);
        int mid = l + (r-l)/2; T v = T{0, LLONG_MAX, 0, 0};
        if (mid >= x) v = v + qr(l, mid, x, y, node<<1);
        if (mid+1 <= y) v = v + qr(mid+1, r, x, y, node<<1|1);
        return v;
    }
}

int main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 1);
    while (q--) {
        char x; cin >> x;
        if (x == 'M') {
            int l, r; cin >> l >> r;
            cout << qr(1, n, l, r, 1).mn << '\n';
        } else if (x == 'S') {
            int l, r; cin >> l >> r;
            cout << qr(1, n, l, r, 1).s << '\n';
        } else {
            int l, r; ll x; cin >> l >> r >> x;
            upd(1, n, l, r, x, 1);
        }
    }
}