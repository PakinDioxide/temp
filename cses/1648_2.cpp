/*
    author  : PakinDioxide
    created : 18/05/2025 02:06
    task    : 1648
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int n, q;
ll seg[4*mxN], a[mxN];

void build(int l, int r, int node) {
    if (l == r) seg[node] = a[l];
    else {
        int mid = l + (r-l)/2;
        build(l, mid, node*2+1);
        build(mid+1, r, node*2+2);
        seg[node] = seg[node*2+1] + seg[node*2+2];
    }
}

void upd(int l, int r, int idx, ll x, int node) {
    if (l == r) seg[node] = x;
    else {
        int mid = l + (r-l)/2;
        if (mid >= idx) upd(l, mid, idx, x, node*2+1);
        else upd(mid+1, r, idx, x, node*2+2);
        seg[node] = seg[node*2+1] + seg[node*2+2];
    }
}

ll qr(int l, int r, int x, int y, int node) {
    if (x <= l && r <= y) return seg[node];
    else {
        int mid = l + (r-l)/2; ll s = 0;
        if (mid >= x) s += qr(l, mid, x, y, node*2+1);
        if (mid+1 <= y) s += qr(mid+1, r, x, y, node*2+2);
        return s;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 0);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int idx; ll x; cin >> idx >> x;
            upd(1, n, idx, x, 0);
        } else {
            int x, y; cin >> x >> y;
            cout << qr(1, n, x, y, 0) << '\n';
        }
    }
}