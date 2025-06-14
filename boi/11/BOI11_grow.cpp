/*
    author  : PakinDioxide
    created : 26/05/2025 00:22
    task    : BOI11_grow
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

struct T {
    ll s[4*mxN], lz[4*mxN];
    void build() { memset(s, 0, sizeof(s)), memset(lz, 0, sizeof(lz)); }
    void push(int u, int l, int r) {
        s[l] += lz[u], lz[l] += lz[u];
        s[r] += lz[u], lz[r] += lz[u];
        lz[u] = 0;
    }
    void upd(int l, int r, int x, int y, ll k, int u) {
        if (x <= l && r <= y) lz[u] += k, s[u] += k;
        else {
            push(u, u<<1, u<<1|1);
            int mid = l + (r-l)/2;
            if (mid >= x) upd(l, mid, x, y, k, u<<1);
            if (mid+1 <= y) upd(mid+1, r, x, y, k, u<<1|1);
            s[u] = s[u<<1|1];
        }
    }
    int fi(int l, int r, ll x, int u) {
        if (l == r) return l;
        else {
            push(u, u<<1, u<<1|1);
            int mid = l + (r-l)/2;
            if (s[u<<1] >= x) return fi(l, mid, x, u<<1);
            else return fi(mid+1, r, x, u<<1|1);
        }
    }
    ll get(int l, int r, int idx, int u) {
        if (l == r) return s[u];
        else {
            push(u, u<<1, u<<1|1);
            int mid = l + (r-l)/2;
            if (mid >= idx) return get(l, mid, idx, u<<1);
            else return get(mid+1, r, idx, u<<1|1);
        }
    }
};

int n, q;
ll a[mxN];
T s;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    s.build();
    n++;
    a[0] = LLONG_MIN, a[n] = LLONG_MAX;
    for (int i = 1; i < n; i++) cin >> a[i];
    sort(a, a+n+1);
    s.upd(0, n, 0, 0, a[0], 1);
    s.upd(0, n, n, n, a[n], 1);
    for (int i = 1; i < n; i++) s.upd(0, n, i, i, a[i], 1);
    while (q--) {
        char t; cin >> t;
        if (t == 'F') {
            ll c, h; cin >> c >> h;
            int l = s.fi(0, n, h, 1), r = min((int) (l+c-1), n-1);
            if (l > r) continue;
            int l_ = s.fi(0, n, s.get(0, n, r, 1), 1), r_ = s.fi(0, n, s.get(0, n, r, 1)+1, 1) - 1;
            if (l >= l_) s.upd(0, n, max(l_, (int) (r_-c+1)), r_, 1, 1);
            else s.upd(0, n, r_ - (r - l_ + 1) + 1, r_, 1, 1);
            if (l <= l_-1) s.upd(0, n, l, l_ - 1, 1, 1);
        } else {
            ll l, r; cin >> l >> r;
            cout << (s.fi(0, n, r+1, 1) - 1) - s.fi(0, n, l, 1) + 1 << '\n';
        }
    }
}