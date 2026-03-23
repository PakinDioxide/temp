#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

const ll mxN = 2e6+5;
const ll INF = 2e9;

int n, d; 
ll TT, a[mxN];

struct SEG {
    ll seg[4*mxN];
    
    void build(int l, int r, int u) {
        if (l == r) seg[u] = a[l] - l;
        else {
            int m = l + (r-l)/2;
            build(l, m, u<<1);
            build(m+1, r, u<<1|1);
            seg[u] = min(seg[u<<1], seg[u<<1|1]);
        }
    }

    ll qr(int l, int r, int x, int y, int u) {
        if (x <= l && r <= y) return seg[u];
        else {
            int m = l + (r-l)/2; ll k = LLONG_MAX;
            if (m >= x) k = min(k, qr(l, m, x, y, u<<1));
            if (m+1 <= y) k = min(k, qr(m+1, r, x, y, u<<1|1));
            return k;
        }
    }

    ll QR(int l, int r, int x, int y, ll k, int u) {
        if (r < x || l > y || seg[u] > k) return -1;
        if (l == r) return l;
        else {
            int m = l + (r-l)/2;
            int res = QR(m+1, r, x, y, k, u<<1|1);
            if (res == -1) res = QR(l, m, x, y, k, u<<1);
            return res;
        }
    }
} T;

struct SEG2 {
    ll seg[4*mxN];
    
    void build(int l, int r, int u) {
        if (l == r) seg[u] = 0;
        else {
            int m = l + (r-l)/2;
            build(l, m, u<<1);
            build(m+1, r, u<<1|1);
            seg[u] = max(seg[u<<1], seg[u<<1|1]);
        }
    }

    void upd(int l, int r, int idx, int x, int u) {
        if (l == r) seg[u] = x;
        else {
            int m = l + (r-l)/2;
            if (m >= idx) upd(l, m, idx, x, u<<1);
            else upd(m+1, r, idx, x, u<<1|1);
            seg[u] = max(seg[u<<1], seg[u<<1|1]);
        }
    }

    ll qr(int l, int r, int x, int y, int u) {
        if (x <= l && r <= y) return seg[u];
        else {
            int m = l + (r-l)/2; ll k = LLONG_MIN;
            if (m >= x) k = max(k, qr(l, m, x, y, u<<1));
            if (m+1 <= y) k = max(k, qr(m+1, r, x, y, u<<1|1));
            return k;
        }
    }

    ll QR(int l, int r, int x, int y, ll k, int u) {
        if (r < x || l > y || seg[u] < k) return -1;
        if (l == r) return l;
        else {
            int m = l + (r-l)/2;
            int res = QR(m+1, r, x, y, k, u<<1|1);
            if (res == -1) res = QR(l, m, x, y, k, u<<1);
            return res;
        }
    }
} T2;

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> d;
    cin >> TT;
    for (int i = 1; i <= n; i++) cin >> a[i];
    T.build(1, n, 1);
    // cout << T.qr(1, n, 1, n, 1) << '\n';
    // for (int i = 1; i <= n; i++) cout << T.qr(1, n, i, i, 1) << ' '; cout << '\n';
    ll t[n+1];
    for (int i = 1; i <= n; i++) {
        // K + i <= TT
        // K <= TT-i
        t[i] = T.QR(1, n, 1, i, TT-i, 1);
        // cout << t[i] << ' ';
    }
    // cout << '\n';
    ll cnt = n;
    for (int i = 1; i <= n; i++) if (t[i] == -1) t[i] = INF, cnt--;
    ll C[n+1]; memset(C, 0, sizeof(C));
    T2.build(1, n, 1);
    for (int i = 1; i <= n; i++) if (t[i] < INF && i != t[i]) {
        ll mx = T2.qr(1, n, t[i], i, 1);
        int idx = T2.QR(1, n, t[i], i, mx, 1);
        C[idx]++;
        T2.upd(1, n, idx, C[idx], 1);
    }
    sort(C+1, C+n+1);
    for (int i = n; i > 0 && i > n-d; i--) cnt -= C[i];
    cout << cnt << '\n';

}
