/*
    author  : PakinDioxide
    created : 20/05/2025 23:02
    task    : 104380H
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

struct T {
    ll X, Y, S;
    T operator + (const T &o) {
        ll k = min(X, o.Y);
        return {X-k+o.X, Y+o.Y-k, S+o.S+k};
    }
};

int n, q;
string s;
T seg[4*mxN];

void upd(int l, int r, int idx, int node) {
    if (l == r) seg[node] = {(s[idx] == 0), (s[idx] == 1), 0};
    else {
        int mid = l + (r-l)/2;
        if (mid >= idx) upd(l, mid, idx, node<<1);
        else upd(mid+1, r, idx, node<<1|1);
        seg[node] = seg[node<<1] + seg[node<<1|1];
    }
}

T qr(int l, int r, int x, int y, int node) {
    if (x <= l && r <= y) return seg[node];
    else {
        int mid = l + (r-l)/2; T v = {0, 0, 0};
        if (mid >= x) v = v + qr(l, mid, x, y, node<<1);
        if (mid+1 <= y) v = v + qr(mid+1, r, x, y, node<<1|1);
        return v;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> s >> q; n = s.size();
    for (int i = 0; i < n; i++) s[i] = (s[i] == '1'), upd(0, n-1, i, 1);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int idx; cin >> idx; s[--idx] ^= 1;
            upd(0, n-1, idx, 1);
        } else {
            int l, r; cin >> l >> r;
            cout << r-l+1-2*qr(0, n-1, --l, --r, 1).S << '\n';
        }
    }
}