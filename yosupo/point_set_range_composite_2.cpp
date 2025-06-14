/*
    author  : PakinDioxide
    created : 18/05/2025 22:46
    task    : point_set_range_composite
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 5e5+5;
const ll mod = 998244353;

int n, q;
pair <ll, ll> a[mxN], seg[4*mxN];

pair <ll, ll> mg(pair <ll, ll> a, pair <ll, ll> b) {
    return make_pair((b.first * a.first) % mod, (((b.first * a.second) % mod) + b.second) % mod);
}

void build(int l, int r, int node) {
    if (l == r) seg[node] = a[l];
    else {
        int mid = l + (r-l)/2;
        build(l, mid, node*2+1);
        build(mid+1, r, node*2+2);
        seg[node] = mg(seg[node*2+1], seg[node*2+2]);
    }
}

void upd(int l, int r, int idx, pair <ll, ll> x, int node) {
    if (l == r) seg[node] = x;
    else {
        int mid = l + (r-l)/2;
        if (mid >= idx) upd(l, mid, idx, x, node*2+1);
        else upd(mid+1, r, idx, x, node*2+2);
        seg[node] = mg(seg[node*2+1], seg[node*2+2]);
    }
}

pair <ll, ll> qr(int l, int r, int x, int y, int node) {
    if (x <= l && r <= y) return seg[node];
    else {
        int mid = l + (r-l)/2, k = 0;
        pair <ll, ll> v;
        if (mid >= x) v = (k ? mg(v, qr(l, mid, x, y, node*2+1)) : qr(l, mid, x, y, node*2+1)), k = 1;
        if (mid+1 <= y) v = (k ? mg(v, qr(mid+1, r, x, y, node*2+2)) : qr(mid+1, r, x, y, node*2+2)), k = 1;
        return v;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    build(0, n-1, 0);
    while (q--) {
        int t; cin >> t;
        if (t == 0) {
            int idx; ll x, y; cin >> idx >> x >> y;
            upd(0, n-1, idx, make_pair(x, y), 0);
        } else {
            int x, y; ll k; cin >> x >> y >> k; y--;
            pair <ll, ll> v = qr(0, n-1, x, y, 0);
            cout << (((v.first * k) % mod) + v.second) % mod << '\n';
        }
    }
}