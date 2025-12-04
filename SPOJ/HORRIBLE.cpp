/*
    author  : PakinDioxide
    created : 31/03/2025 19:29
    task    : HORRIBLE
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll seg[400005], laz[400005];

void push(int l, int r, int node) {
    int mid = l + (r-l)/2;
    seg[node*2+1] += laz[node] * (mid - l + 1);
    seg[node*2+2] += laz[node] * (r - (mid+1) + 1);
    laz[node*2+1] += laz[node];
    laz[node*2+2] += laz[node];
    laz[node] = 0;
}

void build(int l, int r, int node) {
    if (l == r) seg[node] = laz[node] = 0;
    else {
        int mid = l + (r-l)/2;
        build(l, mid, node*2+1);
        build(mid+1, r, node*2+2);
        seg[node] = seg[node*2+1] + seg[node*2+2];
        laz[node] = 0;
    }
}

void upd(int l, int r, int x, int y, ll k, int node) {
    if (x <= l && r <= y) seg[node] += k * (r - l + 1), laz[node] += k;
    else {
        push(l, r, node);
        int mid = l + (r-l)/2;
        if (mid >= x) upd(l, mid, x, y, k, node*2+1);
        if (mid+1 <= y) upd(mid+1, r, x, y, k, node*2+2);
        seg[node] = seg[node*2+1] + seg[node*2+2];
    }
}

ll qr(int l, int r, int x, int y, int node) {
    if (x <= l && r <= y) return seg[node];
    else {
        push(l, r, node);
        int mid = l + (r-l)/2;
        ll sum = 0;
        if (mid >= x) sum += qr(l, mid, x, y, node*2+1);
        if (mid+1 <= y) sum += qr(mid+1, r, x, y, node*2+2);
        return sum;
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    build(1, n, 0);
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r; ll x;
            cin >> l >> r >> x;
            upd(1, n, l, r, x, 0);
        } else {
            int l, r;
            cin >> l >> r;
            cout << qr(1, n, l, r, 0) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}