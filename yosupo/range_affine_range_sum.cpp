/*
    author  : PakinDioxide
    created : 23/05/2025 22:20
    task    : range_affine_range_sum
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mxN = 5e5+5, MOD = 998244353;

struct T {
    ll val, lza, lzc, sz;
    void rst(ll x) {
        val = x, lza = 1, lzc = 0, sz = 1;
    }
    void mod() {
        val %= MOD, lza %= MOD, lzc %= MOD;
    }
};

int n, q;
ll a[mxN];
T seg[4*mxN];

void push(int u, int l, int r) {
    seg[l].lza *= seg[u].lza, seg[l].lzc *= seg[u].lza, seg[l].lzc += seg[u].lzc;
    seg[l].val *= seg[u].lza, seg[l].val += seg[u].lzc * seg[l].sz;
    seg[l].mod();
    seg[r].lza *= seg[u].lza, seg[r].lzc *= seg[u].lza, seg[r].lzc += seg[u].lzc;
    seg[r].val *= seg[u].lza, seg[r].val += seg[u].lzc * seg[r].sz;
    seg[r].mod();
    seg[u].lza = 1, seg[u].lzc = 0;
}

void build(int l, int r, int node) {
    seg[node].rst(0);
    if (l == r) seg[node].rst(a[l]);
    else {
        int mid = l + (r-l)/2;
        build(l, mid, node<<1);
        build(mid+1, r, node<<1|1);
        seg[node].val = seg[node<<1].val + seg[node<<1|1].val;
        seg[node].sz = seg[node<<1].sz + seg[node<<1|1].sz;
        seg[node].mod();
    }
}

void upd(int l, int r, int x, int y, ll a, ll c, int node) {
    if (x <= l && r <= y) seg[node].lza *= a, seg[node].lzc *= a, seg[node].lzc += c, seg[node].val *= a, seg[node].val += c*seg[node].sz, seg[node].mod();
    else {
        push(node, node<<1, node<<1|1);
        int mid = l + (r-l)/2;
        if (mid >= x) upd(l, mid, x, y, a, c, node<<1);
        if (mid+1 <= y) upd(mid+1, r, x, y, a, c, node<<1|1);
        seg[node].val = seg[node<<1].val + seg[node<<1|1].val;
        seg[node].mod();
    }
}

ll qr(int l, int r, int x, int y, int node) {
    if (x <= l && r <= y) return seg[node].val;
    else {
        push(node, node<<1, node<<1|1);
        int mid = l + (r-l)/2; ll v = 0;
        if (mid >= x) v += qr(l, mid, x, y, node<<1);
        if (mid+1 <= y) v += qr(mid+1, r, x, y, node<<1|1);
        return v % MOD;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    build(0, n-1, 1);
    while (q--) {
        int t; cin >> t;
        if (t == 0) {
            int l, r; ll a, c; cin >> l >> r >> a >> c;
            upd(0, n-1, l, r-1, a, c, 1);
        } else {
            int l, r; cin >> l >> r;
            cout << qr(0, n-1, l, r-1, 1) << '\n';
        }
    }
}