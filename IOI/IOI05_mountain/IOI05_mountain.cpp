#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5;

struct Node {
    ll val = 0, l = 0, r = 0, lz = 0, vt = 0;
};

int it = 0;
Node pool[mxN<<6];

int nw() { return ++it; }

void push(int u, int l, int r) {
    int m = l + (r-l)/2;
    if (!pool[u].l) pool[u].l = nw();
    if (!pool[u].r) pool[u].r = nw();
    if (pool[u].lz == LLONG_MAX || l == r) return;
    int L = pool[u].l, R = pool[u].r;
    pool[L].val = max(pool[u].lz, pool[L].vt = pool[u].lz * (m-l+1));
    pool[L].lz = pool[u].lz;
    pool[R].val = max(pool[u].lz, pool[R].vt = pool[u].lz * (r-m));
    pool[R].lz = pool[u].lz;
    pool[u].lz = LLONG_MAX;
}

int root = 0;

void upd(int l, int r, int x, int y, ll k, int u) {
    if (y < l || r < x) return;
    if (x <= l && r <= y) {
        pool[u].val = max(k, pool[u].vt = k * (r-l+1));
        pool[u].lz = k;
        return;
    }
    int m = l + (r-l)/2;
    push(u, l, r);
    upd(l, m, x, y, k, pool[u].l);
    upd(m+1, r, x, y, k, pool[u].r);
    pool[u].val = max(pool[pool[u].l].val, pool[pool[u].l].vt + pool[pool[u].r].val);
    pool[u].vt = pool[pool[u].l].vt + pool[pool[u].r].vt;
}

int qr(int l, int r, ll k, int u) {
    if (l == r) return l;
    else {
        int m = l + (r-l)/2;
        push(u, l, r);
        // cout << l << ' ' << m << ' ' << pool[pool[u].l].val << '\n';
        ll L = pool[pool[u].l].val, LL = pool[pool[u].l].vt;
        if (L > k) return qr(l, m, k, pool[u].l);
        else return qr(m+1, r, k-LL, pool[u].r);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    root = nw();
    while (1) {
        char x; cin >> x;
        if (x == 'E') exit(0);
        if (x == 'I') {
            int l, r; ll k; cin >> l >> r >> k;
            upd(0, n+1, l, r, k, root);
        } else {
            ll k; cin >> k;
            cout << qr(0, n+1, k, root)-1 << '\n';
        }
    }
}