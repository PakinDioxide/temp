#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

struct node {
    ll val;
    node *l, *r;
    node(ll x) : val(x), l(nullptr), r(nullptr) {}
    node(node *L, node *R) : val(L->val + R->val), l(L), r(R) {}
};

ll a[mxN];
node *pst[mxN];

node *build(int l, int r) {
    if (l == r) return new node(a[l]);
    else {
        int m = l + (r-l)/2;
        return new node(build(l, m), build(m+1, r));
    }
}

node *upd(int l, int r, int x, int k, node *u) {
    if (l == r) return new node(k);
    else {
        int m = l + (r-l)/2;
        if (m >= x) return new node(upd(l, m, x, k, u->l), u->r);
        else return new node(u->l, upd(m+1, r, x, k, u->r));
    }
}

ll qr(int l, int r, int x, int y, node *u) {
    if (y < l || r < x) return 0;
    if (x <= l && r <= y) return u->val;
    else {
        int m = l + (r-l)/2; ll k = 0;
        k += qr(l, m, x, y, u->l);
        k += qr(m+1, r, x, y, u->r);
        return k;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    pst[1] = build(1, n); int it = 1;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int k; ll x, y; cin >> k >> x >> y;
            pst[k] = upd(1, n, x, y, pst[k]);
        } else if (t == 2) {
            int k, l, r; cin >> k >> l >> r;
            cout << qr(1, n, l, r, pst[k]) << '\n';
        } else {
            int k; cin >> k; pst[++it] = pst[k];
        }
    }
}