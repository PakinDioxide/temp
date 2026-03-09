#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

struct Node {
    int val, l, r;
};

int seg[mxN], it = 0;
Node pool[mxN<<5];

int nw(int x) {
    pool[++it] = {x, 0, 0};
    return it;
}

int nw(int L, int R) {
    pool[++it] = {pool[L].val + pool[R].val, L, R};
    return it;
}

int build(int l, int r) {
    if (l == r) return nw(0);
    else {
        int m = l + (r-l)/2;
        return nw(build(l, m), build(m+1, r));
    }
}

int upd(int l, int r, int x, int k, int u) {
    if (l == r) return nw(k);
    else {
        int m = l + (r-l)/2;
        if (m >= x) return nw(upd(l, m, x, k, pool[u].l), pool[u].r);
        else return nw(pool[u].l, upd(m+1, r, x, k, pool[u].r));
    }
}

int qr(int l, int r, int k, int L, int R) {
    if (l == r) return l;
    else {
        int m = l + (r-l)/2, c = pool[pool[R].l].val - pool[pool[L].l].val;
        // cout << " K " << k << ' ' << l << ' ' << r << ' ' << c << '\n';
        if (c >= k) return qr(l, m, k, pool[L].l, pool[R].l);
        else return qr(m+1, r, k-c, pool[L].r, pool[R].r);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q; cin >> n >> q;
    vector <int> cc; int a[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i], cc.emplace_back(a[i]);
    sort(cc.begin(), cc.end());
    for (int i = 1; i <= n; i++) a[i] = upper_bound(cc.begin(), cc.end(), a[i]) - cc.begin();
    seg[0] = build(1, n);
    for (int i = 1; i <= n; i++) seg[i] = upd(1, n, a[i], 1, seg[i-1]);
    while (q--) {
        int l, r, k; cin >> l >> r >> k;
        l--;
        cout << cc[qr(1, n, k, seg[l], seg[r])-1] << '\n';
    }
}