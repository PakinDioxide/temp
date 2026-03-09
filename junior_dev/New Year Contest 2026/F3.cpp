#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

const int mxN = 1e6+5;

struct F {
    ll x, y;
    F operator+(const F &o) {
        ll X = x * o.y + o.x * y;
        ll Y = y * o.y;
        ll G = __gcd(X, Y);
        X /= G, Y /= G;
        return {X, Y};
    }
    bool operator!=(const F &o) {
        return !(x == o.x && y == o.y);
    }
};

struct Node {
    F first;
    int second;
};

F zr = {0, 0};

Node seg[4*mxN];

void build(int l, int r, int u) {
    if (l == r) seg[u] = {{l, 1}, 1};
    else {
        int m = l + (r-l)/2;
        build(l, m, u<<1);
        build(m+1, r, u<<1|1);
        seg[u] = {zr, seg[u<<1].second + seg[u<<1|1].second};
    }
}

void upd(int l, int r, int x, F k, int u) {
    if (l == r) seg[u] = {k, (k != zr)};
    else {
        int m = l + (r-l)/2;
        if (m >= x) upd(l, m, x, k, u<<1);
        else upd(m+1, r, x, k, u<<1|1);
        seg[u] = {zr, seg[u<<1].second + seg[u<<1|1].second};
    }
}

Node qr(int l, int r, int x, int u) {
    if (l == r) return {seg[u].first, l};
    else {
        int m = l + (r-l)/2;
        if (seg[u<<1].second >= x) return qr(l, m, x, u<<1);
        else return qr(m+1, r, x-seg[u<<1].second, u<<1|1);
    }
}

bool solve() {
    int n; cin >> n;
    build(1, n, 1);
    F rc = {1, 1};
    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        Node X = qr(1, n, x, 1), Y = qr(1, n, y, 1);
        X.first = (X.first + Y.first);
        if (X.first.x % 2 == 0) X.first.x /= 2;
        else X.first.y *= 2;
        // cout << "X " << X.first << ' ' << X.second << '\n';
        // cout << "Y " << Y.first << ' ' << Y.second << '\n';
        upd(1, n, X.second, X.first, 1);
        upd(1, n, Y.second, zr, 1);
        rc = X.first;
    }
    // cout << k << '\n';
    return rc.y == 1;
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) cout << (solve() ? "YES\n" : "NO\n");
}

