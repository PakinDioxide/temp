#include <bits/stdc++.h>
#define ll long long
#define int ll
#define db double

using namespace std;

const int mxN = 2e5+5;

ll seg[4*mxN], seg2[4*mxN], lz[4*mxN];

void push(int u) {
    seg[u<<1] += lz[u];
    seg[u<<1|1] += lz[u];
    seg2[u<<1] += lz[u];
    seg2[u<<1|1] += lz[u];
    lz[u<<1] += lz[u];
    lz[u<<1|1] += lz[u];
    lz[u] = 0;
}

void build(int l, int r, int u) {
    if (l == r) seg[u] = -1e18, seg2[u] = 1e18;
    else {
        int m = l + (r-l)/2;
        build(l, m, u<<1);
        build(m+1, r, u<<1|1);
        seg[u] = -1e18;
        seg2[u] = 1e18;
    }
}

void upd(int l, int r, int x, int y, ll k, int u) {
    if (y < x) return;
    if (x <= l && r <= y) seg[u] += k, seg2[u] += k, lz[u] += k;
    else {
        push(u);
        int m = l + (r-l)/2;
        if (m >= x) upd(l, m, x, y, k, u<<1);
        if (m+1 <= y) upd(m+1, r, x, y, k, u<<1|1);
        seg[u] = max(seg[u<<1], seg[u<<1|1]);
        seg2[u] = min(seg2[u<<1], seg2[u<<1|1]);
    }
}

void st(int l, int r, int x, ll k, int u, int TYPE) {
    if (l == r) {
        if (TYPE == 0) seg[u] = k;
        else seg2[u] = k;
        lz[u] = 0;
    } else {
        push(u);
        int m = l + (r-l)/2;
        if (m >= x) st(l, m, x, k, u<<1, TYPE);
        else st(m+1, r, x, k, u<<1|1, TYPE);
        seg[u] = max(seg[u<<1], seg[u<<1|1]);
        seg2[u] = min(seg2[u<<1], seg2[u<<1|1]);
    }
}

ll qr(int l, int r, int x, int y, int u, int TYPE) {
    if (y < x) return (TYPE == 0 ? -1e18 : 1e18);
    if (x <= l && r <= y) return (TYPE == 0 ? seg[u] : seg2[u]);
    else {
        push(u);
        if (TYPE == 0) {
            int m = l + (r-l)/2; ll k = -1e18;
            if (m >= x) k = max(k, qr(l, m, x, y, u<<1, TYPE));
            if (m+1 <= y) k = max(k, qr(m+1, r, x, y, u<<1|1, TYPE));
            return k;
        } else {
            int m = l + (r-l)/2; ll k = 1e18;
            if (m >= x) k = min(k, qr(l, m, x, y, u<<1, TYPE));
            if (m+1 <= y) k = min(k, qr(m+1, r, x, y, u<<1|1, TYPE));
            return k;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, m, d; 
    cin >> n >> m >> d;
    d *= 2;
    if (n) {
        vector <ll> a(n);
        for (auto &e : a) cin >> e, e *= 2;
        while (m--) {
            ll x; cin >> x; x *= 2; a.emplace_back(x);
            sort(a.begin(), a.end());
            ll L = 0, R = 1e18, ans = 0;
            while (L <= R) {
                ll X = L + (R-L)/2;
                int ok = 1;
                ll r = -1e18;
                for (auto &e : a) {
                    ll k = max(r+d, e-X);
                    if (k > e+X) { ok = 0; break; }
                    r = k;
                }
                if (ok) ans = X, R = X-1;
                else L = X+1;
            }
            cout << ans/2;
            if (ans % 2 == 1) cout << ".5";
            cout << " ";
        }
        cout << '\n';
    } else {
        build(0, m-1, 1);
        ll rec = 0;
        map <ll, bool> vis;
        vector <ll> V(m), cc;
        for (auto &e : V) cin >> e, e *= 2, cc.emplace_back(e);
        sort(cc.begin(), cc.end());
        cc.resize(unique(cc.begin(), cc.end()) - cc.begin());
        map <ll, int> id;
        for (int i = 0; i < (int) cc.size(); i++) id[cc[i]] = i;
        for (auto &k : V) {
            int idx = id[k];
            if (vis[k]) {
                rec += d/2;
                upd(0, m-1, 0, idx-1, -d/2, 1);
                upd(0, m-1, idx+1, m-1, d/2, 1);
                st(0, m-1, idx, qr(0, m-1, idx, idx, 1, 0) + d/2, 1, 0);
                st(0, m-1, idx, qr(0, m-1, idx, idx, 1, 1) - d/2, 1, 1);
            } else {
                vis[k] = 1;
                ll p = qr(0, m-1, 0, idx-1, 1, 0), r = qr(0, m-1, idx+1, m-1, 1, 1);
                ll q = k;
                // cout << "PQR " << p << ' ' << q << ' ' << r << '\n';
                ll L = 0, R = 1e18, x = 0;
                while (L <= R) {
                    ll xx = L + (R-L)/2;
                    if (p-xx+d <= q+rec+xx && max(q-rec-xx, p-xx+d) + d <= r + xx) x = xx, R = xx-1;
                    else L = xx+1;
                }
                // cout << p-x+d << ' ' << max(q-x, p-x+d) + d << ' ' << r + x << '\n';
                rec += x;
                upd(0, m-1, 0, idx-1, -x, 1);
                upd(0, m-1, idx, m-1, x, 1);
                st(0, m-1, idx, max(p-x+d, q-rec-x), 1, 0);
                st(0, m-1, idx, min(r+x-d, q+rec+x), 1, 1);
                /*
                cout << "X " << x << '\n';
                for (int i = 0; i <= m-1; i++) {
                    ll DDD = qr(0, m-1, i, i, 1, 0);
                    cout << (DDD > -1e18 ? DDD : -67) << ' ';
                }
                cout << '\n';
                */
            }
            cout << rec/2;
            if (rec % 2 == 1) cout << ".5";
            cout << " ";
        }
        cout << '\n';
    }
}
