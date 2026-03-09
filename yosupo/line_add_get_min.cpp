#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

struct Line {
    ll m = 0, c = LLONG_MAX;
    ll operator()(ll x) { return m * x + c; }
};

struct Node {
    Line val;
    int l, r;
};

Node pool[mxN<<5];
int it = 0;

int nw(Line x = {0, LLONG_MAX}) {
    pool[++it] = {x, 0, 0};
    return it;
}

int seg = nw();

void ins(int l, int r, Line x, int u) {
    if (l == r) {
        if (pool[u].val(l) > x(l)) pool[u].val = x;
        return;
    }
    int m = l + (r-l)/2;
    if (x.m > pool[u].val.m) swap(x, pool[u].val);
    if (x(m) < pool[u].val(m)) {
        swap(x, pool[u].val);
        if (pool[u].l == 0) pool[u].l = nw();
        ins(l, m, x, pool[u].l);
    } else {
        if (pool[u].r == 0) pool[u].r = nw();
        ins(m+1, r, x, pool[u].r);
    }
}

ll qr(int l, int r, ll x, int u) {
    if (l == r) return pool[u].val(x);
    else {
        int m = l + (r-l)/2;
        if (m >= x) {
            if (pool[u].l == 0) pool[u].l = nw();
            return min(pool[u].val(x), qr(l, m, x, pool[u].l));
        } else {
            if (pool[u].r == 0) pool[u].r = nw();
            return min(pool[u].val(x), qr(m+1, r, x, pool[u].r));
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q; cin >> n >> q;
    while (n--) {
        ll m, c; cin >> m >> c;
        ins(-1e9, 1e9, {m, c}, seg);
    }
    while (q--) {
        int t; cin >> t;
        if (t == 0) {
            ll m, c; cin >> m >> c;
            ins(-1e9, 1e9, {m, c}, seg);
        } else {
            ll x; cin >> x;
            cout << qr(-1e9, 1e9, x, seg) << '\n';
        }
    }
}

