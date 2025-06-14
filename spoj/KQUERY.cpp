/*
    author  : PakinDioxide
    created : 18/05/2025 03:04
    task    : KQUERY
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 3e4+5;

int n, q;
ll a[mxN];
vector <ll> seg[4*mxN];

void build(int l, int r, int node) {
    if (l == r) seg[node].emplace_back(a[l]);
    else {
        int mid = l + (r-l)/2;
        build(l, mid, node*2+1);
        build(mid+1, r, node*2+2);
        int x = 0, y = 0;
        while (x < seg[node*2+1].size() && y < seg[node*2+2].size()) {
            if (seg[node*2+1][x] <= seg[node*2+2][y]) seg[node].emplace_back(seg[node*2+1][x++]);
            else seg[node].emplace_back(seg[node*2+2][y++]);
        }
        while (x < seg[node*2+1].size()) seg[node].emplace_back(seg[node*2+1][x++]);
        while (y < seg[node*2+2].size()) seg[node].emplace_back(seg[node*2+2][y++]);
    }
}

ll qr(int l, int r, int x, int y, ll k, int node) {
    if (x <= l && r <= y) return (ll) seg[node].size() - (upper_bound(seg[node].begin(), seg[node].end(), k) - seg[node].begin());
    else {
        int mid = l + (r-l)/2; ll s = 0;
        if (mid >= x) s += qr(l, mid, x, y, k, node*2+1);
        if (mid+1 <= y) s += qr(mid+1, r, x, y, k, node*2+2);
        return s;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;
    build(1, n, 0);
    while (q--) {
        int x, y; ll k; cin >> x >> y >> k;
        cout << qr(1, n, x, y, k, 0) << '\n';
    }
}