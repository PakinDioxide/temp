#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e6+5;

ll seg[4*mxN], lz[4*mxN];

void push(int u) {
    seg[u<<1] += lz[u];
    seg[u<<1|1] += lz[u];
    lz[u<<1] += lz[u];
    lz[u<<1|1] += lz[u];
    lz[u] = 0;
}

void build(int l, int r, int u) {
    if (l == r) seg[u] = 0, lz[u] = 0;
    else {
        int m = l + (r-l)/2;
        build(l, m, u<<1);
        build(m+1, r, u<<1|1);
        seg[u] = min(seg[u<<1], seg[u<<1|1]);
        lz[u] = 0;
    }
}

void upd(int l, int r, int x, int y, ll k, int u) {
    if (x <= l && r <= y) seg[u] += k, lz[u] += k;
    else {
        push(u);
        int m = l + (r-l)/2;
        if (m >= x) upd(l, m, x, y, k, u<<1);
        if (m+1 <= y) upd(m+1, r, x, y, k, u<<1|1);
        seg[u] = min(seg[u<<1], seg[u<<1|1]);
    }
}

ll qr(int l, int r, int x, int y, int u) {
    if (x <= l && r <= y) return seg[u];
    else {
        push(u);
        int m = l + (r-l)/2; ll mn = LLONG_MAX;
        if (m >= x) mn = min(mn, qr(l, m, x, y, u<<1));
        if (m+1 <= y) mn = min(mn, qr(m+1, r, x, y, u<<1|1));
        return mn;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    ll b, p; cin >> b >> p;
    vector <tuple <int, int, int, ll>> I, O;
    for (int i = 0; i < p; i++) {
        int x1, x2, y1, y2; ll c; cin >> x1 >> y1 >> x2 >> y2 >> c;
        I.emplace_back(x1, y1, y2, c), O.emplace_back(x2+1, y1, y2, c);
    }
    int L = 1, R = min(m, n), ans = 0, sz = (int) I.size() + (int) O.size();
    while (L <= R) {
        int x = L + (R-L)/2;// x = 4;
        tuple <int, int, int, ll> v[sz]; int it = 0;
        for (auto &[x1, y1, y2, c] : I) v[it++] = make_tuple(max(1, x1 - x + 1), max(1, y1 - x + 1), y2, c);
        for (auto &[x2, y1, y2, c] : O) v[it++] = make_tuple(x2, max(1, y1 - x + 1), y2, -c);
        sort(v, v+sz);
        build(1, m, 1);
        int ok = 0;
        for (int i = 0; i < sz; i++) {
            auto &[xi, y1, y2, c] = v[i];
            if (xi + x - 1 > n) break;
            upd(1, m, y1, y2, c, 1);
            if (i < sz-1 && xi == get<0>(v[i+1])) continue;
            // cerr << qr(1, n, 1, n - x + 1, 1) << '\n';
            // for (int i = 1; i <= m; i++) cerr << qr(1, m, i, i, 1) << ' '; cerr << '\n';
            if (qr(1, m, 1, m - x + 1, 1) <= b) { ok = 1; break; }
        }
        if (ok) ans = x, L = x+1;
        else R = x-1;
        // break;
    }
    cout << ans << '\n';
}

/*
do bsearch on square size k

then sweepline, across x, like sliding window size k

when add rectangle [y1, y2];

add the value to segtree from [y1-x+1, y2]

then find min; if min <= B then OK; else continue
*/