/*
    author  : PakinDioxide
    created : 31/03/2025 19:42
    task    : 1735
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll seg[800005], a[200005], laz[800005], st[800005];

void push(int l, int r, int node) {
    int mid = l + (r-l)/2;
    if (st[node]) {
        seg[node*2+1] = st[node] * (mid - l + 1);
        seg[node*2+2] = st[node] * (r - (mid+1) + 1);
        st[node*2+1] = st[node];
        st[node*2+2] = st[node];
        laz[node*2+1] = 0;
        laz[node*2+2] = 0;
        st[node] = 0;
    }
    seg[node*2+1] += laz[node] * (mid - l + 1);
    seg[node*2+2] += laz[node] * (r - (mid+1) + 1);
    laz[node*2+1] += laz[node];
    laz[node*2+2] += laz[node];
    laz[node] = 0;
}

void build(int l, int r, int node) {
    if (l == r) seg[node] = a[l], laz[node] = st[node] = 0;
    else {
        int mid = l + (r-l)/2;
        build(l, mid, node*2+1);
        build(mid+1, r, node*2+2);
        seg[node] = seg[node*2+1] + seg[node*2+2];
        laz[node] = st[node] = 0;
    }
}

void upd(int l, int r, int x, int y, ll k, int node) {
    if (x <= l && r <= y) seg[node] += (r - l + 1) * k, laz[node] += k;
    else {
        push(l, r, node);
        int mid = l + (r-l)/2;
        if (mid >= x) upd(l, mid, x, y, k, node*2+1);
        if (mid+1 <= y) upd(mid+1, r, x, y, k, node*2+2);
        seg[node] = seg[node*2+1] + seg[node*2+2];
    }
}

void stt(int l, int r, int x, int y, ll k, int node) {
    if (x <= l && r <= y) seg[node] = (r - l + 1) * k, st[node] = k, laz[node] = 0;
    else {
        push(l, r, node);
        int mid = l + (r-l)/2;
        if (mid >= x) stt(l, mid, x, y, k, node*2+1);
        if (mid+1 <= y) stt(mid+1, r, x, y, k, node*2+2);
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

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 0);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r; ll x;
            cin >> l >> r >> x;
            upd(1, n, l, r, x, 0);
        } else if (t == 2) {
            int l, r; ll x;
            cin >> l >> r >> x;
            stt(1, n, l, r, x, 0);
        } else {
            int l, r;
            cin >> l >> r;
            cout << qr(1, n, l, r, 0) << '\n';
        }
    }
}