/*
    author  : PakinDioxide
    created : 24/05/2025 20:51
    task    : 1736
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

struct T {
    ll val = 0, shf = 0, cnt = 0, sz = 0;
    T operator+(const T &o) {
        return T{val+o.val, 0, 0, sz+o.sz};
    }
};

int n, q;
ll a[mxN];
T s[4*mxN];

ll gt(ll x) { return x*(x+1)/2; }

void push(int u, int l, int r) {
    s[l].val += gt(s[l].sz)*s[u].cnt + s[u].shf*s[l].sz;
    s[l].cnt += s[u].cnt, s[l].shf += s[u].shf;
    s[u].shf += s[l].sz*s[u].cnt;
    s[r].val += gt(s[r].sz)*s[u].cnt + s[u].shf*s[r].sz;
    s[r].cnt += s[u].cnt, s[r].shf += s[u].shf;
    s[u].cnt = s[u].shf = 0;
}

void build(int l, int r, int u) {
    if (l == r) s[u].val = a[l], s[u].sz = 1;
    else {
        int mid = l + (r-l)/2;
        build(l, mid, u<<1);
        build(mid+1, r, u<<1|1);
        s[u] = s[u<<1] + s[u<<1|1];
    }
}

void upd(int l, int r, int x, int y, int u) {
    if (x <= l && r <= y) s[u].val += gt(s[u].sz) + (l-x)*s[u].sz, s[u].cnt++, s[u].shf += (l-x);
    else {
        push(u, u<<1, u<<1|1);
        int mid = l + (r-l)/2;
        if (mid >= x) upd(l, mid, x, y, u<<1);
        if (mid+1 <= y) upd(mid+1, r, x, y, u<<1|1);
        s[u] = s[u<<1]+s[u<<1|1];
    }
}

ll qr(int l, int r, int x, int y, int u) {
    if (x <= l && r <= y) return s[u].val;
    else {
        push(u, u<<1, u<<1|1);
        int mid = l + (r-l)/2; ll v = 0;
        if (mid >= x) v += qr(l, mid, x, y, u<<1);
        if (mid+1 <= y) v += qr(mid+1, r, x, y, u<<1|1);
        return v;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 1);
    while (q--) {
        int t, l, r; cin >> t >> l >> r;
        if (t == 1) upd(1, n, l, r, 1);
        else cout << qr(1, n, l, r, 1) << '\n';
    }
}