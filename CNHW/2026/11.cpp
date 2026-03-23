#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;
const ll INF = 2e9;

ll a[mxN], t[mxN];

struct PST {
    struct {
        int l, r, val;
    } pool[mxN<<5];

    int it = 0, seg[mxN];

    int nw(int x) {
        pool[++it] = {0, 0, x};
        return it;
    }

    int nw(int l, int r) {
        pool[++it] = {l, r, pool[l].val + pool[r].val};
        return it;
    }

    int build(int l, int r) {
        if (l == r) return nw(0);
        else {
            int m = l + (r-l)/2;
            return nw(build(l, m), build(m+1, r));
        }
    }

    int upd(int l, int r, int idx, int x, int u) {
        if (l == r) return nw(pool[u].val + x);
        else {
            int m = l + (r-l)/2;
            if (m >= idx) return nw(upd(l, m, idx, x, pool[u].l), pool[u].r);
            else return nw(pool[u].l, upd(m+1, r, idx, x, pool[u].r));
        }
    }

    int QR(int l, int r, int x, int L, int R) {
        if (r <= x) return pool[R].val - pool[L].val;
        else if (l > x) return 0;
        else {
            int m = l + (r-l)/2;
            return QR(l, m, x, pool[L].l, pool[R].l)
                 + QR(m+1, r, x, pool[L].r, pool[R].r);
        }
    }
} T;

struct SEG {
    ll seg[4*mxN];

    void build(int l, int r, int u) {
        if (l == r) seg[u] = a[l];
        else {
            int m = l + (r-l)/2;
            build(l, m, u<<1);
            build(m+1, r, u<<1|1);
            seg[u] = min(seg[u<<1], seg[u<<1|1]);
        }
    }

    ll qr(int l, int r, int x, int y, int u) {
        if (y < x) return INF;
        if (x <= l && r <= y) return seg[u];
        else {
            int m = l + (r-l)/2;
            ll k = INF;
            if (m >= x) k = min(k, qr(l, m, x, y, u<<1));
            if (m+1 <= y) k = min(k, qr(m+1, r, x, y, u<<1|1));
            return k;
        }
    }
    
    int QR_L(int l, int r, int x, int y, ll k, int u) {
        if (r < x || l > y) return -1;
        if (seg[u] > k) return -1;
        if (l == r) return l;
        else {
            int m = l + (r-l)/2;
            int idx = QR_L(l, m, x, y, k, u<<1);
            if (idx == -1) idx = QR_L(m+1, r, x, y, k, u<<1|1);
            return idx;
        }
    }

    int QR_R(int l, int r, int x, int y, ll k, int u) {
        if (r < x || l > y) return -1;
        if (seg[u] > k) return -1;
        if (l == r) return l;
        else {
            int m = l + (r-l)/2;
            int idx = QR_R(m+1, r, x, y, k, u<<1|1);
            if (idx == -1) idx = QR_R(l, m, x, y, k, u<<1);
            return idx;
        }
    }

} TT;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) t[i] = -INF;
    stack <int> st;
    for (int i = 1; i <= n; i++) {
        while (st.size() && st.top() > a[i]) st.pop();
        if (st.size()) t[i] = max(t[i], a[i] + st.top());
        st.emplace(a[i]);
    }
    while (st.size()) st.pop();
    for (int i = n; i > 0; i--) {
        while (st.size() && st.top() > a[i]) st.pop();
        if (st.size()) t[i] = max(t[i], a[i] + st.top());
        st.emplace(a[i]);
    }
    for (int i = 1; i <= n; i++) if (t[i] == -INF) t[i] = 2*a[i];
    vector <ll> cc;
    for (int i = 1; i <= n; i++) cc.emplace_back(t[i]);
    sort(cc.begin(), cc.end());
    T.seg[0] = T.build(1, n);
    for (int i = 1; i <= n; i++) {
        T.seg[i] = T.upd(1, n, upper_bound(cc.begin(), cc.end(), t[i]) - cc.begin(), 1, T.seg[i-1]);
    }
    TT.build(1, n, 1);
    while (q--) {
        int l, r, k; cin >> l >> r >> k;
        ll L = 2*TT.qr(1, n, l, r, 1), R = 2e9, ans = 2e9;
        while (L <= R) {
            ll x = L + (R-L)/2;
            int X = upper_bound(cc.begin(), cc.end(), x) - cc.begin();
            int L_idx = TT.QR_L(1, n, l, r, x/2, 1),
                R_idx = TT.QR_R(1, n, l, r, x/2, 1);
            assert(L_idx > 0 && R_idx > 0);
            int cnt = T.QR(1, n, X, T.seg[L_idx-1], T.seg[R_idx]);
            ll mn = min(TT.qr(1, n, l, L_idx-1, 1), TT.qr(1, n, R_idx+1, r, 1));
            // cout << "X " << X << ' ' << L_idx << ' ' << R_idx << '\n' << "Lmin " << TT.qr(1, n, l, L_idx-1, 1) << ' ' << TT.qr(1, n, R_idx+1, r, 1) << '\n' << "MN " << mn << ' ' << cnt << '\n';
            // for (int i = 1; i <= n; i++) cout << t[i] << ' '; cout << '\n';
            if (mn + a[L_idx] <= x && mn + a[R_idx] <= x) cnt++;
            if (cnt >= k) ans = x, R = x-1;
            else L = x+1;
        }
        cout << ans << '\n';
    }
}

