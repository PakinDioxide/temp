#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;
const int MX = 4e5+1;
const ll mod = 1e9+7;

pair <ll, ll> seg[4*2*mxN];

pair <ll, ll> mg(const pair <ll, ll> &l, const pair <ll, ll> & r) {
    if (l.first < r.first) return l;
    if (r.first < l.first) return r;
    return make_pair(l.first, (l.second + r.second) % mod);
}

void build(int l, int r, int u) {
    if (l == r) seg[u] = make_pair(LLONG_MAX, 0);
    else {
        int m = l + (r-l)/2;
        build(l, m, u<<1);
        build(m+1, r, u<<1|1);
        seg[u] = mg(seg[u<<1], seg[u<<1|1]);
    }
}

void upd(int l, int r, int x, pair <ll, ll> k, int u) {
    if (l == r) seg[u] = mg(seg[u], k);
    else {
        int m = l + (r-l)/2;
        if (m >= x) upd(l, m, x, k, u<<1);
        else upd(m+1, r, x, k, u<<1|1);
        seg[u] = mg(seg[u<<1], seg[u<<1|1]);
    }
}

pair <ll, ll> qr(int l, int r, int x, int y, int u) {
    if (x <= l && r <= y) return seg[u];
    else {
        int m = l + (r-l)/2;
        pair <ll, ll> a = make_pair(LLONG_MAX, 0);
        if (m >= x) a = mg(a, qr(l, m, x, y, u<<1));
        if (m+1 <= y) a = mg(a, qr(m+1, r, x, y, u<<1|1));
        return a;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    vector <int> cc; vector <pair <int, int>> a(n);
    for (auto &[x, y] : a) cin >> x >> y, cc.emplace_back(x), cc.emplace_back(y);
    sort(a.begin(), a.end()), reverse(a.begin(), a.end()), sort(cc.begin(), cc.end());
    build(1, MX, 1);
    upd(1, MX, MX, make_pair(LLONG_MAX-1, 1), 1);
    for (auto &[x, y] : a) {
        swap(x, y);
        int px = upper_bound(cc.begin(), cc.end(), x) - cc.begin(), py = upper_bound(cc.begin(), cc.end(), y) - cc.begin();
        pair <ll, ll> k = qr(1, MX, py, MX, 1);
        if (k.first == LLONG_MAX-1) upd(1, MX, px, make_pair(x, 1), 1);
        else upd(1, MX, px, make_pair(k.first - y + x, k.second), 1);
    
        // cout << x << ' ' << y << ' ' << seg[1].first << ' ' << seg[1].second << '\n';
    }
    cout << seg[1].second << '\n';
}