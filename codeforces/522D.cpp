#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 5e5+5;

int n, q, a[mxN], idx[mxN];
vector <int> cc;

struct Node {
    int val, l, r;
};

int seg[mxN];
Node pool[mxN*30];

int it = 0;

int nw(int x) {
    pool[++it] = {x, 0, 0};
    return it;
}

int nw2(int L, int R) {
    pool[++it] = {min(pool[L].val, pool[R].val), L, R};
    return it;
}

int build(int l, int r) {
    if (l == r) return nw(INT_MAX);
    else {
        int m = l + (r-l)/2;
        return nw2(build(l, m), build(m+1, r));
    }
}

int upd(int l, int r, int x, int k, int u) {
    if (l == r) return nw(k);
    else {
        int m = l + (r-l)/2;
        if (m >= x) return nw2(upd(l, m, x, k, pool[u].l), pool[u].r);
        else return nw2(pool[u].l, upd(m+1, r, x, k, pool[u].r));
    }
}

int qr(int l, int r, int x, int y, int u) {
    if (y < l || r < x) return INT_MAX;
    else if (x <= l && r <= y) return pool[u].val;
    else {
        int m = l + (r-l)/2, k = INT_MAX;
        k = min(k, qr(l, m, x, y, pool[u].l));
        k = min(k, qr(m+1, r, x, y, pool[u].r));
        return k;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i], cc.emplace_back(a[i]);
    sort(cc.begin(), cc.end());
    cc.resize(unique(cc.begin(), cc.end()) - cc.begin());
    for (int i = 1; i <= n; i++) a[i] = upper_bound(cc.begin(), cc.end(), a[i]) - cc.begin();
    seg[0] = build(1, n);
    for (int i = 1; i <= n; i++) {
        seg[i] = seg[i-1];
        if (idx[a[i]] > 0) seg[i] = upd(1, n, idx[a[i]], i - idx[a[i]], seg[i]);
        idx[a[i]] = i;
    }
    while (q--) {
        int x, y; cin >> x >> y; int k = qr(1, n, x, n, seg[y]);
        cout << (k == INT_MAX ? -1 : k) << '\n';
    }
}