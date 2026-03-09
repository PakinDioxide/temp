#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

struct T {
    ll L = 0, R = 0, M = 0, S = 0;
};

int a[mxN];
T seg[4*mxN], seg2[4*mxN];

void mg(int node) {
    seg[node].L = max(seg[node<<1].L, seg[node<<1].S + seg[node<<1|1].L);
    seg[node].R = max(seg[node<<1|1].R, seg[node<<1|1].S + seg[node<<1].R);
    seg[node].M = max({seg[node].L, seg[node].R, seg[node<<1].M, seg[node<<1|1].M, seg[node<<1].R + seg[node<<1|1].L});
    seg[node].S = seg[node<<1].S + seg[node<<1|1].S;
}
 
void upd(int l, int r, int idx, int node) {
    if (l == r) seg[node] = {a[l], a[l], max(0, a[l]), a[l]};
    else {
        int mid = l + (r-l)/2;
        if (mid >= idx) upd(l, mid, idx, node<<1);
        else upd(mid+1, r, idx, node<<1|1);
        mg(node);
    }
}

void mg2(int node) {
    seg2[node].L = min(seg2[node<<1].L, seg2[node<<1].S + seg2[node<<1|1].L);
    seg2[node].R = min(seg2[node<<1|1].R, seg2[node<<1|1].S + seg2[node<<1].R);
    seg2[node].M = min({seg2[node].L, seg2[node].R, seg2[node<<1].M, seg2[node<<1|1].M, seg2[node<<1].R + seg2[node<<1|1].L});
    seg2[node].S = seg2[node<<1].S + seg2[node<<1|1].S;
}
 
void upd2(int l, int r, int idx, int node) {
    if (l == r) seg2[node] = {a[l], a[l], min(0, a[l]), a[l]};
    else {
        int mid = l + (r-l)/2;
        if (mid >= idx) upd2(l, mid, idx, node<<1);
        else upd2(mid+1, r, idx, node<<1|1);
        mg2(node);
    }
}

void solve() {
    // SUB1
    int n, q; cin >> n >> q;
    vector <tuple <int, int, int>> Q(q);
    int mx = 0, mn = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], mx = max(mx, a[i]), mn = min(mn, a[i]), upd(1, n, i, 1), upd2(1, n, i, 1);
    for (auto &[x, y, z] : Q) {
        cin >> x;
        if (x == 1) cin >> y >> z, mx = max(mx, z), mn = min(mn, z);
        else cin >> y;
    }
    if (mx <= 1 && mn >= -1) {
        for (auto &[x, y, z] : Q) {
            int t;
            t = x;
            if (t == 1) {
                int i = y, x = z; a[i] = x;
                upd(1, n, i, 1), upd2(1, n, i, 1);
            } else {
                int k = y;
                if (seg2[1].M <= k && k <= seg[1].M) cout << "YES\n1 1\n";
                else cout << "NO\n";
            }
        }
    } else {
        for (auto &[x, y, z] : Q) {
            int t;
            t = x;
            if (t == 1) {
                int i = y, x = z; a[i] = x;
            } else {
                int k = y;
                unordered_map <int, int> vis;
                vis[0] = 1;
                int s = 0, ok = 0;
                for (int i = 1; i <= n; i++) {
                    s += a[i];
                    // cout << s << ' ' << vis[k-s] << '\n';
                    if (vis[k-s]) { ok = 1; cout << "YES\n"; cout << vis[k-s] << ' ' << i << '\n'; break; }
                    vis[-s] = i+1;
                }
                if (ok == 0) cout << "NO\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}